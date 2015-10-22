/*!
 *\file deletingvisitor.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of deleting visitor class.
 */

#ifndef DELETINGVISITOR_H
#define DELETINGVISITOR_H

#include "visitor.h"
#include "number.h"
#include "negation.h"
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"
#include "power.h"

namespace melihovv {
    namespace calculator {
        namespace Ast {

            /*!
             * Deleting visitor class.
             */
            class DeletingVisitor : public Visitor
            {
            public:
                virtual void visit(const Number* number) override;
                virtual void visit(const Negation* negation) override;
                virtual void visit(const Addition* addition) override;
                virtual void visit(const Subtraction* subtraction) override;
                virtual void visit(const Multiplication* multiplication)
                    override;
                virtual void visit(const Division* division) override;
                virtual void visit(const Power* power) override;

            private:
                void visitBinaryOperation(const BinaryOperation* binOperation);
                void visitUnaryOperation(const UnaryOperation* unaryOperation);
                void visitNode(const Node* node);
            };
        }
    }
}

#endif // DELETINGVISITOR_H
