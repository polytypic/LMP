// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"
#include "boost/lmp/int.hpp"
#include "test.hpp"

typedef test< true_,
              or_<and_<true_, true_>,
                  void> > TEST;

typedef test< false_,
              and_<or_<false_, false_>,
                   void> > TEST;

typedef test< one,
              if_<false_, void, one> > TEST;

typedef test< one,
              if_<true_, one, void> > TEST;
