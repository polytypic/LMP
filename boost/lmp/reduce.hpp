#ifndef BOOST_LMP_REDUCE_HPP_VK_20043010
#define BOOST_LMP_REDUCE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/spine.hpp"

namespace boost { namespace lmp {

  template<class F, class L>
  struct reduce_once {
    typedef typename reduce_once<typename F::eval,
                                 typename spine<L>::eval>::eval eval;
  };

  template<class F, class X, class Y, class T>
  struct reduce_once<F, cons<X, cons<Y, T> > > {
    typedef cons<typename F::template with<X>::eval::template with<Y>::eval,
                 typename reduce_once<F, T>::eval> eval;
  };

  template<class F, class X>
  struct reduce_once<F, cons<X, nil> > {
    typedef cons<X, nil> eval;
  };

  template<class F>
  struct reduce_once<F, nil> {
    typedef nil eval;
  };

  template<class F, class L>
  struct reduce {
    typedef typename if_<typename or_<is_nil<L>,
                                      is_nil<tail<L> > >::eval,
                         L,
                         reduce<typename F::eval,
                                reduce_once<F, L> > >::eval eval;
  };

} }

#endif
