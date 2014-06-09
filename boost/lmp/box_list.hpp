#ifndef BOOST_LMP_BOX_LIST_HPP_VK_20043010
#define BOOST_LMP_BOX_LIST_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/box.hpp"
#include "boost/lmp/cons.hpp"
#include "boost/lmp/fn.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  /**
   * `box_list<t1, ..., tN>' is shorthand for `list<box<t1>, ..., box<tN> >'.
   */
  template<class X0,              class X1  = box<void>, class X2  = box<void>, class X3  = box<void>, class X4  = box<void>,
           class X5  = box<void>, class X6  = box<void>, class X7  = box<void>, class X8  = box<void>, class X9  = box<void>,
           class X10 = box<void>, class X11 = box<void>, class X12 = box<void>, class X13 = box<void>, class X14 = box<void>,
           class X15 = box<void>, class X16 = box<void>, class X17 = box<void>, class X18 = box<void>, class X19 = box<void> >
  struct box_list {
    typedef cons<box<X0>,
                 typename box_list<X1,  X2,  X3,  X4,
                                   X5,  X6,  X7,  X8,  X9,
                                   X10, X11, X12, X13, X14,
                                   X15, X16, X17, X18, X19>::eval> eval;
  };

  template<class X0>
  struct box_list<X0> {
    typedef cons<box<X0>, nil> eval;
  };

#define F box_list
#define FROM 1
#define TO 20
#include "boost/lmp/detail/unsubstitutable.hpp"

} }

#endif
