// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/box_list.hpp"
#include "boost/lmp/topo_sort.hpp"
#include "boost/lmp/traits.hpp"
#include "test.hpp"

struct a {};
struct b : a {};
struct c : b {};
struct d {};
struct e : d {};
struct f : d {};
struct g : a, e, f {};

typedef test< box_list<c, b, g, a, e, f, d>,
              topo_sort<is_base_of_trait,
                        box_list<a, b, c, d, e, f, g> > > TEST;

typedef test< box_list<g, f, e, d, c, b, a>,
              topo_sort<is_base_of_trait,
                        box_list<g, f, e, d, c, b, a> > > TEST;

typedef test< box_list<g, f, e, d, c, b, a>,
              topo_sort<is_base_of_trait,
                        box_list<d, g, c, f, e, a, b> > > TEST;

typedef test< box_list<c, g, f, e, d, b, a>,
              topo_sort<is_base_of_trait,
                        box_list<c, d, f, e, a, b, g> > > TEST;
