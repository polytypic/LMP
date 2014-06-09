// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int_list.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/merge.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/take.hpp"
#include "boost/lmp/uniq.hpp"
#include "test.hpp"

// See Exercise 3.56 in SICP. (Note that merge doesn't eliminate duplicates.)
// (http://mitpress.mit.edu/sicp/full-text/book/book-Z-H-24.html#%_sec_3.5)

template<class N, class L>
struct scale
  : map<bind_1_of_2<times, N>, L> {};

struct hamming
  : cons<one,
         uniq<op_2<eq>,
              merge<op_2<less>,
                    scale<int_<2>, hamming>,
                    merge<op_2<less>,
                          scale<int_<3>, hamming>,
                          scale<int_<5>, hamming> > > > > {};

typedef test< int_list<1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, 16>,
              take<int_<12>, hamming> > TEST;
