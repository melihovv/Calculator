/*!
 *\file multiplication.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of multiplication node class.
 */

#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "binaryoperation.h"

namespace melihovv {
    namespace calculator {
        namespace Ast {

            /*!
             * Multiplication node class.
             */
            class Multiplication : public BinaryOperation
            {
            public:
                Multiplication(const Node* left, const Node* right);
                void accept(Visitor& visitor) const override;
            };
        }
    }
}

#endif // MULTIPLICATION_H
