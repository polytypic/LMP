#ifndef BOOST_LMP_ERROR_HPP_VK_20043010
#define BOOST_LMP_ERROR_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

namespace boost { namespace lmp {

  template<class E>
  struct error {
    typedef typename E::must_NOT_be_defined eval;
  };

} }

#endif
