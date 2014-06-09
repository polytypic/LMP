// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/chain.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/list.hpp"
#include "boost/lmp/op.hpp"
#include "test.hpp"

typedef test< int_<4>,
              apply<chain<op_2<plus>,
                          op_1<neg>,
                          op_1<pred>,
                          op_1<pred>,
                          op_1<head> >,
                    list<one>,
                    int_<3> > > TEST;
