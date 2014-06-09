#ifndef BOOST_LMP_INT_HPP_VK_20043010
#define BOOST_LMP_INT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"

namespace boost { namespace lmp {

  typedef long int_type;

  template<int_type V>
  struct int_ {
    typedef int_ eval;
    static const int_type value = V;
  };

  typedef int_<0> zero;
  typedef int_<1> one;

  template<class I> struct is_0   { typedef bool_<(0 == I::eval::value)> eval; };
  template<class I> struct isnt_0 { typedef bool_<(0 != I::eval::value)> eval; };

  template<class I> struct is_even { typedef bool_<(0 == I::eval::value % 2)> eval; };
  template<class I> struct is_odd  { typedef bool_<(0 != I::eval::value % 2)> eval; };

  template<class L, class R> struct eq         { typedef bool_<(L::eval::value == R::eval::value)> eval; };
  template<class L, class R> struct greater_eq { typedef bool_<(L::eval::value >= R::eval::value)> eval; };
  template<class L, class R> struct greater    { typedef bool_<(L::eval::value >  R::eval::value)> eval; };
  template<class L, class R> struct less_eq    { typedef bool_<(L::eval::value <= R::eval::value)> eval; };
  template<class L, class R> struct less       { typedef bool_<(L::eval::value <  R::eval::value)> eval; };
  template<class L, class R> struct not_eq_    { typedef bool_<(L::eval::value != R::eval::value)> eval; };

  template<class I> struct neg { typedef int_<(-I::eval::value)> eval; };
  template<class I> struct abs { typedef int_<(I::eval::value < 0 ? -I::eval::value : I::eval::value)> eval; };

  template<class I> struct pred { typedef int_<(I::eval::value - 1)> eval; };
  template<class I> struct succ { typedef int_<(I::eval::value + 1)> eval; };

  template<class L, class R> struct plus      { typedef int_<(L::eval::value + R::eval::value)> eval; };
  template<class L, class R> struct minus     { typedef int_<(L::eval::value - R::eval::value)> eval; };
  template<class L, class R> struct times     { typedef int_<(L::eval::value * R::eval::value)> eval; };
  template<class L, class R> struct quotient  { typedef int_<(L::eval::value / R::eval::value)> eval; };
  template<class L, class R> struct remainder { typedef int_<(L::eval::value % R::eval::value)> eval; };

  template<class L, class R> struct min { typedef int_<(R::eval::value < L::eval::value ? R::eval::value : L::eval::value)> eval; };
  template<class L, class R> struct max { typedef int_<(L::eval::value < R::eval::value ? R::eval::value : L::eval::value)> eval; };

} }

#endif
