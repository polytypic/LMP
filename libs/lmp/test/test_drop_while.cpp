// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/drop_while.hpp"
#include "boost/lmp/fn.hpp"
#include "boost/lmp/range.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef test< range<int_<10>, int_<20> >,
              drop_while<fn<X,
                            less<X, int_<10> > >,
                         range<int_<-10>,
                               int_<20> > > > TEST;

typedef test< nil,
              drop_while<bind_1_of_2<greater, int_<100> >,
                         range<int_<-10>,
                               int_<20> > > > TEST;
