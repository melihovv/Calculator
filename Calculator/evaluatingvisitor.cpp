#include "evaluatingvisitor.h"

void melihovv::calculator::EvaluatingVisitor::visit(
    const Ast::Number* number)
{
    result_ = number->number();
}

void melihovv::calculator::EvaluatingVisitor::visit(
    const Ast::Negation* negation)
{
    negation->child()->accept(*this);
    result_ *= -1;
}

void melihovv::calculator::EvaluatingVisitor::visit(
    const Ast::Addition* addition)
{
    std::tuple<int, int> t = visitBinaryOperation(addition);
    result_ = std::get<0>(t) + std::get<1>(t);
}

void melihovv::calculator::EvaluatingVisitor::visit(
    const Ast::Subtraction* subtraction)
{
    std::tuple<int, int> t = visitBinaryOperation(subtraction);
    result_ = std::get<0>(t) - std::get<1>(t);
}

void melihovv::calculator::EvaluatingVisitor::visit(
    const Ast::Multiplication* multiplication)
{
    std::tuple<int, int> t = visitBinaryOperation(multiplication);
    result_ = std::get<0>(t) * std::get<1>(t);
}

void melihovv::calculator::EvaluatingVisitor::visit(
    const Ast::Division* division)
{
    std::tuple<int, int> t = visitBinaryOperation(division);
    result_ = std::get<0>(t) / std::get<1>(t);
}

void melihovv::calculator::EvaluatingVisitor::visit(
    const Ast::Power* power)
{
    std::tuple<int, int> t = visitBinaryOperation(power);
    result_ = pow(std::get<0>(t), std::get<1>(t));
}

int melihovv::calculator::EvaluatingVisitor::getResult() const
{
    return result_;
}

std::tuple<int, int>
melihovv::calculator::EvaluatingVisitor::visitBinaryOperation(
    const Ast::BinaryOperation* binaryOperation)
{
    binaryOperation->left()->accept(*this);
    int left = result_;
    binaryOperation->right()->accept(*this);
    int right = result_;
    return std::make_tuple(left, right);
}
