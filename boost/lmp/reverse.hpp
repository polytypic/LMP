#ifndef BOOST_LMP_REVERSE_HPP_VK_20043010
#define BOOST_LMP_REVERSE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/foldl.hpp"
#include "boost/lmp/nil.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  template<class L>
  struct reverse {
    typedef typename foldl<op_2<snoc>, nil, typename L::eval>::eval eval;
  };

} }

#endif
