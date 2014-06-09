#ifndef BOOST_LMP_QUEUE_HPP_VK_20043010
#define BOOST_LMP_QUEUE_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/let.hpp"
#include "boost/lmp/nil.hpp"
#include "boost/lmp/pair.hpp"
#include "boost/lmp/reverse.hpp"
#include "boost/lmp/strict.hpp"
#include "boost/lmp/var.hpp"

namespace boost { namespace lmp {

  // NOTE: Go to the bottom first!

  namespace queue_private {
    ////////////////////////////////////////////////////////////////

    template<class F, class B>
    struct queue {
      typedef queue eval;

      typedef F front;
      typedef B back;
    };

    ////////////////////////////////////////////////////////////////

    typedef queue<nil, nil> queue_empty;

    ////////////////////////////////////////////////////////////////

    template<class F, class B>
    struct queue_norm
      : if_<is_nil<F>,
            queue<reverse<B>, nil>,
            queue<F, B> > {};

    ////////////////////////////////////////////////////////////////

    template<class Q>
    struct queue_is_empty
      : is_nil<typename Q::eval::front> {};

    ////////////////////////////////////////////////////////////////

    template<class Q, class V>
    struct queue_push
      : queue_norm<typename Q::eval::front,
                   cons<V, typename Q::eval::back> > {};

    ////////////////////////////////////////////////////////////////

    template<class Q>
    struct queue_pop
      : queue_norm<tail<typename Q::eval::front>,
                   typename Q::eval::back>  {};

    ////////////////////////////////////////////////////////////////

    template<class Q>
    struct queue_top
      : head<typename Q::eval::front> {};

    ////////////////////////////////////////////////////////////////
  }

  ///////////////////////////////////////////////////////////////////////////////////////////
  //                   Function        // Type                    // Complexity (amortized)
  ///////////////////////////////////////////////////////////////////////////////////////////
  using queue_private::queue_empty;    // queue a                 // <constant>
  using queue_private::queue_is_empty; // queue a -> bool         // O(1)
  using queue_private::queue_push;     // queue a -> a -> queue a // O(1)
  using queue_private::queue_pop;      // queue a -> queue a      // O(1)
  using queue_private::queue_top;      // queue a -> a            // O(1)
  ///////////////////////////////////////////////////////////////////////////////////////////

} }

#endif
