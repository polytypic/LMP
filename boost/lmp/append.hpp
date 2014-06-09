#ifndef BOOST_LMP_APPEND_HPP_VK_20043010
#define BOOST_LMP_APPEND_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  /**
   * `all<L, R>' concatenates the lists `L' and `R'.
   *
   * Definition:
   *<
   *   template<class L, class R>
   *   struct append : if_<is_cons<L>,
   *                       cons<head<L>,
   *                            append<tail<L>, R> >,
   *                       R> {};
   *>
   */
  template<class L, class R>
  struct append {
    typedef typename append<typename L::eval, R>::eval eval;
  };

  template<class H, class T, class R>
  struct append<cons<H, T>, R> {
    typedef cons<H, append<typename T::eval, R> > eval;
  };

  template<class R>
  struct append<nil, R> {
    typedef typename R::eval eval;
  };

} }

#endif
