#ifndef BOOST_LMP_LET_HPP_VK_20043010
#define BOOST_LMP_LET_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/fn.hpp"

namespace boost { namespace lmp {

  template<class V0, class E0,
           class E>
  struct let {
    typedef typename subst<E, E0, V0>::expr::eval eval;
  };

  template<class V0, class E0, class E,
           class T, class V>
  struct subst<let<V0, E0,
                   E>,
               T, V> {
    typedef let<V0, typename subst<E0, T, V>::expr,
                typename subst<E, T, V>::expr> expr;
  };

  template<class E0, class E,
           class T, class V>
  struct subst<let<V, E0,
                   E>,
               T, V> {
    typedef let<V, typename subst<E0, T, V>::expr,
                E> expr;
  };

} }

#endif
