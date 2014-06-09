// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/flip.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/op.hpp"
#include "test.hpp"

typedef test< int_<2>,
              apply<flip<op_2<minus> >,
                    int_<1>,
                    int_<3> > > TEST;
