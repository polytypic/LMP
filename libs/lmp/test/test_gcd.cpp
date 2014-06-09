// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/gcd.hpp"
#include "test.hpp"

typedef test< int_<3>,
              gcd<int_<6>,
                  int_<9> > > TEST;

typedef test< int_<1>,
              gcd<int_<11>,
                  int_<7> > > TEST;

typedef test< int_<0>,
              gcd<int_<0>,
                  int_<0> > > TEST;
