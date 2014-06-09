#ifndef BOOST_LMP_PAIR_HPP_VK_20043010
#define BOOST_LMP_PAIR_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"

namespace boost { namespace lmp {

  // TBD: Do we need both a "pair" and a "cons"? Technically no, but conceptually maybe?

  template<class H, class T>
  struct pair {
    typedef pair eval;
  };

  namespace pair_private {
    template<class L>          struct is_pair_helper              { typedef false_ eval; };
    template<class H, class T> struct is_pair_helper<pair<H, T> > { typedef true_  eval; };
  }

  template<class X>
  struct is_pair {
    typedef typename pair_private::is_pair_helper<typename X::eval>::eval eval;
  };

  template<class L>          struct first              { typedef typename first<typename L::eval>::eval eval; };
  template<class H, class T> struct first<pair<H, T> > { typedef typename H::eval                       eval; };

  template<class L>          struct second              { typedef typename second<typename L::eval>::eval eval; };
  template<class H, class T> struct second<pair<H, T> > { typedef typename T::eval                        eval; };

} }

#endif
