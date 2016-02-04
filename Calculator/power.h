/*!
 *\file power.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of power node class.
 */

#ifndef POWER_H
#define POWER_H

#include "binaryoperation.h"

namespace melihovv
{
    namespace calculator
    {
        namespace Ast
        {
            /*!
             * Power node class.
             */
            class Power : public BinaryOperation
            {
            public:
                Power(const Node* left, const Node* right)
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

#endif // POWER_H
