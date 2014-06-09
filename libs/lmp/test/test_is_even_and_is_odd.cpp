// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int.hpp"
#include "test.hpp"

// NOTE: The purpose of this test is to test/show that mutually
// recursive metafunctions are possible. The `is_even_rec' and
// `is_odd_rec' metafunctions aren't very useful as they stand.

template<class I> struct is_even_rec;
template<class I> struct is_odd_rec;

template<class I>
struct is_even_rec
  : if_<less<I, zero>,
        is_odd_rec<succ<I> >,
        and_<not_eq_<one, I>,
             or_<eq<zero, I>,
                 is_odd_rec<pred<I> > > > > {};

template<class I>
struct is_odd_rec
  : if_<less<I, zero>,
        is_even_rec<succ<I> >,
        and_<not_eq_<zero, I>,
             or_<eq<one, I>,
                 is_even_rec<pred<I> > > > > {};

typedef test< false_, is_even_rec<int_<-9> > > TEST;
typedef test< false_, is_even_rec<int_<9> > > TEST;
typedef test< false_, is_odd_rec<int_<-10> > > TEST;
typedef test< false_, is_odd_rec<int_<10> > > TEST;
typedef test< true_,  is_even_rec<int_<-10> > > TEST;
typedef test< true_,  is_even_rec<int_<10> > > TEST;
typedef test< true_,  is_odd_rec<int_<-9> > > TEST;
typedef test< true_,  is_odd_rec<int_<9> > > TEST;
