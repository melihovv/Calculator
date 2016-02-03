#include "evaluatingvisitor.h"

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Number* number
    )
{
    result = number->getNumber();
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Negation* negation
    )
{
    negation->child()->accept(*this);
    result *= -1;
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Addition* addition
    )
{
    std::tuple<int, int> t = visitBinaryOperation(addition);
    result = std::get<0>(t) + std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Subtraction* subtraction
    )
{
    std::tuple<int, int> t = visitBinaryOperation(subtraction);
    result = std::get<0>(t) - std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Multiplication* multiplication
    )
{
    std::tuple<int, int> t = visitBinaryOperation(multiplication);
    result = std::get<0>(t) * std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Division* division
    )
{
    std::tuple<int, int> t = visitBinaryOperation(division);
    result = std::get<0>(t) / std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Power* power
    )
{
    std::tuple<int, int> t = visitBinaryOperation(power);
    result = pow(std::get<0>(t), std::get<1>(t));
}

double melihovv::calculator::Ast::EvaluatingVisitor::getResult() const
{
    return result;
}

std::tuple<int, int>
melihovv::calculator::Ast::EvaluatingVisitor::visitBinaryOperation(
const BinaryOperation* binaryOperation
)
{
    binaryOperation->leftNode()->accept(*this);
    int left = result;
    binaryOperation->rightNode()->accept(*this);
    int right = result;
    return std::make_tuple(left, right);
}
