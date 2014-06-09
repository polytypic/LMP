// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/chain.hpp"
#include "boost/lmp/heap.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/iterate.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/take_until.hpp"
#include "test.hpp"

typedef test< int_list<9, 6, 5, 5, 4, 3, 2, 1, 1>,
              map<op_1<heap_top>,
                  take_until<op_1<heap_is_empty>,
                             iterate<op_1<heap_pop>,
                                     heap_build<op_2<greater>,
                                                int_list<3, 1, 4, 1, 5, 9, 2, 6, 5> > > > > > TEST;
