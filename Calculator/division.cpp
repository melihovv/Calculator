#include "division.h"

melihovv::calculator::Ast::Division::Division(
    const Node* left,
    const Node* right
    )
    : BinaryOperation(left, right)
{
}

void melihovv::calculator::Ast::Division::accept(Visitor& visitor) const
{
    visitor.visit(this);
}
