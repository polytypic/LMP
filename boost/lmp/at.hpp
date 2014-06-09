#ifndef BOOST_LMP_AT_HPP_VK_20043010
#define BOOST_LMP_AT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/drop.hpp"

namespace boost { namespace lmp {

  /**
   * `at<I, L>' returns the `I'th element of the list `L'.
   *
   * Definition:
   *<
   *   template<class I, class L>
   *   struct at : head<drop<I, L> > {};
   *>
   */
  template<class I, class L>
  struct at {
    typedef typename head<typename drop<typename I::eval,
                                        typename L::eval>::eval>::eval eval;
  };

} }

#endif
