#include "stdafx.h"
#include "grammar.h"

int main(int argc, char* argv[])
{
    namespace qi = boost::spirit::qi;
    Calc::Grammar<std::string::iterator> grammar;

    while (true)
    {
        std::string expr;
        std::getline(std::cin, expr);

        std::string::iterator begin = expr.begin();
        std::string::iterator end = expr.end();

        int result;
        bool r = phrase_parse(begin, end, grammar, qi::space, result);

        if (r && begin == end)
        {
            std::cout << result << std::endl;
        }
        else
        {
            std::cout
                << "Parsing failed" << std::endl
                << "stopped at: " + std::string(begin, end) << std::endl;
        }
    }

    return 0;
}

