#include "binaryoperation.h"

melihovv::calculator::Ast::BinaryOperation::BinaryOperation(
    const Node* left,
    const Node* right
    )
{
    this->left = left;
    this->right = right;
}

melihovv::calculator::Ast::BinaryOperation::~BinaryOperation()
{
}

const melihovv::calculator::Ast::Node*
melihovv::calculator::Ast::BinaryOperation::leftNode() const
{
    return left;
}

const melihovv::calculator::Ast::Node*
melihovv::calculator::Ast::BinaryOperation::rightNode() const
{
    return right;
}
