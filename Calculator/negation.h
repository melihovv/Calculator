/*!
 *\file negation.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of negation node class.
 */

#ifndef NEGATION_H
#define NEGATION_H

#include "unaryoperation.h"

namespace melihovv
{
    namespace calculator
    {
        namespace Ast
        {
            /*!
             * Negation node class.
             */
            class Negation : public UnaryOperation
            {
            public:
                Negation(const Node* child)
                    : UnaryOperation(child)
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

#endif // NEGATION_H
