#include "deletingvisitor.h"

void melihovv::calculator::DeletingVisitor::visit(const Ast::Number* number)
{
    visitNode(number);
}

void melihovv::calculator::DeletingVisitor::visit(const Ast::Negation* negation)
{
    visitUnaryOperation(negation);
}

void melihovv::calculator::DeletingVisitor::visit(const Ast::Addition* addition)
{
    visitBinaryOperation(addition);
}

void melihovv::calculator::DeletingVisitor::visit(
    const Ast::Subtraction* subtraction)
{
    visitBinaryOperation(subtraction);
}

void melihovv::calculator::DeletingVisitor::visit(
    const Ast::Multiplication* multiplication)
{
    visitBinaryOperation(multiplication);
}

void melihovv::calculator::DeletingVisitor::visit(const Ast::Division* division)
{
    visitBinaryOperation(division);
}

void melihovv::calculator::DeletingVisitor::visit(const Ast::Power* power)
{
    visitBinaryOperation(power);
}

void melihovv::calculator::DeletingVisitor::visitBinaryOperation(
    const Ast::BinaryOperation* binOperation)
{
    binOperation->left()->accept(*this);
    binOperation->right()->accept(*this);
    visitNode(binOperation);
}

void melihovv::calculator::DeletingVisitor::visitUnaryOperation(
    const Ast::UnaryOperation* unaryOperation)
{
    unaryOperation->child()->accept(*this);
    visitNode(unaryOperation);
}

void melihovv::calculator::DeletingVisitor::visitNode(const Ast::Node* node)
{
    delete node;
    node = nullptr;
}
