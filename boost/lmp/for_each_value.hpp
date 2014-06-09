#ifndef BOOST_LMP_FOR_EACH_VALUE_HPP_VK_20043010
#define BOOST_LMP_FOR_EACH_VALUE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  namespace for_each_value_private {
    template<class H, class T, class F>
    inline void for_each_value(F f, cons<H, T>* = 0) {
      f(H::eval::value);
      for_each_value(f, static_cast<typename T::eval*>(0));
    }

    template<class F>
    inline void for_each_value(F, nil* = 0) {}
  }

  template<class L, class F>
  inline void for_each_value(F f, L* = 0) {
    for_each_value_private::for_each_value(f, static_cast<typename L::eval*>(0));
  }

} }

#endif
