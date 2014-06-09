#ifndef BOOST_LMP_REPEAT_HPP_VK_20043010
#define BOOST_LMP_REPEAT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"

namespace boost { namespace lmp {

  namespace repeat_private {
    template<class X>
    struct repeat {
      typedef cons<X, repeat<X> > eval;
    };
  }

  template<class X>
  struct repeat {
    typedef typename repeat_private::repeat<typename X::eval>::eval eval;
  };

} }

#endif
