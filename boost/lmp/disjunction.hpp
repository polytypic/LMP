#ifndef BOOST_LMP_DISJUNCTION_HPP_VK_20043010
#define BOOST_LMP_DISJUNCTION_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/foldr.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  /**
   * `disjunction<L>' returns the disjunction of the boolean list `L'.
   *
   * Definition:
   *<
   *   template<class L>
   *   struct disjunction : foldr<op_2<or_>, L, false_> {};
   *>
   */
  template<class L>
  struct disjunction {
    typedef typename foldr<op_2<or_>,
                           typename L::eval,
                           false_>::eval eval;
  };

} }

#endif
