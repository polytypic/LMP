// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/at.hpp"
#include "boost/lmp/drop.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/replicate.hpp"
#include "boost/lmp/take.hpp"
#include "boost/lmp/zip_with.hpp"
#include "test.hpp"

// `fibs' is the list of all Fibonacci numbers (less than LONG_MAX,
// of course). (This is definitely not the optimal way to define a
// list of Fibonacci numbers.)
struct fibs
  : cons<zero,
         cons<one,
              zip_with<op_2<plus>, tail<fibs>, fibs> > > {};

typedef test< int_list<0, 1, 1, 2, 3,
                       5, 8, 13, 21, 34>,
              take<int_<10>, fibs> > TEST;

typedef test< int_<102334155>,
              at<int_<40>, fibs> > TEST;

typedef test< nil,
              zip_with<op_2<plus>,
                       nil,
                       fibs> > TEST;

typedef test< int_list<1, 2, 2>,
              zip_with<op_2<plus>,
                       fibs,
                       replicate<int_<3>, one> > > TEST;

typedef test< int_list<1, 1, 1>,
              zip_with<op_2<minus>,
                       replicate<int_<3>, int_<-1> >,
                       replicate<int_<3>, int_<-2> > > > TEST;
