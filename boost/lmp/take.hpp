#ifndef BOOST_LMP_TAKE_HPP_VK_20043010
#define BOOST_LMP_TAKE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  /**
   * `take<N, L>' returns a list of the first `max<length<L>, N>' elements
   * of the list `L'.
   *
   * Definition:
   *<
   *   template<class N, class L>
   *   struct take : if_<or_<is_0<N>, is_nil<L> >,
   *                     nil,
   *                     cons<head<L>,
   *                          take<pred<N>, tail<L> > > > {};
   *>
   */
  template<class N, class L>
  struct take {
    typedef typename take<typename N::eval,
                          typename L::eval>::eval eval;
  };

  template<int_type N, class H, class T>
  struct take<int_<N>, cons<H, T> > {
    typedef cons<H,
                 take<int_<N-1>,
                      typename T::eval> > eval;
  };

  template<class H, class T>
  struct take<zero, cons<H, T> > {
    typedef nil eval;
  };

  template<class N>
  struct take<N, nil> {
    typedef nil eval;
  };

} }

#endif
