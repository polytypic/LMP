#ifndef BOOST_LMP_FLIP_HPP_VK_20043010
#define BOOST_LMP_FLIP_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/fun.hpp"
#include "boost/lmp/var.hpp"

namespace boost { namespace lmp {

  /**
   * `flip<F>' returns a function that corresponds to `F' except that it
   * takes the first two arguments in the opposite order.
   *
   * Definition:
   *<
   *   template<class F>
   *   struct flip : fun<X, Y,
   *                     apply<F, Y, X> > {};
   *>
   */
  template<class F>
  struct flip {
    typedef fn<X, fn<Y, apply<F, Y, X> > > eval;
  };

} }

#endif
