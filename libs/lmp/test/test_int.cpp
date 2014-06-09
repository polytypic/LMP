// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/int.hpp"
#include "test.hpp"

typedef int_<5> lhs;
typedef int_<-4> rhs;

typedef test< int_<lhs::value % rhs::value>, remainder<lhs, rhs> > TEST;
typedef test< int_<lhs::value * rhs::value>, times    <lhs, rhs> > TEST;
typedef test< int_<lhs::value + rhs::value>, plus     <lhs, rhs> > TEST;
typedef test< int_<lhs::value - rhs::value>, minus    <lhs, rhs> > TEST;
typedef test< int_<lhs::value / rhs::value>, quotient <lhs, rhs> > TEST;

typedef test< bool_< lhs::value != rhs::value >, not_eq_   <lhs, rhs> > TEST;
typedef test< bool_< lhs::value <= rhs::value >, less_eq   <lhs, rhs> > TEST;
typedef test< bool_< lhs::value == rhs::value >, eq        <lhs, rhs> > TEST;
typedef test< bool_< lhs::value >= rhs::value >, greater_eq<lhs, rhs> > TEST;
typedef test< bool_<(lhs::value <  rhs::value)>, less      <lhs, rhs> > TEST;
typedef test< bool_<(lhs::value >  rhs::value)>, greater   <lhs, rhs> > TEST;

typedef test< int_<5>, abs<int_<-5> > > TEST;

typedef test< int_<3>, max<int_<3>, int_<0> > > TEST;
typedef test< int_<1>, min<int_<2>, int_<1> > > TEST;
