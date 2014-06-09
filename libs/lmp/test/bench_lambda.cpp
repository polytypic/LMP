// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/lmp/app.hpp"
#include "boost/lmp/fn.hpp"
#include "boost/lmp/var.hpp"
#include "test.hpp"

namespace {
  typedef fn<X, X> id;
  typedef fn<T, fn<F, T> > true_;
  typedef fn<T, fn<F, F> > false_;
  typedef fn<L, fn<M, fn<N, app<app<L, M>, N> > > > test_;
  typedef fn<B, fn<C, app<app<B, C>, false_> > > and_;
  typedef fn<B, fn<C, app<app<B, true_>, C> > > or_;
  typedef fn<B, app<app<B, false_>, true_> > not_;
  typedef fn<F, fn<S, fn<B, app<app<B, F>, S> > > > pair;
  typedef fn<P, app<P, true_> > fst;
  typedef fn<P, app<P, false_> > snd;
  typedef fn<S, fn<Z, Z> > c0;
  typedef fn<S, fn<Z, app<S, Z> > > c1;
  typedef fn<S, fn<Z, app<S, app<S, Z> > > > c2;
  typedef fn<S, fn<Z, app<S, app<S, app<S, Z> > > > > c3;
  typedef fn<S, fn<Z, app<S, app<S, app<S, app<S, Z> > > > > > c4;
  typedef fn<S, fn<Z, app<S, app<S, app<S, app<S, app<S, Z> > > > > > > c5;
  typedef fn<N, fn<S, fn<Z, app<S, app<app<N, S>, Z> > > > > succ;
  typedef fn<M, fn<N, fn<S, fn<Z, app<app<M, S>, app<app<N, S>, Z> > > > > > plus;
  typedef fn<M, fn<N, app<app<M, app<plus, N> >, c0> > > times;
  typedef fn<M, fn<N, app<M, N> > > power;
  typedef fn<M, app<app<M, fn<X, false_> >, true_> > is_zero;
  typedef app<app<pair, c0>, c0> zz;
  typedef fn<P, app<app<pair, app<snd, P> >, app<app<plus, c1>, app<snd, P> > > > ss;
  typedef fn<M, app<fst, app<app<M, ss>, zz> > > pred;
  typedef fn<M, fn<N, app<app<N, pred>, M> > > minus;
  typedef fn<M, fn<N, app<app<and_, app<is_zero, app<app<M, pred>, N> > >,
                          app<is_zero, app<app<N, pred>, M> > > > > equal;

  typedef test< true_,
                app<app<equal,
                        app<app<minus, app<app<times, c4>, c4> >,
                            app<app<power, c2>, c4> > >, c0> > TEST;
}
