#include "driver.h"
#include "lexer.h"

melihovv::calculator::Driver::Driver(std::istream* is /*= nullptr*/)
{
    lexer_ = std::make_unique<Lexer>(is);
    parser_ = std::make_unique<Parser>(*lexer_.get(), *this);
}

melihovv::calculator::Driver::~Driver()
{
    if (root_ != nullptr)
    {
        root_->accept(delVisitor_);
    }
}

int melihovv::calculator::Driver::parse()
{
    errors_.clear();
    parser_->parse();

    if (errors_.size() != 0)
    {
        for (auto error : errors_)
        {
            std::cout << error.error() << std::endl;
        }
        return 0;
    }

    root_->accept(evalVisitor_);
    return evalVisitor_.getResult();
}

void melihovv::calculator::Driver::switchInputStream(std::istream* is) const
{
    lexer_->switch_streams(is);
}

void melihovv::calculator::Driver::setFileName(const std::string& fileName)
{
    fileName_ = fileName;
}

std::list<melihovv::calculator::Error>
melihovv::calculator::Driver::errors() const
{
    return errors_;
}

void melihovv::calculator::Driver::addError(
    const location& location,
    const std::string& message)
{
    errors_.push_back(Error(location, message));
}
