#ifndef BOOST_LMP_WHILE_HPP_VK_20043010
#define BOOST_LMP_WHILE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"

namespace boost { namespace lmp {

  namespace while_private {
    template<class P, class F, class X>
    struct while_ {
      typedef typename if_<typename P::template with<typename X::eval>::eval,
                           while_<P, F, typename F::template with<typename X::eval> >,
                           typename X::eval>::eval eval;
    };
  }

  template<class P, class F, class X>
  struct while_ {
    typedef typename while_private::while_<typename P::eval,
                                           typename F::eval,
                                           typename X::eval>::eval eval;
  };

} }

#endif
