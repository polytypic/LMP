// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/at.hpp"
#include "boost/lmp/box.hpp"
#include "boost/lmp/drop.hpp"
#include "boost/lmp/replicate.hpp"
#include "test.hpp"

typedef verify< is_same<int,
                        at<int_<71>,
                           replicate<int_<1000000000L>,
                                     box<int> > >::eval::type> > TEST;

typedef test< nil,
              drop<int_<19>,
                   replicate<int_<19>, int_<19> > > > TEST;

typedef test< nil,
              replicate<minus<one, one>, one> > TEST;
