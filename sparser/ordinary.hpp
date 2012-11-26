#ifndef SPARSER_ORDINARY_HPP
#define SPARSER_ORDINARY_HPP

#include "tree_operations.hpp"

namespace sp
{

template<
      typename TKey
    , typename TFunc
>
class ordinary_impl
{
public:
    ordinary_impl(const TKey &key, const TFunc &func)
        : m_key(key)
        , m_func(func)
    { }

    template<typename TPTree>
    bool operator () (const TPTree &tree) const
    {
        if (has_key(tree, m_key))
            return m_func(get(tree, m_key));
        return false;
    }

private:
    TKey        m_key;
    TFunc       m_func;
};

template<
      typename TKey
    , typename TFunc
>
ordinary_impl<TKey, TFunc> ordinary(const TKey &key, const TFunc &f)
{
    return ordinary_impl<TKey, TFunc>(key, f);
}

} // namespace sp

#endif // SPARSER_ORDINARY_HPP