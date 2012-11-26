#ifndef SPARSER_LIST_HPP
#define SPARSER_LIST_HPP

#include "tree_operations.hpp"

namespace sp
{

template<
    typename TFunc
>
class list_impl
{
public:
    list_impl(const TFunc &func)
        : m_func(func)
    { }

    template<typename TPTree>
    bool operator() (const TPTree &tree) const
    {
        for (const auto &elem : to_list(tree))
            m_func(elem);
        return true;
    }
private:
    TFunc m_func;
};

template<typename TFunc>
list_impl<TFunc> list(const TFunc &f)
{
    return list_impl<TFunc>(f);
}

} // namespace sp

#endif // SPARSER_LIST_HPP