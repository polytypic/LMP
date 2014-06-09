#ifndef BOOST_LMP_MERGE_HPP_VK_20043010
#define BOOST_LMP_MERGE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  namespace merge_private {
    template<class LTP, class L, class R>
    struct merge {
      typedef typename merge<LTP,
                             typename L::eval,
                             typename R::eval>::eval eval;
    };

    template<class LTP, class LH, class LT, class RH, class RT>
    struct merge<LTP, cons<LH, LT>, cons<RH, RT> > {
      typedef typename if_<typename LTP::template with<RH>::eval::template with<LH>::eval,
                           cons<RH, merge<LTP, cons<LH, LT>, RT> >,
                           cons<LH, merge<LTP, LT, cons<RH, RT> > > >::eval eval;
    };

    template<class LTP, class L>
    struct merge<LTP, L, nil> {
      typedef L eval;
    };

    template<class LTP, class R>
    struct merge<LTP, nil, R> {
      typedef R eval;
    };

    template<class LTP>
    struct merge<LTP, nil, nil> {
      typedef nil eval;
    };
  }

  template<class LTP, class L, class R>
  struct merge {
    typedef typename merge_private::merge<typename LTP::eval,
                                          typename L::eval,
                                          typename R::eval>::eval eval;
  };

} }

#endif
