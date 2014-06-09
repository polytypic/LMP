#ifndef BOOST_LMP_APPLY_HPP_VK_20043010
#define BOOST_LMP_APPLY_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"

namespace boost { namespace lmp {

  template<class F, class X0, class X1 = void, class X2 = void, class X3 = void, class X4 = void>
  struct apply {
    typedef typename apply<typename F::eval::template with<X0>::eval, X1, X2, X3, X4>::eval eval;
  };

  template<class F, class X0>
  struct apply<F, X0> {
    typedef typename F::eval::template with<X0>::eval eval;
  };

#define F apply
#define FROM 2
#define TO 6
#include "boost/lmp/detail/variadic.hpp"

} }

#endif
