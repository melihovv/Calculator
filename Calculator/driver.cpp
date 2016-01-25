#include "driver.h"
#include "lexer.h"

melihovv::calculator::Driver::Driver(std::istream* is /*= 0*/)
{
    lexer = std::unique_ptr<Lexer>(new Lexer(is));
    parser = std::unique_ptr<Parser>(new Parser(*lexer.get(), *this));
}

melihovv::calculator::Driver::~Driver()
{
    if (root != nullptr)
    {
        root->accept(delVisitor);
    }
}

double melihovv::calculator::Driver::parse()
{
    errors.clear();
    parser->parse();

    if (errors.size() != 0)
    {
        for (auto error : errors)
        {
            std::cout << error.error() << std::endl;
        }
        return 0;
    }

    root->accept(evalVisitor);
    return evalVisitor.getResult();
}

void melihovv::calculator::Driver::switchInputStream(std::istream* is)
{
    lexer->switch_streams(is);
}

void melihovv::calculator::Driver::setFileName(const std::string& fileName)
{
    this->fileName = fileName;
}

std::list<melihovv::calculator::Error> melihovv::calculator::Driver::getErrors() const
{
    return errors;
}

void melihovv::calculator::Driver::addError(
    const location& location,
    const std::string& message
    )
{
    errors.push_back(Error(location, message));
}
