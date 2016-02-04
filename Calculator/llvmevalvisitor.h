/*!
 *\file llvmevalvisitor.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of llvm evaluating visitor class.
 */

#ifndef LLVMEVALVISITOR_H
#define LLVMEVALVISITOR_H

#include <tuple>
#include <llvm/IR/Value.h>
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "visitor.h"
#include "binaryoperation.h"
#include "number.h"
#include "negation.h"
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"

namespace melihovv
{
    namespace calculator
    {
        using namespace melihovv::calculator::Ast;

        /*!
         * Llvm evaluating visitor class.
         */
        class LlvmEvalVisitor : public Visitor
        {
        public:
            LlvmEvalVisitor();

            virtual void visit(const Number* number) override;
            virtual void visit(const Negation* negation) override;
            virtual void visit(const Addition* addition) override;
            virtual void visit(const Subtraction* subtraction) override;
            virtual void visit(const Multiplication* multiplication)
            override;
            virtual void visit(const Division* division) override;

            virtual void generateCode(const Node* node);
            virtual void printCode();
            virtual int runCode();

        private:
            std::tuple<llvm::Value*, llvm::Value*> visitBinaryOperation(
                const BinaryOperation* binaryOperation);

            llvm::Value* value_ = nullptr;
            llvm::Module* module_ = nullptr;
            llvm::Function* mainFunc_ = nullptr;
            llvm::IRBuilder<> builder_;
        };
    }
}

#endif // LLVMEVALVISITOR_H
