#ifndef BOOST_LMP_ALL_HPP_VK_20043010
#define BOOST_LMP_ALL_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/conjunction.hpp"
#include "boost/lmp/map.hpp"

namespace boost { namespace lmp {

  /**
   * `all<P, L>' returns `true_' if all items in the list `L' fulfill the
   * condition `P'.
   *
   * Definition:
   *<
   *   template<class P, class L>
   *   struct all : conjunction<map<P, L> > {};
   *>
   */
  template<class P, class L>
  struct all {
    typedef typename conjunction<typename map<typename P::eval,
                                              typename L::eval>::eval>::eval eval;
  };

} }

#endif
