// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/length.hpp"
#include "boost/lmp/range.hpp"
#include "boost/lmp/until.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef test< int_list<7, 8>,
              until_<fn<L,
                        eq<int_<2>, length<L> > >,
                     op_1<tail>,
                     range<int_<-20>, int_<9> > > > TEST;
