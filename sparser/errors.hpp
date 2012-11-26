#ifndef SPARSER_ERRORS_HPP
#define SPARSER_ERRORS_HPP

#include <stdexcept>

namespace sp
{

struct parse_error : std::runtime_error
{
    parse_error(const std::string &str)
        : std::runtime_error(str)
    { }
};

} // namespace sp

#endif // SPARSER_ERRORS_HPP