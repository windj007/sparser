#ifndef SPARSER_TREE_FUNCTORS_HPP
#define SPARSER_TREE_FUNCTORS_HPP

#include "tree_operations.hpp"

#include <boost/utility/result_of.hpp>

namespace sp
{


template<typename TKey>
class getter_t
{
public:
    getter_t(const TKey &key)
        : m_key(key)
    { }

    template<typename TPTree>
    decltype(get<TPTree, TKey>)
    operator() (const TPTree &tree) const
    {
        return get(tree, m_key);
    }
private:
    TKey        m_key;
};

template<typename TKey>
getter_t<TKey> make_getter(const TKey &key) { return getter_t<TKey>(key); }


template<typename TKey>
class key_checker_t
{
public:
    key_checker_t(const TKey &key)
        : m_key(key)
    { }

    template<typename TPTree>
    bool operator() (const TPTree &tree) const
    {
        return has_key(tree, m_key);
    }
private:
    TKey        m_key;
};

template<typename TKey>
key_checker_t<TKey> make_key_checker(const TKey &key) { return key_checker_t<TKey>(key); }


class length_getter_t
{
public:
    template<typename TPTree>
    decltype(length<TPTree>)
    operator() (const TPTree &tree) const
    {
        return length(tree);
    }
};

length_getter_t make_len_getter() { return length_getter_t(); }


class to_list_t
{
public:
    template<typename TPTree>
    decltype(to_list<TPTree>)
    operator() (const TPTree &tree) const
    {
        return to_list(tree);
    }
};

to_list_t make_to_list_conv() { return to_list_t(); }


class to_string_t
{
public:
    template<typename TPTree>
    std::string operator() (const TPTree &tree) const
    {
        return to_string(tree);
    }
};

to_string_t make_to_str_conv() { return to_string_t(); }

} // namespace sp

#endif // SPARSER_TREE_FUNCTORS_HPP