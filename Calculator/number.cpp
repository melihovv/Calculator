#include "number.h"

melihovv::calculator::Ast::Number::Number(int number)
{
    this->number = number;
}

void melihovv::calculator::Ast::Number::accept(Visitor& visitor) const
{
    visitor.visit(this);
}

int melihovv::calculator::Ast::Number::getNumber() const
{
    return number;
}
