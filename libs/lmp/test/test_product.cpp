// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/product.hpp"
#include "boost/lmp/range.hpp"
#include "test.hpp"

typedef test< int_<3*4*5>,
              product<range<int_<3>, int_<6> > > > TEST;

typedef test< one,
              product<range<int_<7>, int_<7> > > > TEST;
