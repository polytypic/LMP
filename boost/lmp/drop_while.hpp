#ifndef BOOST_LMP_DROP_WHILE_HPP_VK_20043010
#define BOOST_LMP_DROP_WHILE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  namespace drop_while_private {
    template<class P, class L>
    struct drop_while {
      typedef nil eval;
    };

    template<class P, class H, class T>
    struct drop_while<P, cons<H, T> > {
      typedef typename if_<typename P::template with<H>::eval,
                           drop_while<P, typename T::eval>,
                           cons<H, T> >::eval eval;
    };
  }

  /**
   * `drop_while<P, L>' returns the list remaining after dropping all
   * elements from the front of the list `L' that fulfill the condition
   * `P'.
   *
   * Definition:
   *<
   *   template<class P, class L>
   *   struct drop_while : if_<and_<is_cons<L>,
   *                                apply<P, head<L> > >,
   *                           drop_while<P, tail<L> >,
   *                           nil> {};
   *>
   */
  template<class P, class L>
  struct drop_while {
    typedef typename drop_while_private::drop_while<typename P::eval,
                                                    typename L::eval>::eval eval;
  };

} }

#endif
