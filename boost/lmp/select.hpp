#ifndef BOOST_LMP_SELECT_HPP_VK_20043010
#define BOOST_LMP_SELECT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/foldr.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  template<class LTP, class L, class R>
  struct min_by {
    typedef typename if_<typename LTP::eval::template with<R>::eval::template with<L>::eval,
                         R,
                         L>::eval eval;
  };

  template<class LTP, class L, class R>
  struct max_by {
    typedef typename if_<typename LTP::eval::template with<L>::eval::template with<R>::eval,
                         R,
                         L>::eval eval;
  };

  template<class LTP, class X, class L>
  struct select {
    typedef typename foldr<bind_1_of_3<min_by, typename LTP::eval>,
                           typename L::eval,
                           typename X::eval>::eval eval;
  };

} }

#endif
