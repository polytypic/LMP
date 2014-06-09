// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/box.hpp"
#include "test.hpp"

typedef verify< is_same<box<int>,
                        box<int>::eval> > TEST;

typedef verify< is_same<int,
                        box<int>::type> > TEST;
