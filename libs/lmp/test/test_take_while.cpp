// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"
#include "boost/lmp/range.hpp"
#include "boost/lmp/take_while.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef test< range<int_<-10>, int_<10> >,
              take_while<fn<X,
                            less<X, int_<10> > >,
                         range<int_<-10>,
                               int_<20> > > > TEST;

typedef test< nil,
              take_while<bind_1_of_2<less, int_<100> >,
                         range<int_<-10>,
                               int_<20> > > > TEST;
