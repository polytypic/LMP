// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/box_list.hpp"
#include "boost/lmp/fun.hpp"
#include "boost/lmp/sizeof.hpp"
#include "boost/lmp/sort.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef test< box_list<int[1], int[1], int[3], int[4], int[5]>,
              sort<fun<X, Y,
                       less<sizeof_<X>,
                            sizeof_<Y> > >,
                   box_list<int[3], int[1], int[4], int[1], int[5]> > > TEST;
