#ifndef BOOST_LMP_CONCAT_HPP_VK_20043010
#define BOOST_LMP_CONCAT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/append.hpp"
#include "boost/lmp/foldr.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  /**
   * `concat<LL>' returns the concatenation of the list of lists `LL'.
   *
   * Definition:
   *<
   *   template<class LL>
   *   struct concat : foldr<op_2<append>, LL, nil> {};
   *>
   */
  template<class LL>
  struct concat {
    typedef typename foldr<op_2<append>,
                           typename LL::eval,
                           nil>::eval eval;
  };

} }

#endif
