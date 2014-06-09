#ifndef BOOST_LMP_TAKE_UNTIL_HPP_VK_20043010
#define BOOST_LMP_TAKE_UNTIL_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2005.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/compose.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/take_while.hpp"

namespace boost { namespace lmp {

  template<class P, class L>
  struct take_until {
    typedef typename take_while<compose<op_1<not_>,
                                        typename P::eval>,
                                L>::eval eval;
  };

} }

#endif
