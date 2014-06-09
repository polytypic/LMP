#ifndef BOOST_LMP_ITERATE_HPP_VK_20043010
#define BOOST_LMP_ITERATE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"

namespace boost { namespace lmp {

  namespace iterate_private {
    template<class UF, class X>
    struct iterate {
      typedef cons<typename X::eval,
                   iterate<UF, typename UF::template with<typename X::eval> > > eval;
    };
  }

  template<class UF, class X>
  struct iterate {
    typedef typename iterate_private::iterate<typename UF::eval,
                                              X>::eval eval;
  };

} }

#endif
