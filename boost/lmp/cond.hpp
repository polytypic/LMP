#ifndef BOOST_LMP_COND_HPP_VK_20043010
#define BOOST_LMP_COND_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"
#include "boost/lmp/fn.hpp"

namespace boost { namespace lmp {

  /**
   * `cond<B0, C0, ..., BN, CN, D> is shorthand for
   * `if_<B0, C0, ..., if_<BN, CN, D> ... >'.
   *
   * Note that the number of parameters to `cond' must be odd.
   */
  template<class B0,        class C0 = void,
           class B1 = void, class C1 = void,
           class B2 = void, class C2 = void,
           class B3 = void, class C3 = void,
           class B4 = void, class C4 = void,
           class B5 = void, class C5 = void,
           class Otherwise = void>
  struct cond {
    typedef typename if_<typename B0::eval,
                         C0,
                         cond<B1, C1,
                              B2, C2,
                              B3, C3,
                              B4, C4,
                              B5, C5,
                              Otherwise> >::eval eval;
  };

  template<class Otherwise>
  struct cond<Otherwise> {
    typedef typename Otherwise::eval eval;
  };

#define F cond
#define FROM 1
#define TO 13
#include "boost/lmp/detail/variadic.hpp"

} }

#endif
