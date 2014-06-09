// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/append.hpp"
#include "boost/lmp/at.hpp"
#include "boost/lmp/drop.hpp"
#include "boost/lmp/length.hpp"
#include "boost/lmp/list.hpp"
#include "boost/lmp/take.hpp"
#include "test.hpp"

struct ones
  : append<list<one>, ones> {};

typedef test< int_<200>,
              length<take<int_<200>, ones> > > TEST;

typedef test< nil,
              append<nil, nil> > TEST;

typedef test< one,
              at<int_<10>,
                 append<ones, ones> > > TEST;
