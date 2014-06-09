#ifndef BOOST_LMP_COMPOSE_HPP_VK_20043010
#define BOOST_LMP_COMPOSE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

namespace boost { namespace lmp {

  /**
   * `compose<F, G>' returns the composition of the functions `F' and `G'.
   * In other words, `apply<compose<F, G>, X> == apply<F, apply<G, X> >'.
   */
  template<class F, class G>
  struct compose {
    typedef compose<typename F::eval, typename G::eval> eval;

    template<class X>
    struct with {
      typedef typename F::eval::template with<typename G::eval::template with<X>::eval>::eval eval;
    };
  };

} }

#endif
