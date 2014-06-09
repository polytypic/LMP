// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/compose.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/op.hpp"
#include "test.hpp"

typedef test< int_<-2>,
              apply<compose<op_2<minus>,
                            op_1<pred> >,
                    int_<1>,
                    int_<2> > > TEST;
