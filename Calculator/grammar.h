#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <iostream>
#include <cmath>

namespace Calc {
    namespace qi = boost::spirit::qi;
    namespace phx = boost::phoenix;

    namespace {
        int pow_func(int a, int b)
        {
            return std::pow(a, b);
        }
    }
    BOOST_PHOENIX_ADAPT_FUNCTION(int, pow, pow_func, 2)

    template <typename Iterator>
    struct Grammar : qi::grammar<Iterator, int(), qi::space_type>
    {
        Grammar() : Grammar::base_type(expr, "expression")
        {
            expr
                = term              [qi::_val = qi::_1]
                >> *( '+' > term    [qi::_val += qi::_1]
                    | '-' > term    [qi::_val -= qi::_1]
                    );

            term
                = expo              [qi::_val = qi::_1]
                >> *( '*' > expo    [qi::_val *= qi::_1]
                    | '/' > expo    [qi::_val /= qi::_1]
                    );

            expo
                = factor            [qi::_val = qi::_1]
                >> *('^' >> expo    [qi::_val = pow(qi::_val, qi::_1)])
                ;

            factor
                = qi::int_          [qi::_val = qi::_1]
                | '(' > expr        [qi::_val = qi::_1] > ')'
                | '-' > factor      [qi::_val = -qi::_1]
                ;

            expr.name("expression");
            term.name("term");
            factor.name("factor");

            qi::on_error<qi::fail>(
                expr,
                std::cout
                    << phx::val("Error. Expected ") << qi::_4
                    << " at " << phx::construct<std::string>(qi::_3, qi::_2)
                    << std::endl
            );
        }

        qi::rule<Iterator, int(), qi::space_type> expr;
        qi::rule<Iterator, int(), qi::space_type> term;
        qi::rule<Iterator, int(), qi::space_type> factor;
        qi::rule<Iterator, int(), qi::space_type> expo;
    };
}

#endif // GRAMMAR_H
