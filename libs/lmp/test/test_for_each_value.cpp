// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/for_each_value.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/iterate.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/take_while.hpp"
#include "boost/lmp/zip_with.hpp"
#include "test.hpp"
#include <iostream>

struct naturals
  : iterate<op_1<succ>, one> {};

template<class L>
struct partial_sums
  : if_<is_nil<L>,
        nil,
        cons<head<L>,
             zip_with<op_2<plus>,
                      tail<L>,
                      partial_sums<L> > > > {};

template<class T>
void put_to_cout(T x) {
  std::cout << x << '\n';
}

typedef take_while<bind_1_of_2<greater, int_<100> >,
                   partial_sums<naturals> > sums;

int main() {
  for_each_value<sums>(put_to_cout<int_type>);
}
