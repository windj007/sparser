#ifndef SPARSER_DETAIL_IDENTITY_HPP
#define SPARSER_DETAIL_IDENTITY_HPP

namespace sp
{
namespace detail
{

/**
 * Probably it's a reinvented wheel, but I could not recall where to find an existing one.
 * I guess it's somewhere in std::functional...
 */
struct identity
{
    template<typename T>
    const T & operator ()(const T &arg)
    {
        return arg;
    }
};



} // namespace detail
} // namespace sp

#endif // SPARSER_DETAIL_IDENTITY_HPP