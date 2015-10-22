/*!
 *\file parser.yy
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of syntax analyzer.
 */

/*! Require bison >=3.0.4. */
%require "3.0.4"

/*! Use c++ skeleton file. */
%skeleton "lalr1.cc"

/*! Generate header file. */
%defines

/*! For parser trace. Disable this for release version. */
%debug

/*! Verbose error messages. */
%error-verbose

/*! Enable location tracking. */
%locations
%initial-action
{
    @$.begin.filename = @$.end.filename = &driver.fileName;
};

%define api.namespace {melihovv::calculator}
%define parser_class_name {Parser}
%parse-param {melihovv::calculator::Lexer& lexer}
%parse-param {melihovv::calculator::Driver& driver}
%lex-param {melihovv::calculator::Driver& driver}

%code requires {
    #include <string>
    #include <list>
    #include "driver.h"
    #include "error.h"
    #include "node.h"
    #include "number.h"
    #include "addition.h"
    #include "subtraction.h"
    #include "negation.h"
    #include "multiplication.h"
    #include "division.h"
    #include "power.h"

    namespace melihovv {
        namespace calculator {
            class Lexer;
            class Error;
            class Driver;

            namespace Ast {
                class Number;
                class Negation;
                class Addition;
                class Subtraction;
                class Multiplication;
                class Division;
                class Power;
            }
        }
    }
}

%code {
    #include "lexer.h"

    #define yylex(x) lexer.mylex(x)

    void melihovv::calculator::Parser::error(
            const location_type& location,
            const std::string& message
        )
    {
        driver.addError(location, message);
    }
}

/*! Generate constructor functions for tokens. */
%define api.token.constructor

/*! Use variants instead of union. */
%define api.value.type variant

/*! Issue runtime assertions to catch invalid uses. */
//%define parse.assert

%token
    END 0 "end of file"
    PLUS "+"
    MINUS "-"
    MULTIPLICATION "*"
    DIVISION "/"
    POWER "^"
    LEFT_PAREN "("
    RIGHT_PAREN ")"
;

%left "+" "-"
%left "*" "/"
%precedence NEG
%right "^"

%token <double> NUMBER;
%type <Ast::Node*> Exp;

%start Input

%%
Input
    : Exp {driver.root = $1;}
    ;

Exp
    : NUMBER {$$ = new Ast::Number($1);}
    | Exp "+" Exp {$$ = new Ast::Addition($1, $3);}
    | Exp "-" Exp {$$ = new Ast::Subtraction($1, $3);}
    | Exp "*" Exp {$$ = new Ast::Multiplication($1, $3);}
    | Exp "/" Exp {$$ = new Ast::Division($1, $3);}
    | "-" Exp %prec NEG {$$ = new Ast::Negation($2);}
    | Exp "^" Exp {$$ = new Ast::Power($1, $3);}
    | "(" Exp ")" {$$ = $2;}
    ;
%%
