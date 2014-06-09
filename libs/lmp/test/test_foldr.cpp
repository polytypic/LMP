// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/foldr.hpp"
#include "boost/lmp/iterate.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/take.hpp"
#include "test.hpp"

struct naturals
  : iterate<op_1<succ>, zero> {};

typedef test< int_<(49*50)/2>,
              foldr<op_2<plus>, take<int_<50>, naturals>, zero> > TEST;
