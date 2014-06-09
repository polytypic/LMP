// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/all.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/iterate.hpp"
#include "test.hpp"

typedef test< true_,
              all<op_1<isnt_0>,
                  int_list<1, 2, 3> > > TEST;

typedef test< false_,
              all<op_1<isnt_0>,
                  iterate<op_1<pred>, int_<40> > > > TEST;
