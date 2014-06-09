// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cond.hpp"
#include "boost/lmp/int.hpp"
#include "test.hpp"

typedef test< int_<2>,
              cond<plus<int_<-1>, int_<3> > > > TEST;

typedef test< one,
              cond<greater<zero, one>,  plus<one, one>,
                   and_<true_, false_>, quotient<one, zero>,
                   one> > TEST;

typedef test< int_<2>,
              cond<and_<false_, true_>, int_<0>,
                   less<one, zero>,     int_<1>,
                   or_<false_, true_>,  int_<2>,
                   false_,              int_<3>,
                   int_<4> > > TEST;
