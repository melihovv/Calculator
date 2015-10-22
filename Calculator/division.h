/*!
 *\file division.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of division node class.
 */

#ifndef DIVISION_H
#define DIVISION_H

#include "binaryoperation.h"

namespace melihovv {
    namespace calculator {
        namespace Ast {

            /*!
             * Division node class.
             */
            class Division : public BinaryOperation
            {
            public:
                Division(const Node* left, const Node* right);
                void accept(Visitor& visitor) const override;
            };
        }
    }
}

#endif // DIVISION_H
