#ifndef BOOST_LMP_FN_HPP_VK_20043010
#define BOOST_LMP_FN_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  /**
   * `nf<expr>' can sometimes be used for (unsafe) optimization of lambda
   * expressions. When `nf<expr>' appears inside a lambda abstraction it
   * stops the substitution mechanism from entering `expr'. `nf<expr>'
   * evaluates to whatever `expr' evaluates to. Beware that you can easily
   * write incorrect code with `nf<expr>'. However, if a lambda expression
   * manipulates large data structures, the speedup obtained from cutting
   * redundant substitution can be significant.
   */
  template<class E>
  struct nf {
    typedef typename E::eval eval;
  };

  /*
   * `subst<E, T, V>::expr' substitutes `T' for `V' in `E' which is often
   * expressed using notations such as `E[T/v]' or `E[v := T]' in the
   * literature.
   *
   * Substitution is not performed lazily due to efficiency reasons. The
   * buildup of large substitution thunks destroys the performance of lazy
   * substitution and makes it much slower than eager (or strict)
   * substitution.
   */
  template<class E, class T, class V>
  struct subst {
    typedef E expr;
  };

  /**
   * A lambda abstraction. Also see `fun'.
   */
  template<class I, class B>
  struct fn {
    typedef fn eval;

    template<class X>
    struct with {
      typedef typename subst<B, X, I>::expr::eval eval;
    };
  };

  template<class V, class T>
  struct subst<V, T, V> {
    typedef nf<T> expr;
  };

  template<class V, class T>
  struct subst<V, nf<T>, V> {
    typedef nf<T> expr;
  };

  template<class V, class B, class T>
  struct subst<fn<V, B>, T, V> {
    typedef fn<V, B> expr;
  };

  template<class I, class B, class T, class V>
  struct subst<fn<I, B>, T, V> {
    typedef fn<I, typename subst<B, T, V>::expr> expr;
  };

  template<class E, class T, class V>
  struct subst<nf<E>, T, V> {
    typedef nf<E> expr;
  };

  template<template<class> class F,
           class E0,
           class T, class V>
  struct subst<F<E0>, T, V> {
    typedef F<typename subst<E0, T, V>::expr> expr;
  };

  template<template<class, class> class F,
           class E0, class E1,
           class T, class V>
  struct subst<F<E0, E1>, T, V> {
    typedef F<typename subst<E0, T, V>::expr,
              typename subst<E1, T, V>::expr> expr;
  };

  template<template<class, class, class> class F,
           class E0, class E1, class E2,
           class T, class V>
  struct subst<F<E0, E1, E2>, T, V> {
    typedef F<typename subst<E0, T, V>::expr,
              typename subst<E1, T, V>::expr,
              typename subst<E2, T, V>::expr> expr;
  };

  template<template<class, class, class, class> class F,
           class E0, class E1, class E2, class E3,
           class T, class V>
  struct subst<F<E0, E1, E2, E3>, T, V> {
    typedef F<typename subst<E0, T, V>::expr,
              typename subst<E1, T, V>::expr,
              typename subst<E2, T, V>::expr,
              typename subst<E3, T, V>::expr> expr;
  };

  template<template<class, class, class, class, class> class F,
           class E0, class E1, class E2, class E3, class E4,
           class T, class V>
  struct subst<F<E0, E1, E2, E3, E4>, T, V> {
    typedef F<typename subst<E0, T, V>::expr,
              typename subst<E1, T, V>::expr,
              typename subst<E2, T, V>::expr,
              typename subst<E3, T, V>::expr,
              typename subst<E4, T, V>::expr> expr;
  };

  template<template<class, class, class, class, class, class> class F,
           class E0, class E1, class E2, class E3, class E4, class E5,
           class T, class V>
           struct subst<F<E0, E1, E2, E3, E4, E5>, T, V> {
    typedef F<typename subst<E0, T, V>::expr,
              typename subst<E1, T, V>::expr,
              typename subst<E2, T, V>::expr,
              typename subst<E3, T, V>::expr,
              typename subst<E4, T, V>::expr,
              typename subst<E5, T, V>::expr> expr;
  };

} }

#endif
