/*!
 *\file driver.h
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of calculator class.
 */

#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include <list>
#include <memory>
#include "node.h"
#include "error.h"
#include "location.hh"
#include "parser.tab.hh"
#include "evaluatingvisitor.h"
#include "deletingvisitor.h"

namespace melihovv
{
    namespace calculator
    {
        /*!
         * Driver class.
         */
        class Driver
        {
        public:
            Driver(std::istream* is = nullptr);
            ~Driver();

            /*!
             * Parse input and return result.
             *\return Result of arithmetic expression.
             */
            int parse();

            /*!
             * Switch lexer input stream. Default is standard input
             * (std::cin).
             *\param[in] is Input stream.
             */
            void switchInputStream(std::istream* is) const;

            /*!
             * Set name of parsing file.
             *\param[in] fileName Name of parsing file.
             */
            void setFileName(const std::string& fileName);

            /*
             * Return all errors.
             */
            std::list<Error> errors() const;

            friend class Parser;
            friend class Lexer;

        private:
            /*!
             * Add error in list of errors.
             *\param[in] location Location of error.
             *\param[in] message Error message.
             */
            void addError(
                const location& location,
                const std::string& message
            );

            std::string fileName_ = "";
            std::list<Error> errors_;
            const Node* root_ = nullptr;
            EvaluatingVisitor evalVisitor_;
            DeletingVisitor delVisitor_;
            std::unique_ptr<Lexer> lexer_;
            std::unique_ptr<Parser> parser_;
        };
    }
}

#endif // DRIVER_H
