// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/at.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/iterate.hpp"
#include "boost/lmp/op.hpp"
#include "test.hpp"

typedef test< int_<10>,
              at<int_<6>,
                 iterate<op_1<succ>,
                         int_<4> > > > TEST;
