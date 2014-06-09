#ifndef BOOST_LMP_SANDBOX_HPP_VK_20043010
#define BOOST_LMP_SANDBOX_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

namespace boost { namespace lmp {

  // This file is for experimentation.

#if 0

  template<class L, class R>
  struct append : match<L,
                        cons<H*, T*>, cons<H, append<T, R> >,
                        nil,          R> {};

#endif

} }

#endif
