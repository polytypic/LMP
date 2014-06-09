#ifndef BOOST_LMP_ANY_HPP_VK_20043010
#define BOOST_LMP_ANY_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/disjunction.hpp"
#include "boost/lmp/map.hpp"

namespace boost { namespace lmp {

  /**
   * `any<P, L>' returns `true_' if at least one item in the list `L'
   * fulfills the condition `P'.
   *
   * Definition:
   *<
   *   template<class P, class L>
   *   struct any : disjunction<map<P, L> > {};
   *>
   */
  template<class P, class L>
  struct any {
    typedef typename disjunction<typename map<typename P::eval,
                                              typename L::eval>::eval>::eval eval;
  };

} }

#endif
