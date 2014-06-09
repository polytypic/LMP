// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/iterate.hpp"
#include "boost/lmp/reverse.hpp"
#include "boost/lmp/take.hpp"
#include "test.hpp"

typedef test< take<int_<50>,
                   iterate<op_1<pred>, int_<50> > >,
              reverse<take<int_<50>,
                           iterate<op_1<succ>, one> > > > TEST;
