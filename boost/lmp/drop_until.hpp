#ifndef BOOST_LMP_DROP_UNTIL_HPP_VK_20043010
#define BOOST_LMP_DROP_UNTIL_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2005.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/compose.hpp"
#include "boost/lmp/drop_while.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  /**
   * `drop_until<P, L>' returns the list remaining after dropping all
   * elements from the front of the list `L' that do not fulfill the
   * condition `P'.
   *
   * Definition:
   *<
   *   template<class P, class L>
   *   struct drop_until : drop_while<compose<op_1<not_>, P>, L> {};
   *>
   */
  template<class P, class L>
  struct drop_until {
    typedef typename drop_while<compose<op_1<not_>,
                                        typename P::eval>,
                                typename L::eval>::eval eval;
  };

} }

#endif
