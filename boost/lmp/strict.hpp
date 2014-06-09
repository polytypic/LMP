#ifndef BOOST_LMP_STRICT_HPP_VK_20043010
#define BOOST_LMP_STRICT_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/box.hpp"
#include "boost/lmp/fn.hpp"

namespace boost { namespace lmp {

  namespace strict_private {
    template<class T>
    struct strict {
      typedef T eval;
    };

    template<class T>
    struct strict<box<T> > {
      typedef box<T> eval;
    };

    template<class T>
    struct strict<nf<T> > {
      typedef typename strict<typename T::eval>::eval eval;
    };

    template<template<class> class F,
             class X0>
    struct strict<F<X0> > {
      typedef typename F<typename strict<typename X0::eval>::eval>::eval eval;
    };

    template<template<class, class> class F,
             class X0, class X1>
    struct strict<F<X0, X1> > {
      typedef typename F<typename strict<typename X0::eval>::eval,
                         typename strict<typename X1::eval>::eval>::eval eval;
    };

    template<template<class, class, class> class F,
             class X0, class X1, class X2>
    struct strict<F<X0, X1, X2> > {
      typedef typename F<typename strict<typename X0::eval>::eval,
                         typename strict<typename X1::eval>::eval,
                         typename strict<typename X2::eval>::eval>::eval eval;
    };

    template<template<class, class, class, class> class F,
             class X0, class X1, class X2, class X3>
    struct strict<F<X0, X1, X2, X3> > {
      typedef typename F<typename strict<typename X0::eval>::eval,
                         typename strict<typename X1::eval>::eval,
                         typename strict<typename X2::eval>::eval,
                         typename strict<typename X3::eval>::eval>::eval eval;
    };

    template<template<class, class, class, class, class> class F,
             class X0, class X1, class X2, class X3, class X4>
    struct strict<F<X0, X1, X2, X3, X4> > {
      typedef typename F<typename strict<typename X0::eval>::eval,
                         typename strict<typename X1::eval>::eval,
                         typename strict<typename X2::eval>::eval,
                         typename strict<typename X3::eval>::eval,
                         typename strict<typename X4::eval>::eval>::eval eval;
    };

    template<template<class, class, class, class, class, class> class F,
             class X0, class X1, class X2, class X3, class X4, class X5>
    struct strict<F<X0, X1, X2, X3, X4, X5> > {
      typedef typename F<typename strict<typename X0::eval>::eval,
                         typename strict<typename X1::eval>::eval,
                         typename strict<typename X2::eval>::eval,
                         typename strict<typename X3::eval>::eval,
                         typename strict<typename X4::eval>::eval,
                         typename strict<typename X5::eval>::eval>::eval eval;
    };

    template<template<class, class, class, class, class, class, class> class F,
             class X0, class X1, class X2, class X3, class X4, class X5, class X6>
    struct strict<F<X0, X1, X2, X3, X4, X5, X6> > {
      typedef typename F<typename strict<typename X0::eval>::eval,
                         typename strict<typename X1::eval>::eval,
                         typename strict<typename X2::eval>::eval,
                         typename strict<typename X3::eval>::eval,
                         typename strict<typename X4::eval>::eval,
                         typename strict<typename X5::eval>::eval,
                         typename strict<typename X6::eval>::eval>::eval eval;
    };
  }

  template<class T>
  struct strict {
    typedef typename strict_private::strict<typename T::eval>::eval eval;
  };

} }

#endif
