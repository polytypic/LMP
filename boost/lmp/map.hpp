#ifndef BOOST_LMP_MAP_HPP_VK_20043010
#define BOOST_LMP_MAP_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  namespace map_private {
    template<class UF, class L>
    struct map {
      typedef typename map<UF, typename L::eval>::eval eval;
    };

    template<class UF, class H, class T>
    struct map<UF, cons<H, T> > {
      typedef cons<typename UF::template with<H>,
                   map<UF, T> > eval;
    };

    template<class UF>
    struct map<UF, nil> {
      typedef nil eval;
    };
  }

  template<class UF, class L>
  struct map {
    typedef typename map_private::map<typename UF::eval,
                                      typename L::eval>::eval eval;
  };

} }

#endif
