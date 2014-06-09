#ifndef BOOST_LMP_LCM_HPP_VK_20043010
#define BOOST_LMP_LCM_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/gcd.hpp"

namespace boost { namespace lmp {

  template<class X, class Y>
  struct lcm {
    typedef typename if_<or_<is_0<X>, is_0<Y> >,
                         zero,
                         abs<times<quotient<X, gcd<X, Y> >,
                                   Y> > >::eval eval;
  };

} }

#endif
