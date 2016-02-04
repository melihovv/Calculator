/*!
 *\file unaryoperation.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of unary operation node abstract class.
 */

#ifndef UNARYOPERATION_H
#define UNARYOPERATION_H

#include "node.h"

namespace melihovv
{
    namespace calculator
    {
        namespace Ast
        {
            /*!
             * Abstract unary operation class.
             */
            class UnaryOperation : public Node
            {
            public:
                /*!
                 * Construct binary operation.
                 *\param[in] child Child.
                 */
                explicit UnaryOperation(const Node* child)
                {
                    child_ = child;
                }

                virtual ~UnaryOperation()
                {
                }

                /*!
                 * Get child.
                 */
                const Node* child() const
                {
                    return child_;
                }

            private:
                const Node* child_;
            };
        }
    }
}

#endif // UNARYOPERATION_H
