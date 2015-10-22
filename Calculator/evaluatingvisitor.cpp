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
    std::tuple<double, double> t = visitBinaryOperation(addition);
    result = std::get<0>(t) + std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Subtraction* subtraction
    )
{
    std::tuple<double, double> t = visitBinaryOperation(subtraction);
    result = std::get<0>(t) - std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Multiplication* multiplication
    )
{
    std::tuple<double, double> t = visitBinaryOperation(multiplication);
    result = std::get<0>(t) * std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Division* division
    )
{
    std::tuple<double, double> t = visitBinaryOperation(division);
    result = std::get<0>(t) / std::get<1>(t);
}

void melihovv::calculator::Ast::EvaluatingVisitor::visit(
    const Power* power
    )
{
    std::tuple<double, double> t = visitBinaryOperation(power);
    result = pow(std::get<0>(t), std::get<1>(t));
}

double melihovv::calculator::Ast::EvaluatingVisitor::getResult() const
{
    return result;
}

std::tuple<double, double>
melihovv::calculator::Ast::EvaluatingVisitor::visitBinaryOperation(
const BinaryOperation* binaryOperation
)
{
    binaryOperation->leftNode()->accept(*this);
    double left = result;
    binaryOperation->rightNode()->accept(*this);
    double right = result;
    return std::make_tuple(left, right);
}
