#include "multiplication.h"

melihovv::calculator::Ast::Multiplication::Multiplication(
    const Node* left,
    const Node* right
    )
    : BinaryOperation(left, right)
{
}

void melihovv::calculator::Ast::Multiplication::accept(
    Visitor& visitor
    ) const
{
    visitor.visit(this);
}
