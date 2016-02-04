/*!
 *\file lexer.ll
 *\author Alexander Melihov <amelihovv@ya.ru>
 *\version 0.0.1
 *
 *\license This code is distributed under the very permissive MIT License but,
 * if you use it, you might consider referring to the repository.
 *
 * The file contains declaration of lexical analyzer.
 */

/*! Scan only one file. */
%option noyywrap

/*! Don't optimize lexer for console input */
%option never-interactive

/*!
 * Causes the default rule (that unmatched scanner input is echoed to stdout)
 * to be suppressed.
 */
%option nodefault

/*! Generate c++ class. */
%option c++
/*! Class name. */
%option yyclass="Lexer"

/* Generate debug output. Disable this for release version. */
%option debug

%{
    #include "lexer.h"

    /*!
     * Each time yylex is invoked, the begin position is moved onto the end 
     * position.
     */
    #define YY_USER_ACTION loc.columns(yyleng);

    /*!
     * In our case yyterminate() must return Parser::symbol_type instead of
     * 0.
     */
    #define yyterminate() {return calculator::Parser::make_END(loc);}

    /*! Don't include unistd.h, which is not availible under MSVC++. */
    #define YY_NO_UNISTD_H
%}

int [0-9]+
blank [ \t\r]

%%

%{
    /*! Tokens' location. */
    static melihovv::calculator::Parser::location_type loc(&driver.fileName_);
    loc.step();
%}

"-" {return calculator::Parser::make_MINUS(loc);}
"+" {return calculator::Parser::make_PLUS(loc);}
"*" {return calculator::Parser::make_MULTIPLICATION(loc);}
"/" {return calculator::Parser::make_DIVISION(loc);}
"(" {return calculator::Parser::make_LEFT_PAREN(loc);}
")" {return calculator::Parser::make_RIGHT_PAREN(loc);}

{int} {return calculator::Parser::make_NUMBER(atol(yytext), loc);}
{blank}+ {loc.step();}

\n {
    loc.lines(yyleng);
    loc.step();
}

. {
    driver.addError(loc, std::string("Strange symbol: ") + yytext);
}

<<EOF>> {
    loc.initialize(&driver.fileName_);
    return calculator::Parser::make_END(loc);
}

%%
