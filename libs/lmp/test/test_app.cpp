// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/app.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/op.hpp"
#include "test.hpp"

typedef test< int_<3>,
              app<app<op_2<plus>,
                      int_<1> >,
                  int_<2> > > TEST;
