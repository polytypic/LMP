#ifndef BOOST_LMP_BOX_HPP_VK_20043010
#define BOOST_LMP_BOX_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"

namespace boost { namespace lmp {

  /**
   * `box<type>' turns an arbitrary type into a value.
   *
   * If `expr' evaluates to a box, then the enclosed type can be accessed
   * as `expr::eval::type'.
   */
  template<class T>
  struct box {
    typedef box eval;
    typedef T type;
  };

  template<class X>
  struct unbox {
    typedef typename unbox<typename X::eval>::eval eval;
  };

  template<class T>
  struct unbox<box<T> > {
    typedef typename T::eval eval;
  };

#define F box
#define FROM 1
#define TO 1
#include "boost/lmp/detail/unsubstitutable.hpp"

} }

#endif
