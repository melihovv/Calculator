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

namespace melihovv {
    namespace calculator {
        namespace Ast {

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
                UnaryOperation(const Node* child);
                virtual ~UnaryOperation() = 0;

                /*!
                 * Get child.
                 */
                const Node* child() const;

            private:
                const Node* _child;
            };
        }
    }
}

#endif // UNARYOPERATION_H
