// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/chain.hpp"
#include "boost/lmp/filter.hpp"
#include "boost/lmp/fn.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/iterate.hpp"
#include "boost/lmp/take.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

template<class L>
struct sieve
  : cons<head<L>,
         sieve<filter<fn<X,
                         remainder<X, nf<head<L> > > >,
                      tail<L> > > > {};

struct primes
  : cons<int_<2>,
         sieve<iterate<bind_1_of_2<plus, int_<2> >,
                       int_<3> > > > {};

typedef test< int_list<2, 3, 5, 7, 11, 13, 17, 19, 23, 29>,
              take<int_<10>, primes> > TEST;

typedef test< nil,
              filter<bind_1_of_2<greater, one>,
                     take<int_<5>, primes> > > TEST;

typedef test< nil,
              filter<bind_1_of_2<greater, one>,
                     nil> > TEST;
