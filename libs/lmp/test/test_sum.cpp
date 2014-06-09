// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/range.hpp"
#include "boost/lmp/sum.hpp"
#include "test.hpp"

typedef test< int_<5+4+3>,
              sum<range<int_<6>,
                        int_<3> > > > TEST;

typedef test< zero,
              sum<range<int_<-30>,
                        int_< 31> > > > TEST;
