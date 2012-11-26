#ifndef SPARSER_TREE_OPERATIONS_HPP
#define SPARSER_TREE_OPERATIONS_HPP

#include <string>

namespace sp
{

template<
      typename TTree
    , typename TKeyName
    , typename TValue = std::string
>
TValue get(const TTree &tree, const TKeyName &name);

template<
      typename TTree
    , typename TKeyName
>
bool has_key(const TTree &tree, const TKeyName &name);

template<
      typename TTree
>
size_t length(const TTree &tree);

template<
      typename TTree
>
void to_list(const TTree &tree);

template<
      typename TTree
>
std::string to_string(const TTree &tree);

} // namespace sp

#endif // SPARSER_TREE_OPERATIONS_HPP
