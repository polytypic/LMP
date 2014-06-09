// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/box.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/range.hpp"
#include "test.hpp"

typedef test< int_list<1, 2, 3>,
              range<int_<1>, int_<4> > > TEST;

typedef test< box<int>,
              or_<false_,
                  box<int> > > TEST;
