#ifndef BOOST_LMP_CHAIN_HPP_VK_20043010
#define BOOST_LMP_CHAIN_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"
#include "boost/lmp/compose.hpp"

namespace boost { namespace lmp {

  /**
   * `chain<F0, F1, ..., FN>' is shorthand for
   * `compose<F0, compose<F1, ..., FN> ... >'.
   */
  template<class F0, class F1, class F2 = void, class F3 = void, class F4 = void>
  struct chain {
    typedef compose<typename F0::eval,
                    typename chain<F1, F2, F3, F4>::eval> eval;
  };

  template<class F0, class F1>
  struct chain<F0, F1> {
    typedef compose<typename F0::eval,
                    typename F1::eval> eval;
  };

#define F chain
#define FROM 2
#define TO 5
#include "boost/lmp/detail/variadic.hpp"

} }

#endif
