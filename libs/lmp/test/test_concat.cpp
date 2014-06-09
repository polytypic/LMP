// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/concat.hpp"
#include "boost/lmp/fn.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/iterate.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/take.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef test< int_list<0,
                       0, -1,
                       0, -1, -2,
                       0, -1>,
              take<int_<1+2+3+2>,
                   concat<map<fn<N,
                                 take<N,
                                      nf<iterate<op_1<pred>, zero> > > >,
                              iterate<op_1<succ>, one> > > > > TEST;

typedef test< int_list<0,
                       0, -1>,
              concat<take<int_<3>,
                          map<fn<N,
                                 take<N,
                                      nf<iterate<op_1<pred>, zero> > > >,
                              iterate<op_1<succ>, zero> > > > > TEST;
