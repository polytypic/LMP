// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/cycle.hpp"
#include "boost/lmp/length.hpp"
#include "boost/lmp/repeat.hpp"
#include "boost/lmp/replicate.hpp"
#include "boost/lmp/take.hpp"
#include "test.hpp"

typedef test< int_<21>,
              length<take<int_<21>,
                          cycle<replicate<int_<5>,
                                          one> > > > > TEST;

typedef test< int_<20>,
              length<take<int_<20>,
                          cycle<repeat<zero> > > > > TEST;

typedef test< int_<22>,
              length<take<int_<22>,
                          cycle<cycle<repeat<zero> > > > > > TEST;
