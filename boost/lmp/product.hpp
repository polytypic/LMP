#ifndef BOOST_LMP_PRODUCT_HPP_VK_20043010
#define BOOST_LMP_PRODUCT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/foldr.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  template<class L>
  struct product {
    typedef typename foldr<op_2<times>, typename L::eval, one>::eval eval;
  };

} }

#endif
