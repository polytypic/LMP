#ifndef BOOST_LMP_APP_HPP_VK_20043010
#define BOOST_LMP_APP_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"

namespace boost { namespace lmp {

  /**
   * `app<F, X>' applies the function `F' to `X'.
   */
  template<class F, class X>
  struct app {
    typedef typename F::eval::template with<X>::eval eval;
  };

} }

#endif
