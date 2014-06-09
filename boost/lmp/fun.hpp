#ifndef BOOST_LMP_FUN_HPP_VK_20043010
#define BOOST_LMP_FUN_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"

namespace boost { namespace lmp {

  template<class I0, class I1, class I2 = void, class I3 = void, class I4 = void, class B = void>
  struct fun {
    typedef fn<I0, typename fun<I1, I2, I3, I4, B>::eval> eval;
  };

  template<class I0, class B>
  struct fun<I0, B> {
    typedef fn<I0, B> eval;
  };

  template<class X0, class X1, class T, class V>
  struct subst<fun<X0, X1>, T, V> {
    typedef typename subst<typename fun<X0, X1>::eval, T, V>::expr expr;
  };

  template<class X0, class X1, class X2, class T, class V>
  struct subst<fun<X0, X1, X2>, T, V> {
    typedef typename subst<typename fun<X0, X1, X2>::eval, T, V>::expr expr;
  };

  template<class X0, class X1, class X2, class X3, class T, class V>
  struct subst<fun<X0, X1, X2, X3>, T, V> {
    typedef typename subst<typename fun<X0, X1, X2, X3>::eval, T, V>::expr expr;
  };

  template<class X0, class X1, class X2, class X3, class X4, class T, class V>
  struct subst<fun<X0, X1, X2, X3, X4>, T, V> {
    typedef typename subst<typename fun<X0, X1, X2, X3, X4>::eval, T, V>::expr expr;
  };

  template<class X0, class X1, class X2, class X3, class X4, class X5, class T, class V>
  struct subst<fun<X0, X1, X2, X3, X4, X5>, T, V> {
    typedef typename subst<typename fun<X0, X1, X2, X3, X4, X5>::eval, T, V>::expr expr;
  };

} }

#endif
