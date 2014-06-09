#ifndef BOOST_LMP_UNIQ_HPP_VK_20043010
#define BOOST_LMP_UNIQ_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/drop_while.hpp"

namespace boost { namespace lmp {

  template<class EQP, class L>
  struct uniq {
    typedef typename uniq<typename EQP::eval,
                          typename L::eval>::eval eval;
  };

  template<class EQP, class H, class T>
  struct uniq<EQP, cons<H, T> > {
    typedef cons<H,
                 uniq<EQP,
                      drop_while<typename EQP::template with<H>,
                                 T> > > eval;
  };

  template<class EQP>
  struct uniq<EQP, nil> {
    typedef nil eval;
  };

} }

#endif
