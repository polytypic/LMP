#ifndef BOOST_LMP_TAKE_WHILE_HPP_VK_20043010
#define BOOST_LMP_TAKE_WHILE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  namespace take_while_private {
    template<class P, class L>
    struct take_while {
      typedef typename take_while<P,
                                  typename L::eval>::eval eval;
    };

    template<class P, class H, class T>
    struct take_while<P, cons<H, T> > {
      typedef typename if_<typename P::template with<H>::eval,
                           cons<H, take_while<P, T> >,
                           nil>::eval eval;
    };

    template<class P>
    struct take_while<P, nil> {
      typedef nil eval;
    };
  }

  template<class P, class L>
  struct take_while {
    typedef typename take_while_private::take_while<typename P::eval,
                                                    typename L::eval>::eval eval;
  };

} }

#endif
