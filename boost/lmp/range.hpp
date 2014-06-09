#ifndef BOOST_LMP_RANGE_HPP_VK_20043010
#define BOOST_LMP_RANGE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/iterate.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/take.hpp"

namespace boost { namespace lmp {

  template<class A, class B>
  struct range {
    typedef typename if_<typename less<A, B>::eval,
                         take<minus<B, A>,
                              iterate<op_1<succ>, A> >,
                         take<minus<A, B>,
                              iterate<op_1<pred>, pred<A> > > >::eval eval;
  };

} }

#endif
