/*!
 *\file subtraction.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of subtraction node class.
 */

#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "binaryoperation.h"

namespace melihovv {
    namespace calculator {
        namespace Ast {

            /*!
             * Subtraction node class.
             */
            class Subtraction : public BinaryOperation
            {
            public:
                Subtraction(const Node* left, const Node* right);
                void accept(Visitor& visitor) const override;
            };
        }
    }
}

#endif // SUBTRACTION_H
