#ifndef BOOST_LMP_SUM_HPP_VK_20043010
#define BOOST_LMP_SUM_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/foldr.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  template<class L>
  struct sum {
    typedef typename foldr<op_2<plus>,
                           typename L::eval,
                           zero>::eval eval;
  };

} }

#endif
