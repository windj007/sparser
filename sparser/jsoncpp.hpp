#ifndef SPARSER_JSONCPP_HPP
#define SPARSER_JSONCPP_HPP

#include <jsoncpp/json/value.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/reader.h>

namespace Json
{

template<
    typename TValue = Value
>
TValue get(const Value &tree, const std::string &name)
{
    return tree.get(name, Value());
}

bool has_key(const Value &tree, const std::string &name)
{
    return !tree.get(name, Value()).empty();
}


size_t length(const Value &tree)
{
    return tree.size();
}

Value to_list(const Value &tree)
{
    return tree;
}

std::string to_string(const Value &tree)
{
    return tree.toStyledString();
}

} // namespace Json

namespace sp
{

bool parse_jsoncpp(const std::string &content, Json::Value &result)
{
    Json::Reader reader;
    return reader.parse(content, result);
}

} // namespace sp

#endif // SPARSER_JSONCPP_HPP