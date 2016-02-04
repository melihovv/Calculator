#include "llvmevalvisitor.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/IRPrintingPasses.h"
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include "llvm/IR/Verifier.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include <vector>

melihovv::calculator::LlvmEvalVisitor::LlvmEvalVisitor()
    : builder_(llvm::IRBuilder<>(llvm::getGlobalContext()))
{
}

void melihovv::calculator::LlvmEvalVisitor::visit(const Ast::Number* number)
{
    value_ = llvm::ConstantInt::get(
        llvm::Type::getInt32Ty(llvm::getGlobalContext()),
        llvm::APInt(32, number->number(), true)
    );
}

void melihovv::calculator::LlvmEvalVisitor::visit(const Ast::Negation* negation)
{
    negation->child()->accept(*this);
    value_ = builder_.CreateNeg(value_);
}

void melihovv::calculator::LlvmEvalVisitor::visit(const Ast::Addition* addition)
{
    std::tuple<llvm::Value*, llvm::Value*> t = visitBinaryOperation(addition);
    value_ = builder_.CreateAdd(std::get<0>(t), std::get<1>(t));
}

void melihovv::calculator::LlvmEvalVisitor::visit(
    const Ast::Subtraction* subtraction)
{
    std::tuple<llvm::Value*, llvm::Value*> t = visitBinaryOperation(
        subtraction);
    value_ = builder_.CreateSub(std::get<0>(t), std::get<1>(t));
}

void melihovv::calculator::LlvmEvalVisitor::visit(
    const Ast::Multiplication* multiplication)
{
    std::tuple<llvm::Value*, llvm::Value*> t = visitBinaryOperation(
        multiplication);
    value_ = builder_.CreateMul(std::get<0>(t), std::get<1>(t));
}

void melihovv::calculator::LlvmEvalVisitor::visit(const Ast::Division* division)
{
    std::tuple<llvm::Value*, llvm::Value*> t = visitBinaryOperation(division);
    value_ = builder_.CreateSDiv(std::get<0>(t), std::get<1>(t));
}

void melihovv::calculator::LlvmEvalVisitor::generateCode(
    const melihovv::calculator::Node* node)
{
    std::vector<llvm::Type*> argTypes;
    llvm::FunctionType* ftype = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(llvm::getGlobalContext()),
        llvm::makeArrayRef(argTypes),
        false
    );

    module_= new llvm::Module("main", llvm::getGlobalContext());
    mainFunc_ = llvm::Function::Create(
        ftype,
        llvm::GlobalValue::InternalLinkage,
        "main",
        module_
    );
    llvm::BasicBlock* mainBlock = llvm::BasicBlock::Create(
        llvm::getGlobalContext(),
        "entry",
        mainFunc_,
        nullptr
    );

    node->accept(*this);
    llvm::ReturnInst::Create(llvm::getGlobalContext(), value_, mainBlock);
}

void melihovv::calculator::LlvmEvalVisitor::printCode()
{
    llvm::PassManager<llvm::Module> pm;
    pm.addPass(llvm::PrintModulePass(llvm::outs()));
    pm.run(*module_);
}

int melihovv::calculator::LlvmEvalVisitor::runCode()
{
    llvm::ExecutionEngine* ee = llvm::EngineBuilder(
        std::unique_ptr<llvm::Module>(module_)
    ).create();

    ee->finalizeObject();
    std::vector<llvm::GenericValue> noargs;
    llvm::GenericValue result = ee->runFunction(mainFunc_, noargs);
    return *result.IntVal.getRawData();
}

std::tuple<llvm::Value*, llvm::Value*>
melihovv::calculator::LlvmEvalVisitor::visitBinaryOperation(
    const Ast::BinaryOperation* binaryOperation)
{
    binaryOperation->left()->accept(*this);
    llvm::Value* left = value_;
    binaryOperation->right()->accept(*this);
    llvm::Value* right = value_;
    return std::make_tuple(left, right);
}
