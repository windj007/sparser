#ifndef SPARSER_ONE_OF_HPP
#define SPARSER_ONE_OF_HPP

#include "detail/caller.hpp"
#include "detail/logic.hpp"
#include "detail/identity.hpp"

#include "tree_operations.hpp"
#include "errors.hpp"

#include <boost/bind.hpp>
#include <boost/fusion/container/list.hpp>
#include <boost/fusion/algorithm.hpp>
#include <boost/fusion/functional.hpp>

namespace sp
{

template<typename ... TCases>
class one_of_impl
{
public:
    one_of_impl(const TCases & ...cases)
        : m_impl(cases...)
    { }

    template<typename TPTree>
    bool operator () (const TPTree &tree) const
    {
        return boost::fusion::any(
              m_impl
            , detail::make_caller_bool(tree)
        );
    }

private:
    typedef boost::fusion::list<TCases ...>     impl_type;
    impl_type                                   m_impl;
};

template<typename... TCases>
one_of_impl<TCases ...>
one_of(const TCases & ...name)
{
    return one_of_impl<TCases...>(name...);
}

} // namespace sp

#endif // SPARSER_ONE_OF_HPP