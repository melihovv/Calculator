/*!
 *\file addition.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of addition node class.
 */

#ifndef ADDITION_H
#define ADDITION_H

#include "binaryoperation.h"

namespace melihovv
{
    namespace calculator
    {
        namespace Ast
        {
            /*!
             * Addition node class.
             */
            class Addition : public BinaryOperation
            {
            public:
                Addition(const Node* left, const Node* right)
                    : BinaryOperation(left, right)
                {
                }

                void accept(Visitor& visitor) const override
                {
                    visitor.visit(this);
                }
            };
        }
    }
}

#endif // ADDITION_H
