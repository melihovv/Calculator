#include "number.h"

melihovv::calculator::Ast::Number::Number(double number)
{
    this->number = number;
}

void melihovv::calculator::Ast::Number::accept(Visitor& visitor) const
{
    visitor.visit(this);
}

double melihovv::calculator::Ast::Number::getNumber() const
{
    return number;
}
