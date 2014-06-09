// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/box_list.hpp"
#include "boost/lmp/list.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/traits.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

typedef test< box_list<char, int, double>,
              apply<function_arg_types_trait,
                    box<short (char, int, double)> > > TEST;

typedef test< box<short>,
              apply<function_result_type_trait,
                    box<short (char, int, double)> > > TEST;

typedef test< box_list<T**, U*>,
              map<add_pointer_trait,
                  box_list<T*, U> > > TEST;

typedef test< list<false_, true_>,
              map<is_pointer_trait,
                  box_list<T, U*> > > TEST;

typedef test< int_<3>,
              apply<rank_trait,
                    box<double[2][3][4]> > > TEST;

typedef test< int_<0>,
              remainder<apply<alignment_of_trait,
                              apply<aligned_storage_trait,
                                    int_<sizeof(int)> > >,
                        int_<sizeof(int)> > > TEST;

typedef test< int_<2>,
              apply<extent_trait,
                    box<double[3][2][4]>,
                    int_<1> > > TEST;
