/*!
 *\file binaryoperation.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of binary operation node abstract class.
 */

#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "node.h"

namespace melihovv
{
    namespace calculator
    {
        namespace Ast
        {
            /*!
             * Abstract binary operation class.
             */
            class BinaryOperation : public Node
            {
            public:
                /*!
                 * Construct binary operation.
                 *\param[in] left Left child.
                 *\param[in] right Right child.
                 */
                BinaryOperation(const Node* left, const Node* right)
                {
                    left_ = left;
                    right_ = right;
                }

                virtual ~BinaryOperation()
                {
                }

                /*!
                 * Get left child.
                 */
                const Node* left() const
                {
                    return left_;
                }

                /*!
                 * Get right child.
                 */
                const Node* right() const
                {
                    return right_;
                }

            private:
                const Node* left_;
                const Node* right_;
            };
        }
    }
}

#endif // BINARYOPERATION_H
