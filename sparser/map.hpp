#ifndef SPARSER_ORDERED_MAP_HPP
#define SPARSER_ORDERED_MAP_HPP

#include "tree_operations.hpp"
#include "detail/caller.hpp"

#include <boost/fusion/container/list.hpp>
#include <boost/fusion/algorithm/query/all.hpp>

namespace sp
{

template<
      typename ...TCases
>
class map_impl
{
public:
    map_impl(const TCases & ...cases)
        : m_cases(cases...)
    { }

    template<typename TPTree>
    bool operator () (const TPTree &tree) const
    {
        return boost::fusion::all(
              m_cases
            , detail::make_caller_bool(tree)
        );
    }

private:
    typedef boost::fusion::list<TCases ...>     cases_type;
    cases_type                                  m_cases;
};

template<
      typename ...TCases
>
map_impl<TCases ...> map(const TCases & ...cases)
{
    return map_impl<TCases ...>(cases...);
}

} // namespace sp

#endif // SPARSER_ORDERED_MAP_HPP