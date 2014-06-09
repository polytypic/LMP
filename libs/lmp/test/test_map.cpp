// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int_list.hpp"
#include "boost/lmp/length.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/take.hpp"
#include "test.hpp"

struct naturals
  : cons<zero,
         map<op_1<succ>,
             naturals> > {};

typedef test< int_list<0, 1, 2, 3>,
              take<int_<4>, naturals> > TEST;

typedef test< int_<50>,
              length<take<int_<50>, naturals> > > TEST;
