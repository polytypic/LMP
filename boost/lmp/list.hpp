#ifndef BOOST_LMP_LIST_HPP_VK_20043010
#define BOOST_LMP_LIST_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/fn.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  template<class X0,         class X1  = void, class X2  = void, class X3  = void, class X4  = void,
           class X5  = void, class X6  = void, class X7  = void, class X8  = void, class X9  = void,
           class X10 = void, class X11 = void, class X12 = void, class X13 = void, class X14 = void,
           class X15 = void, class X16 = void, class X17 = void, class X18 = void, class X19 = void>
  struct list {
    typedef cons<X0,
                 typename list<X1,  X2,  X3,  X4,
                               X5,  X6,  X7,  X8,  X9,
                               X10, X11, X12, X13, X14,
                               X15, X16, X17, X18, X19>::eval> eval;
  };

  template<class X0>
  struct list<X0> {
    typedef cons<X0, nil> eval;
  };

  template<class X0>
  struct list1 {
    typedef cons<X0, nil> eval;
  };

#define F list
#define FROM 1
#define TO 20
#include "boost/lmp/detail/variadic.hpp"

} }

#endif
