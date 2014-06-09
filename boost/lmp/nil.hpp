#ifndef BOOST_LMP_NIL_HPP_VK_20043010
#define BOOST_LMP_NIL_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"

namespace boost { namespace lmp {

  struct nil {
    typedef nil eval;
  };

  namespace nil_private {
    template<class X> struct is_nil_helper      { typedef false_ eval; };
    template<>        struct is_nil_helper<nil> { typedef true_  eval; };
  }

  template<class X>
  struct is_nil {
    typedef typename nil_private::is_nil_helper<typename X::eval>::eval eval;
  };

} }

#endif
