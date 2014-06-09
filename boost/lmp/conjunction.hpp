#ifndef BOOST_LMP_CONJUNCTION_HPP_VK_20043010
#define BOOST_LMP_CONJUNCTION_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/foldr.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  /**
   * `conjunction<L>' returns the conjunction of the boolean list `L'.
   *
   * Definition:
   *<
   *   template<class L>
   *   struct conjunction : foldr<op_2<and_>, L, true_> {};
   *>
   */
  template<class L>
  struct conjunction {
    typedef typename foldr<op_2<and_>,
                           typename L::eval,
                           true_>::eval eval;
  };

} }

#endif
