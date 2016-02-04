/*!
 *\file number.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of number node class.
 */

#ifndef NUMBER_H
#define NUMBER_H

#include "node.h"

namespace melihovv
{
    namespace calculator
    {
        namespace Ast
        {
            /*!
             * Number node class.
             */
            class Number : public Node
            {
            public:
                Number(int number)
                {
                    number_ = number;
                }

                void accept(Visitor& visitor) const override
                {
                    visitor.visit(this);
                }

                int number() const
                {
                    return number_;
                }

            private:
                int number_;
            };
        }
    }
}

#endif // NUMBER_H
