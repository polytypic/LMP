// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/any.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/iterate.hpp"
#include "test.hpp"

typedef test< false_,
              any<op_1<is_0>,
                  int_list<1, 2, 3> > > TEST;

typedef test< true_,
              any<op_1<is_0>,
                  iterate<op_1<pred>, int_<40> > > > TEST;
