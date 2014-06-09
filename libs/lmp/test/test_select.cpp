// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/range.hpp"
#include "boost/lmp/select.hpp"
#include "test.hpp"

typedef test< int_<49>,
              select<op_2<greater>,
                     int_<25>,
                     range<int_<1>,
                           int_<50> > > > TEST;

typedef test< int_<1>,
              select<op_2<less>,
                     int_<25>,
                     range<int_<1>,
                           int_<50> > > > TEST;

typedef test< int_<25>,
              select<op_2<less>,
                     int_<25>,
                     range<int_<1>,
                           int_<1> > > > TEST;
