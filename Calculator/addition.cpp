#include "addition.h"

melihovv::calculator::Ast::Addition::Addition(
    const Node* left,
    const Node* right
    )
    : BinaryOperation(left, right)
{
}

void melihovv::calculator::Ast::Addition::accept(Visitor& visitor) const
{
    visitor.visit(this);
}
