#ifndef BOOST_LMP_INT_LIST_HPP_VK_20043010
#define BOOST_LMP_INT_LIST_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/nil.hpp"
#include <climits>

namespace boost { namespace lmp {

  template<int_type X0,             int_type X1  = LONG_MIN, int_type X2  = LONG_MIN, int_type X3  = LONG_MIN, int_type X4  = LONG_MIN,
           int_type X5  = LONG_MIN, int_type X6  = LONG_MIN, int_type X7  = LONG_MIN, int_type X8  = LONG_MIN, int_type X9  = LONG_MIN,
           int_type X10 = LONG_MIN, int_type X11 = LONG_MIN, int_type X12 = LONG_MIN, int_type X13 = LONG_MIN, int_type X14 = LONG_MIN,
           int_type X15 = LONG_MIN, int_type X16 = LONG_MIN, int_type X17 = LONG_MIN, int_type X18 = LONG_MIN, int_type X19 = LONG_MIN>
  struct int_list {
    typedef cons<int_<X0>,
                 typename int_list<X1,  X2,  X3,  X4,
                                   X5,  X6,  X7,  X8,  X9,
                                   X10, X11, X12, X13, X14,
                                   X15, X16, X17, X18, X19>::eval> eval;
  };

  template<int_type X0>
  struct int_list<X0> {
    typedef cons<int_<X0>, nil> eval;
  };

} }

#endif
