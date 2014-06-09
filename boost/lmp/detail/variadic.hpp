// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

// This header generates specializations of `subst' for variadic
// metafunctions such as `cond'. The specialization are needed to
// eliminate ambiquities.

#if !defined(F) || !defined(FROM) || !defined(TO)
#error "Either F, FROM, or TO was undefined."
#endif

#if FROM > TO
#error "FROM is greater than TO."
#endif

#if FROM <= 1 && 1 <= TO
template<class X0,
         class T, class V>
struct subst<F<X0>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr> expr;
};
#endif

#if FROM <= 2 && 2 <= TO
template<class X0, class X1,
         class T, class V>
struct subst<F<X0, X1>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr> expr;
};
#endif

#if FROM <= 3 && 3 <= TO
template<class X0, class X1, class X2,
         class T, class V>
struct subst<F<X0, X1, X2>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr> expr;
};
#endif

#if FROM <= 4 && 4 <= TO
template<class X0, class X1, class X2, class X3,
         class T, class V>
struct subst<F<X0, X1, X2, X3>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr> expr;
};
#endif

#if FROM <= 5 && 5 <= TO
template<class X0, class X1, class X2, class X3, class X4,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr> expr;
};
#endif

#if FROM <= 6 && 6 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr> expr;
};
#endif

#if FROM <= 7 && 7 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr> expr;
};
#endif

#if FROM <= 8 && 8 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr> expr;
};
#endif

#if FROM <= 9 && 9 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr> expr;
};
#endif

#if 10 <= TO && FROM <= 19
#include "boost/lmp/detail/variadic_10_19.hpp"
#endif

#undef F
#undef FROM
#undef TO
