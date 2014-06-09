#ifndef BOOST_LMP_REPLICATE_HPP_VK_20043010
#define BOOST_LMP_REPLICATE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/repeat.hpp"
#include "boost/lmp/take.hpp"

namespace boost { namespace lmp {

  template<class N, class X>
  struct replicate {
    typedef typename take<typename N::eval,
                          typename repeat<X>::eval>::eval eval;
  };

} }

#endif
