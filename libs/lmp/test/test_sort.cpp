// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int_list.hpp"
#include "boost/lmp/sort.hpp"
#include "boost/lmp/take.hpp"
#include "test.hpp"

typedef test< int_list<1, 1, 2, 2, 3, 3, 3, 3, 4, 4,
                       5, 5, 5, 6, 7, 8, 8, 9, 9, 9>,
              sort<op_2<less>,
                   int_list<3, 1, 4, 1, 5, 9, 2, 6, 5, 3,
                            5, 8, 9, 7, 9, 3, 2, 3, 8, 4> > > TEST;

typedef test< nil,
              sort<op_2<less>,
                   take<zero, int_list<2, 1> > > > TEST;
