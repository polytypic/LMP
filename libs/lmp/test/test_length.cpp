// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/length.hpp"
#include "boost/lmp/repeat.hpp"
#include "boost/lmp/replicate.hpp"
#include "boost/lmp/take.hpp"
#include "test.hpp"

typedef test< zero,
              length<nil> > TEST;

typedef test< int_<99>,
              length<take<int_<99>, repeat<one> > > > TEST;

typedef test< int_<101>,
              length<replicate<int_<101>, one> > > TEST;
