// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/box_list.hpp"
#include "boost/lmp/concat.hpp"
#include "boost/lmp/fun.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/int_list.hpp"
#include "boost/lmp/list.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef test< int_<-2>,
              apply<fun<X, Y,
                        minus<X, Y> >,
                    int_<3>,
                    int_<5> > > TEST;

typedef test< list<false_>,
              apply<fn<X,
                       list<not_<X> > >,
                    true_> > TEST;

typedef test< list<one, zero>,
              apply<fun<X, Y,
                        apply<fun<A, B,
                                  list<B, A> >,
                              X,
                              Y> >,
                    zero,
                    one> > TEST;

typedef test< list<int_<3>, int_<2>, int_<1>,
                   box<int>, box<float>,
                   int_<5>, int_<6>, int_<7> >,
              apply<fun<X, Y,
                        fun<X, Z,
                            concat<list<list<Z, Y, X>,
                                        box_list<int, float>,
                                        int_list<5, 6, 7> > > > >,
                    int_<-1>,
                    int_<2>,
                    int_<1>,
                    int_<3> > > TEST;
