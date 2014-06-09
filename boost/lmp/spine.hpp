#ifndef BOOST_LMP_SPINE_HPP_VK_20043010
#define BOOST_LMP_SPINE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  template<class L>
  struct spine {
    typedef typename spine<typename L::eval>::eval eval;
  };

  template<class H, class T>
  struct spine<cons<H, T> > {
    typedef cons<H, typename spine<typename T::eval>::eval> eval;
  };

  template<>
  struct spine<nil> {
    typedef nil eval;
  };

} }

#endif
