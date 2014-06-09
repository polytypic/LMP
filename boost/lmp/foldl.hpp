#ifndef BOOST_LMP_FOLDL_HPP_VK_20043010
#define BOOST_LMP_FOLDL_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"

namespace boost { namespace lmp {

  namespace foldl_private {
    template<class BF, class X, class L>
    struct foldl {
      typedef typename X::eval eval;
    };

    template<class BF, class X, class H, class T>
    struct foldl<BF, X, cons<H, T> > {
      typedef typename foldl<BF,
                             typename BF::template with<X>::eval::template with<H>::eval,
                             typename T::eval>::eval eval;
    };
  }

  template<class BF, class X, class L>
  struct foldl {
    typedef typename foldl_private::foldl<typename BF::eval,
                                          typename X::eval,
                                          typename L::eval>::eval eval;
  };

} }

#endif
