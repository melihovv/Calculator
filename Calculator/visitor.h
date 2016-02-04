/*!
 *\file visitor.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of visitor abstract class.
 */

#ifndef VISITOR_H
#define VISITOR_H

namespace melihovv
{
    namespace calculator
    {
        namespace Ast
        {
            class Node;
            class Number;
            class Negation;
            class Addition;
            class Subtraction;
            class Multiplication;
            class Division;
        }

        /*!
         * Visitor class.
         */
        class Visitor
        {
        public:
            virtual ~Visitor()
            {
            }

            /*!
             * Visit number node.
             *\param[in] number Number node.
             */
            virtual void visit(const Ast::Number* number) = 0;

            /*!
             * Visit negation node.
             *\param[in] negation Negation node.
             */
            virtual void visit(const Ast::Negation* negation) = 0;

            /*!
             * Visit addition node.
             *\param[in] addition Addition node.
             */
            virtual void visit(const Ast::Addition* addition) = 0;

            /*!
             * Visit subtraction node.
             *\param[in] subtraction Subtraction node.
             */
            virtual void visit(const Ast::Subtraction* subtraction) = 0;

            /*!
             * Visit multiplication node.
             *\param[in] multiplication Multiplication node.
             */
            virtual void visit(const Ast::Multiplication* multiplication) = 0;

            /*!
             * Visit division node.
             *\param[in] division Division node.
             */
            virtual void visit(const Ast::Division* division) = 0;
        };
    }
}

#endif // VISITOR_H
