#ifndef BOOST_LMP_BOOL_HPP_VK_20043010
#define BOOST_LMP_BOOL_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

namespace boost { namespace lmp {

  /**
   * `bool_<b>' is a boolean value. Typedefs `true_' and `false_' are
   * provided for convenience.
   */
  template<bool V>
  struct bool_ {
    typedef bool_ eval;
    static const bool value = V;
  };

  typedef bool_<true> true_;
  typedef bool_<false> false_;

  /**
   * `not_<B>' returns the negation of the boolean `B'.
   *
   * Definition:
   *<
   *   template<class B>
   *   struct not_ : if_<B, false_, true_> {};
   *>
   */
  template<class B>
  struct not_ {
    typedef bool_<!B::eval::value> eval;
  };

  /**
   * `if_<B,C,A>' returns the consequent `C' if the condition `B' is
   * `true_' and the alternative `A' if the condition `B' is `false_'.
   */
  template<class B, class C, class A> struct if_               { typedef typename if_<typename B::eval, C, A>::eval eval; };
  template<         class C, class A> struct if_<true_,  C, A> { typedef typename C::eval                           eval; };
  template<         class C, class A> struct if_<false_, C, A> { typedef typename A::eval                           eval; };

  /**
   * `or_<L, R>' return the disjunction of `L' and `R'.
   *
   * Definition:
   *<
   *   template<class L, class R>
   *   struct or_ : if_<L, true_, R> {};
   *>
   */
  template<class L, class R> struct or_  { typedef typename if_<typename L::eval, true_, R>::eval  eval; };

  /**
   * `and_<L, R>' returns the conjunction of `L' and `R'.
   *
   * Definition:
   *<
   *   template<class L, class R>
   *   struct and_ : if_<L, R, false_> {};
   *>
   */
  template<class L, class R> struct and_ { typedef typename if_<typename L::eval, R, false_>::eval eval; };

} }

#endif
