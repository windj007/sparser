#ifndef SPARSER_BOOST_PTREE_HPP
#define SPARSER_BOOST_PTREE_HPP

#include "elements.hpp"

#include <boost/property_tree/json_parser.hpp>

namespace boost
{
namespace property_tree
{

template<
    typename TValue = ptree
>
TValue get(const ptree &tree, const ptree::key_type &name)
{
    return tree.get<TValue>(name);
}

bool has_key(const ptree &tree, const ptree::key_type &name)
{
    return tree.find(name) != tree.not_found();
}


size_t length(const ptree &tree)
{
    return tree.size();
}

ptree to_list(const ptree &tree)
{
    return tree;
}

std::string to_string(const ptree &tree)
{
    std::stringstream ostr;
    boost::property_tree::json_parser::write_json(ostr, tree, true);
    return ostr.str();
}

} // namespace property_tree
} // namespace boost

#endif // SPARSER_BOOST_PTREE_HPP
