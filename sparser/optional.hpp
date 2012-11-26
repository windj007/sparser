#ifndef SPARSER_OPTIONAL_HPP
#define SPARSER_OPTIONAL_HPP

#include "tree_operations.hpp"

namespace sp
{

template<
      typename TKey
    , typename TFunc
>
class optional_impl
{
public:
    optional_impl(const TKey &key, const TFunc &func)
        : m_key(key)
        , m_func(func)
    { }

    template<typename TPTree>
    bool operator () (const TPTree &tree) const
    {
        if (has_key(tree, m_key))
            return m_func(get(tree, m_key));
        return true;
    }

private:
    TKey        m_key;
    TFunc       m_func;
};

template<
      typename TKey
    , typename TFunc
>
optional_impl<TKey, TFunc> optional(const TKey &key, const TFunc &f)
{
    return optional_impl<TKey, TFunc>(key, f);
}

} // namespace sp

#endif // SPARSER_OPTIONAL_HPP
