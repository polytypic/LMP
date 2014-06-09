#ifndef BOOST_LMP_SIZEOF_HPP_VK_20043010
#define BOOST_LMP_SIZEOF_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2005.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int.hpp"

namespace boost { namespace lmp {

  template<class T>
  struct sizeof_ {
    typedef int_<sizeof(typename T::eval::type)> eval;
  };

} }

#endif
