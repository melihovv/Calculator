#include "deletingvisitor.h"

void melihovv::calculator::Ast::DeletingVisitor::visit(const Number* number)
{
    visitNode(number);
}

void melihovv::calculator::Ast::DeletingVisitor::visit(const Negation* negation)
{
    visitUnaryOperation(negation);
}

void melihovv::calculator::Ast::DeletingVisitor::visit(const Addition* addition)
{
    visitBinaryOperation(addition);
}

void melihovv::calculator::Ast::DeletingVisitor::visit(
    const Subtraction* subtraction)
{
    visitBinaryOperation(subtraction);
}

void melihovv::calculator::Ast::DeletingVisitor::visit(
    const Multiplication* multiplication)
{
    visitBinaryOperation(multiplication);
}

void melihovv::calculator::Ast::DeletingVisitor::visit(const Division* division)
{
    visitBinaryOperation(division);
}

void melihovv::calculator::Ast::DeletingVisitor::visit(const Power* power)
{
    visitBinaryOperation(power);
}

void melihovv::calculator::Ast::DeletingVisitor::visitBinaryOperation(
    const BinaryOperation* binOperation)
{
    binOperation->left()->accept(*this);
    binOperation->right()->accept(*this);
    visitNode(binOperation);
}

void melihovv::calculator::Ast::DeletingVisitor::visitUnaryOperation(
    const UnaryOperation* unaryOperation)
{
    unaryOperation->child()->accept(*this);
    visitNode(unaryOperation);
}

void melihovv::calculator::Ast::DeletingVisitor::visitNode(const Node* node)
{
    delete node;
    node = nullptr;
}
