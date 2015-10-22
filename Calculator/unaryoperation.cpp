#include "unaryoperation.h"

melihovv::calculator::Ast::UnaryOperation::UnaryOperation(
    const Node* child
    )
{
    _child = child;
}

melihovv::calculator::Ast::UnaryOperation::~UnaryOperation()
{
}

const melihovv::calculator::Ast::Node*
melihovv::calculator::Ast::UnaryOperation::child() const
{
    return _child;
}
