#ifndef BOOST_LMP_FOLDR_HPP_VK_20043010
#define BOOST_LMP_FOLDR_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"

namespace boost { namespace lmp {

  namespace foldr_private {
    template<class BF, class L, class X>
    struct foldr {
      typedef typename X::eval eval;
    };

    template<class BF, class H, class T, class X>
    struct foldr<BF, cons<H, T>, X> {
      typedef typename BF::template with<H>::eval::template with<foldr<BF, typename T::eval, X> >::eval eval;
    };
  }

  template<class BF, class L, class X>
  struct foldr {
    typedef typename foldr_private::foldr<typename BF::eval,
                                          typename L::eval,
                                          typename X::eval>::eval eval;
  };

} }

#endif
