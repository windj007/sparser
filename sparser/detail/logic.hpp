#ifndef SPARSER_DETAIL_LOGIC_HPP
#define SPARSER_DETAIL_LOGIC_HPP

namespace sp
{
namespace detail
{

/**
 * @author rsuvorov
 *
 * Probably it's a reinvented wheel, but I could not recall where to find an existing one.
 * I guess it's somewhere in std::functional...
 */
template<
      typename TA
    , typename TB
>
struct and_op_t
{
    bool operator ()(const TA &a, const TB &b) const
    {
        return a && b;
    }
};

template<typename TA, typename TB>
and_op_t<TA, TB> and_op() { return and_op_t<TA, TB>(); }

template<
      typename TA
    , typename TB
>
struct or_op_t
{
    bool operator ()(const TA &a, const TB &b) const
    {
        return a || b;
    }
};

template<typename TA, typename TB>
or_op_t<TA, TB> or_op() { return or_op_t<TA, TB>(); }

} // namespace detail
} // namespace sp

#endif // SPARSER_DETAIL_LOGIC_HPP