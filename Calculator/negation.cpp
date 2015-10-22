#include "negation.h"

melihovv::calculator::Ast::Negation::Negation(const Node* child)
    : UnaryOperation(child)
{
}

void melihovv::calculator::Ast::Negation::accept(
    Visitor& visitor
    ) const
{
    visitor.visit(this);
}
