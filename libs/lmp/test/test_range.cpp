// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int_list.hpp"
#include "boost/lmp/range.hpp"
#include "test.hpp"

typedef test< int_list<5, 6, 7>,
              range<int_<5>, int_<8> > > TEST;

typedef test< int_list<1, 0, -1, -2>,
              range<int_<2>, int_<-2> > > TEST;

typedef test< nil,
              range<int_<-2>, int_<-2> > > TEST;
