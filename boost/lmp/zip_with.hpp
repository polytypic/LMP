#ifndef BOOST_LMP_ZIP_WITH_HPP_VK_20043010
#define BOOST_LMP_ZIP_WITH_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/cons.hpp"
#include "boost/lmp/nil.hpp"

namespace boost { namespace lmp {

  template<class BF, class L, class R>
  struct zip_with {
    typedef typename if_<typename or_<is_nil<L>, is_nil<R> >::eval,
                         nil,
                         cons<apply<BF, head<L>, head<R> >,
                              zip_with<BF, tail<L>, tail<R> > > >::eval eval;
  };

} }

#endif
