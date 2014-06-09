#ifndef BOOST_LMP_FILTER_HPP_VK_20043010
#define BOOST_LMP_FILTER_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  namespace filter_private {
    template<class P, class L>
    struct filter {
      typedef nil eval;
    };

    template<class P, class H, class T>
    struct filter<P, cons<H, T> > {
      typedef typename if_<bool_<P::template with<typename H::eval>::eval::value>,
                           cons<typename H::eval,
                                filter<P, typename T::eval> >,
                           filter<P, typename T::eval> >::eval eval;
    };
  }

  template<class P, class L>
  struct filter {
    typedef typename filter_private::filter<typename P::eval,
                                            typename L::eval>::eval eval;
  };

} }

#endif
