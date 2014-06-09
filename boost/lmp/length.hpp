#ifndef BOOST_LMP_LENGTH_HPP_VK_20043010
#define BOOST_LMP_LENGTH_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cons.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  template<class L>          struct length              { typedef int_<length<typename L::eval>::eval::value>     eval; };
  template<class H, class T> struct length<cons<H, T> > { typedef int_<length<typename T::eval>::eval::value + 1> eval; };
  template<>                 struct length<nil>         { typedef zero                                            eval; };

} }

#endif
