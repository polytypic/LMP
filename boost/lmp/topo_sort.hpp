#ifndef BOOST_LMP_TOPO_SORT_HPP_VK_20043010
#define BOOST_LMP_TOPO_SORT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/append.hpp"
#include "boost/lmp/compose.hpp"
#include "boost/lmp/filter.hpp"
#include "boost/lmp/op.hpp"

namespace boost { namespace lmp {

  // TBD: This is actually a naive quicksort. Are there better
  // algorithms for topological sorting when adjacency lists are not
  // available?

  template<class LTP, class L>
  struct topo_sort {
    typedef typename if_<typename or_<is_nil<L>, is_nil<tail<L> > >::eval,
                         L,
                         append<topo_sort<LTP,
                                          filter<typename LTP::eval::template with<head<L> >,
                                                 tail<L> > >,
                                cons<head<L>,
                                     topo_sort<LTP,
                                               filter<compose<op_1<not_>,
                                                              typename LTP::eval::template with<head<L> > >,
                                                      tail<L> > > > > >::eval eval;
  };

} }

#endif
