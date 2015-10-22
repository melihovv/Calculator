#include "power.h"

melihovv::calculator::Ast::Power::Power(
    const Node* left,
    const Node* right
    )
    : BinaryOperation(left, right)
{
}

void melihovv::calculator::Ast::Power::accept(Visitor& visitor) const
{
    visitor.visit(this);
}
