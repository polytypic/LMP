#ifndef BOOST_LMP_DROP_HPP_VK_20043010
#define BOOST_LMP_DROP_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  /**
   * `drop<N, L>' returns the list remaining after dropping the first `N'
   * elements from the list `L'.
   *
   * Definition:
   *<
   *   template<class N, class L>
   *   struct drop : if_<or_<is_0<N>, is_nil<L> >,
   *                     L,
   *                     drop<pred<N>, tail<L> > > {};
   *>
   */
  template<class N, class L>
  struct drop {
    typedef typename drop<typename N::eval,
                          typename L::eval>::eval eval;
  };

  template<int_type N, class H, class T>
  struct drop<int_<N>, cons<H, T> > {
    typedef typename drop<int_<N-1>,
                          typename T::eval>::eval eval;
  };

  template<class H, class T>
  struct drop<zero, cons<H, T> > {
    typedef cons<H, T> eval;
  };

  template<class N>
  struct drop<N, nil> {
    typedef nil eval;
  };

} }

#endif
