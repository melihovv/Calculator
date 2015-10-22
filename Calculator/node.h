/*!
 *\file node.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of node abstract class.
 */

#ifndef NODE_H
#define NODE_H

#include "visitor.h"

namespace melihovv {
    namespace calculator {
        namespace Ast {

            /*!
             * Node class.
             */
            class Node
            {
            public:
                virtual ~Node() = 0;

                /*!
                 * Accept visitor.
                 *\param[in] visitor Visitor.
                 */
                virtual void accept(Visitor& visitor) const = 0;
            };
        }
    }
}

#endif // NODE_H
