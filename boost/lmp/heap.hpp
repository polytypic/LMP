#ifndef BOOST_LMP_HEAP_HPP_VK_20043010
#define BOOST_LMP_HEAP_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/apply.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/map.hpp"
#include "boost/lmp/nil.hpp"
#include "boost/lmp/op.hpp"
#include "boost/lmp/reduce.hpp"

namespace boost { namespace lmp {

  // NOTE: Go to the bottom first!

  namespace heap_private {
    ////////////////////////////////////////////////////////////////

    template<class LTP, class R>
    struct heap {
      typedef heap eval;

      typedef LTP predicate;
      typedef R root;
    };

    ////////////////////////////////////////////////////////////////

    template<class V, class K, class L, class R>
    struct node {
      typedef node eval;
    };

    ////////////////////////////////////////////////////////////////

    template<class V>
    struct singleton
      : node<V, one, nil, nil> {};

    ////////////////////////////////////////////////////////////////

    template<class T>
    struct node_rank
      : node_rank<typename T::eval> {};

    template<class V, class K, class L, class R>
    struct node_rank<node<V, K, L, R> >
      : K {};

    template<>
    struct node_rank<nil>
      : zero {};

    ////////////////////////////////////////////////////////////////

    template<class V, class L, class R>
    struct node_make
      : if_<less_eq<node_rank<R>, node_rank<L> >,
            node<V, succ<node_rank<R> >, L, R>,
            node<V, succ<node_rank<L> >, R, L> > {};

    ////////////////////////////////////////////////////////////////

    template<class T>
    struct node_value
      : node_value<typename T::eval> {};

    template<class V, class K, class L, class R>
    struct node_value<node<V, K, L, R> >
      : V {};

    ////////////////////////////////////////////////////////////////

    template<class P, class L, class R>
    struct node_merge
      : node_merge<P, typename L::eval, typename R::eval> {};

    template<class P, class L>
    struct node_merge<P, L, nil>
      : L {};

    template<class P, class R>
    struct node_merge<P, nil, R>
      : R {};

    template<class P>
    struct node_merge<P, nil, nil>
      : nil {};

    template<class P,
             class LV, class LK, class LL, class LR,
             class RV, class RK, class RL, class RR>
    struct node_merge<P, node<LV, LK, LL, LR>, node<RV, RK, RL, RR> >
      : if_<apply<P, LV, RV>,
            node_make<LV, LL, node_merge<P, LR, node<RV, RK, RL, RR> > >,
            node_make<RV, RL, node_merge<P, node<LV, LK, LL, LR>, RR> > > {};

    ////////////////////////////////////////////////////////////////

    template<class LTP, class T>
    struct node_pop
      : node_pop<LTP, typename T::eval> {};

    template<class LTP,
             class V, class K, class L, class R>
    struct node_pop<LTP, node<V, K, L, R> >
      : node_merge<LTP, L, R> {};

    ////////////////////////////////////////////////////////////////

    template<class LTP>
    struct heap_empty
      : heap<typename LTP::eval,
             nil> {};

    ////////////////////////////////////////////////////////////////

    template<class LTP,
             class L>
    struct heap_build
      : heap<typename LTP::eval,
             if_<is_nil<L>,
                 nil,
                 head<reduce<bind_1_of_3<node_merge, LTP>,
                             map<op_1<singleton>, L> > > > > {};

    ////////////////////////////////////////////////////////////////

    template<class H>
    struct heap_is_empty
      : is_nil<typename H::eval::root> {};

    ////////////////////////////////////////////////////////////////

    template<class H>
    struct heap_top
      : node_value<typename H::eval::root> {};

    ////////////////////////////////////////////////////////////////

    template<class H>
    struct heap_pop
      : heap<typename H::eval::predicate,
             node_pop<typename H::eval::predicate,
                      typename H::eval::root> > {};

    ////////////////////////////////////////////////////////////////

    template<class H, class V>
    struct heap_push
      : heap<typename H::eval::predicate,
             node_merge<typename H::eval::predicate,
                        singleton<V>,
                        typename H::eval::root> > {};

    ////////////////////////////////////////////////////////////////

    template<class L, class R>
    struct heap_merge
      : heap_merge<typename L::eval, typename R::eval> {};

    template<class LTP, class LT, class RT>
    struct heap_merge<heap<LTP, LT>, heap<LTP, RT> >
      : heap<LTP, node_merge<LTP, LT, RT> > {};

    ////////////////////////////////////////////////////////////////
  }

  // This is the Leftist Heap data structure (a priority queue implementation).

  //////////////////////////////////////////////////////////////////////////////////////////
  //                  Function       // Type                                 // Complexity
  //////////////////////////////////////////////////////////////////////////////////////////
  using heap_private::heap_empty;    // (a -> a -> bool) -> heap a           // O(1)
  using heap_private::heap_is_empty; // heap a -> bool                       // O(1)
  using heap_private::heap_build;    // (a -> a -> bool) -> list a -> heap a // O(n)
  using heap_private::heap_top;      // heap a -> a                          // O(1)
  using heap_private::heap_pop;      // heap a -> heap a                     // O(log n)
  using heap_private::heap_push;     // heap a -> a -> heap a                // O(log n)
  using heap_private::heap_merge;    // heap a -> heap a -> heap a           // O(log n)
  //////////////////////////////////////////////////////////////////////////////////////////

} }

#endif
