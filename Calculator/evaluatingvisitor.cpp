#include "evaluatingvisitor.h"

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Number* number)
{
    result_ = number->number();
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Negation* negation)
{
    negation->child()->accept(*this);
    result_ *= -1;
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Addition* addition)
{
    std::tuple<int, int> t = visitBinaryOperation(addition);
    result_ = std::get<0>(t) + std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Subtraction* subtraction)
{
    std::tuple<int, int> t = visitBinaryOperation(subtraction);
    result_ = std::get<0>(t) - std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Multiplication* multiplication)
{
    std::tuple<int, int> t = visitBinaryOperation(multiplication);
    result_ = std::get<0>(t) * std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Division* division)
{
    std::tuple<int, int> t = visitBinaryOperation(division);
    result_ = std::get<0>(t) / std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Power* power)
{
    std::tuple<int, int> t = visitBinaryOperation(power);
    result_ = pow(std::get<0>(t), std::get<1>(t));
}

int melihovv::calculator::Ast::EvaluatingVisitor::getResult() const
{
    return result_;
}

std::tuple<int, int>
melihovv::calculator::Ast::EvaluatingVisitor::visitBinaryOperation(
    const BinaryOperation* binaryOperation)
{
    binaryOperation->left()->accept(*this);
    int left = result_;
    binaryOperation->right()->accept(*this);
    int right = result_;
    return std::make_tuple(left, right);
}
