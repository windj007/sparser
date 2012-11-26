#ifndef SPARSER_MATCH_HPP
#define SPARSER_MATCH_HPP

#include "tree_operations.hpp"

namespace sp
{

template<
      typename TKeyName
    , typename TKeyValue
    , typename TAction
>
class match_impl
{
public:
    
    typedef TKeyName    kname_type;
    typedef TKeyValue   kvalue_type;
    typedef TAction     action_type;

    match_impl(
          const kname_type &key_name
        , const kvalue_type &key_value
        , const action_type &action )
        : m_key_name(key_name)
        , m_key_value(key_value)
        , m_action(action)
    { }
    
    template<typename TPTree>
    bool operator () (const TPTree &tree) const
    {
        kvalue_type real_val = get(tree, m_key_name);
        if (real_val == m_key_value)
        {
            m_action(tree);
            return true;
        }
        return false;
    }
    
private:
    kname_type  m_key_name;
    kvalue_type m_key_value;
    action_type m_action;
};

template<
      typename TKeyName
    , typename TKeyValue
    , typename TAction
>
match_impl<TKeyName, TKeyValue, TAction>
match(const TKeyName &name, const TKeyValue &value, const TAction &action)
{
    return match_impl<TKeyName, TKeyValue, TAction>(name, value, action);
}

} // namespace sp
#endif // SPARSER_MATCH_HPP