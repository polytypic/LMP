// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/list.hpp"
#include "boost/lmp/range.hpp"
#include "boost/lmp/reduce.hpp"
#include "test.hpp"

typedef test< list<cons<cons<int_<5>, int_<6> >,
                        cons<int_<7>, int_<8> > > >,
              reduce<op_2<cons>,
                     range<int_<5>, int_<9> > > > TEST;

typedef test< nil,
              reduce<op_2<times>,
                     nil> > TEST;
