#include "subtraction.h"

melihovv::calculator::Ast::Subtraction::Subtraction(
    const Node* left,
    const Node* right
    )
    : BinaryOperation(left, right)
{
}

void melihovv::calculator::Ast::Subtraction::accept(
    Visitor& visitor
    ) const
{
    visitor.visit(this);
}
