#ifndef BOOST_LMP_OP_HPP_VK_20043010
#define BOOST_LMP_OP_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

namespace boost { namespace lmp {

  template<template<class, class, class, class, class> class F, class X0, class X1, class X2, class X3>
  struct bind_4_of_5 {
    typedef bind_4_of_5 eval;

    template<class X4>
    struct with {
      typedef typename F<X0, X1, X2, X3, X4>::eval eval;
    };
  };

  template<template<class, class, class, class, class> class F, class X0, class X1, class X2>
  struct bind_3_of_5 {
    typedef bind_3_of_5 eval;

    template<class X3>
    struct with {
      typedef bind_4_of_5<F, X0, X1, X2, X3> eval;
    };
  };

  template<template<class, class, class, class, class> class F, class X0, class X1>
  struct bind_2_of_5 {
    typedef bind_2_of_5 eval;

    template<class X2>
    struct with {
      typedef bind_3_of_5<F, X0, X1, X2> eval;
    };
  };

  template<template<class, class, class, class, class> class F, class X0>
  struct bind_1_of_5 {
    typedef bind_1_of_5 eval;

    template<class X1>
    struct with {
      typedef bind_2_of_5<F, X0, X1> eval;
    };
  };

  template<template<class, class, class, class, class> class F>
  struct op_5 {
    typedef op_5 eval;

    template<class X0>
    struct with {
      typedef bind_1_of_5<F, X0> eval;
    };
  };

  template<template<class, class, class, class> class F, class X0, class X1, class X2>
  struct bind_3_of_4 {
    typedef bind_3_of_4 eval;

    template<class X3>
    struct with {
      typedef typename F<X0, X1, X2, X3>::eval eval;
    };
  };

  template<template<class, class, class, class> class F, class X0, class X1>
  struct bind_2_of_4 {
    typedef bind_2_of_4 eval;

    template<class X2>
    struct with {
      typedef bind_3_of_4<F, X0, X1, X2> eval;
    };
  };

  template<template<class, class, class, class> class F, class X0>
  struct bind_1_of_4 {
    typedef bind_1_of_4 eval;

    template<class X1>
    struct with {
      typedef bind_2_of_4<F, X0, X1> eval;
    };
  };

  template<template<class, class, class, class> class F>
  struct op_4 {
    typedef op_4 eval;

    template<class X0>
    struct with {
      typedef bind_1_of_4<F, X0> eval;
    };
  };

  template<template<class, class, class> class F, class X0, class X1>
  struct bind_2_of_3 {
    typedef bind_2_of_3 eval;

    template<class X2>
    struct with {
      typedef typename F<X0, X1, X2>::eval eval;
    };
  };

  template<template<class, class, class> class F, class X0>
  struct bind_1_of_3 {
    typedef bind_1_of_3 eval;

    template<class X1>
    struct with {
      typedef bind_2_of_3<F, X0, X1> eval;
    };
  };

  template<template<class, class, class> class F>
  struct op_3 {
    typedef op_3 eval;

    template<class X0>
    struct with {
      typedef bind_1_of_3<F, X0> eval;
    };
  };

  template<template<class, class> class F, class X0>
  struct bind_1_of_2 {
    typedef bind_1_of_2 eval;

    template<class X1>
    struct with {
      typedef typename F<X0, X1>::eval eval;
    };
  };

  template<template<class, class> class F>
  struct op_2 {
    typedef op_2 eval;

    template<class X0>
    struct with {
      typedef bind_1_of_2<F, X0> eval;
    };
  };

  template<template<class> class F>
  struct op_1 {
    typedef op_1 eval;

    template<class X0>
    struct with {
      typedef typename F<X0>::eval eval;
    };
  };

} }

#endif
