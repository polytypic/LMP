#ifndef BOOST_LMP_CYCLE_HPP_VK_20043010
#define BOOST_LMP_CYCLE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/append.hpp"
#include "boost/lmp/error.hpp"

namespace boost { namespace lmp {

  /**
   * `cycle<L>' creates an infinite circular list from the list `L'.
   *
   * Definition:
   *<
   *   template<class L>
   *   struct cycle : append<L, cycle<L> > {};
   *>
   */
  template<class L>
  struct cycle {
    typedef typename cycle<typename L::eval>::eval eval;
  };

  template<class H, class T>
  struct cycle<cons<H, T> > {
    typedef typename append<cons<H, T>, cycle<cons<H, T> > >::eval eval;
  };

  template<>
  struct cycle<nil> {
    /* intentionally not defined */
  };

} }

#endif
