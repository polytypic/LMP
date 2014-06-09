#ifndef BOOST_LMP_SORT_HPP_VK_20043010
#define BOOST_LMP_SORT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/list.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/merge.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/reduce.hpp"

namespace boost { namespace lmp {

  template<class LTP, class L>
  struct sort {
    typedef typename if_<typename is_nil<typename L::eval>::eval,
                         nil,
                         head<reduce<bind_1_of_3<merge, typename LTP::eval>,
                                     map<op_1<list1>,
                                         typename L::eval> > > >::eval eval;
  };

} }

#endif
