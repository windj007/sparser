#ifndef SPARSER_DETAIL_CALLER_HPP
#define SPARSER_DETAIL_CALLER_HPP

#include <boost/preprocessor.hpp>

namespace sp
{
namespace detail
{

#define SP_DETAIL_CALLER_MAX_ARGS 20


#define SP_DETAIL_MEMBER(q1, i, q2) TArg ## i m_arg ## i;
#define SP_DETAIL_ARG(q1, i, q2) BOOST_PP_COMMA_IF(i) const TArg ## i &arg ## i
#define SP_DETAIL_INITIALIZER(q1, i, q2) BOOST_PP_COMMA_IF(i) m_arg ## i ( arg ## i )

#define SP_DETAIL_DEFINE_CALLER_BASE(type, params_count, return_type, return_stmt) \
    template<BOOST_PP_ENUM_PARAMS(params_count, typename TArg)> \
    struct caller_ ## type ## _ ## params_count ## _t \
    { \
        caller_ ## type ## _ ## params_count ## _t(BOOST_PP_REPEAT(params_count, SP_DETAIL_ARG, )) \
            : BOOST_PP_REPEAT(params_count, SP_DETAIL_INITIALIZER, ) \
        { } \
        template<typename TFunc> \
        return_type operator() (const TFunc &func) const \
        { \
            return_stmt func(BOOST_PP_ENUM_PARAMS(params_count, m_arg)); \
        } \
    private: \
        BOOST_PP_REPEAT(params_count, SP_DETAIL_MEMBER,) \
    }; \
    template<BOOST_PP_ENUM_PARAMS(params_count, typename TArg)> \
    caller_ ## type ## _ ## params_count ## _t <BOOST_PP_ENUM_PARAMS(params_count, TArg)> \
    make_caller_ ## type (BOOST_PP_REPEAT(params_count, SP_DETAIL_ARG, )) \
    { return caller_ ## type ## _ ## params_count ## _t \
        <BOOST_PP_ENUM_PARAMS(params_count, TArg)> \
        ( BOOST_PP_ENUM_PARAMS(params_count, arg) ); \
    }

#define SP_DETAIL_DEFINE_CALLER_VOID(a, params_count, b) \
    SP_DETAIL_DEFINE_CALLER_BASE(void, params_count, void,)

#define SP_DETAIL_DEFINE_CALLER_BOOL(a, params_count, b) \
    SP_DETAIL_DEFINE_CALLER_BASE(bool, params_count, bool, return)

BOOST_PP_REPEAT_FROM_TO(1, SP_DETAIL_CALLER_MAX_ARGS, SP_DETAIL_DEFINE_CALLER_VOID,)
BOOST_PP_REPEAT_FROM_TO(1, SP_DETAIL_CALLER_MAX_ARGS, SP_DETAIL_DEFINE_CALLER_BOOL,)

} // namespace detail
} // namespace sp

#endif // SPARSER_DETAIL_CALLER_HPP
