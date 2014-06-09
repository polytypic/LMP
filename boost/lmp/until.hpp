#ifndef BOOST_LMP_UNTIL_HPP_VK_20043010
#define BOOST_LMP_UNTIL_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/compose.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/while.hpp"

namespace boost { namespace lmp {

  template<class P, class F, class X>
  struct until_ {
    typedef typename while_<compose<op_1<not_>, typename P::eval>,
                            F,
                            X>::eval eval;
  };

} }

#endif
