#ifndef BOOST_LMP_GCD_HPP_VK_20043010
#define BOOST_LMP_GCD_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int.hpp"

namespace boost { namespace lmp {

  namespace gcd_private {
    template<int_type X, int_type Y>
    struct gcd {
      static const int_type value = gcd<Y, X % Y>::value;
    };

    template<int_type X>
    struct gcd<X, 0> {
      static const int_type value = X;
    };
  }

  template<class X, class Y>
  struct gcd {
    typedef int_<gcd_private::gcd<abs<X>::eval::value,
                                  abs<Y>::eval::value>::value> eval;
  };

} }

#endif
