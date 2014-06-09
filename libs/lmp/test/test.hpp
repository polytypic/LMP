#ifndef TEST_HPP_VK_20043010
#define TEST_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/bool.hpp"
#include "boost/lmp/strict.hpp"

using namespace boost::lmp; // TBD

template<class L, class R>
struct is_same
  : false_ {};

template<class T>
struct is_same<T, T>
  : true_ {};

template<class T>
struct verify {
  typedef int eval[T::value ? 1 : -1];
};

template<class Expected, class Actual>
struct test
  : verify<is_same<typename strict<Expected>::eval, typename strict<Actual>::eval> > {};

#define TEST ::eval TEST_CAT(test_, __LINE__)
#define TEST_CAT(l, r) TEST_PRIMITIVE_CAT(l, r)
#define TEST_PRIMITIVE_CAT(l, r) l##r

#endif
