#ifndef BOOST_LMP_CONS_HPP_VK_20043010
#define BOOST_LMP_CONS_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"

namespace boost { namespace lmp {

  /**
   * `cons<H, T>' is a list constructor.
   */
  template<class H, class T>
  struct cons {
    typedef cons eval;
  };

  /**
   * `snoc<T, H>' is equivalent to `cons<H, T>'.
   */
  template<class T, class H>
  struct snoc {
    typedef cons<H, T> eval;
  };

  namespace cons_private {
    template<class L>          struct is_cons_helper              { typedef false_ eval; };
    template<class H, class T> struct is_cons_helper<cons<H, T> > { typedef true_ eval;  };
  }

  /**
   * `is_cons<X>' returns `true_' if `X == cons<H, T>'.
   */
  template<class X>
  struct is_cons {
    typedef typename cons_private::is_cons_helper<typename X::eval>::eval eval;
  };

  /**
   * `head<X>' returns the head `H' of the cons cell `X == cons<H, T>'.
   */
  template<class L>          struct head              { typedef typename head<typename L::eval>::eval eval; };
  template<class H, class T> struct head<cons<H, T> > { typedef typename H::eval                      eval; };

  /**
   * `tail<X>' returns the tail `T' of the cons cell `X == cons<H, T>'.
   */
  template<class L>          struct tail              { typedef typename tail<typename L::eval>::eval eval; };
  template<class H, class T> struct tail<cons<H, T> > { typedef typename T::eval                      eval; };

} }

#endif
