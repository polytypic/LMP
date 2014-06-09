// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"
#include "boost/lmp/error.hpp"
#include "test.hpp"

struct an_error {};

typedef test< true_,
              if_<false_,
                  error<an_error>,
                  true_> > TEST;
