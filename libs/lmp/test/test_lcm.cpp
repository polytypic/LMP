// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/lcm.hpp"
#include "test.hpp"

typedef test< int_<24>,
              lcm<int_<8>,
                  int_<6> > > TEST;
