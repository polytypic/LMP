// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/fn.hpp"
#include "boost/lmp/foldl.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/iterate.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/queue.hpp"
#include "boost/lmp/take_until.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef int_list<3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9> pi_digits;

typedef test< pi_digits,
              map<op_1<queue_top>,
                  take_until<op_1<queue_is_empty>,
                             iterate<op_1<queue_pop>,
                                     foldl<op_2<queue_push>,
                                           queue_empty,
                                           pi_digits> > > > > TEST;
