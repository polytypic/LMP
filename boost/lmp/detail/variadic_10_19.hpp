// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#if FROM <= 10 && 10 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr> expr;
};
#endif

#if FROM <= 11 && 11 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr> expr;
};
#endif

#if FROM <= 12 && 12 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr> expr;
};
#endif

#if FROM <= 13 && 13 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr> expr;
};
#endif

#if FROM <= 14 && 14 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12, class X13,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr, typename subst<X13, T, V>::expr> expr;
};
#endif

#if FROM <= 15 && 15 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12, class X13, class X14,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr, typename subst<X13, T, V>::expr, typename subst<X14, T, V>::expr> expr;
};
#endif

#if FROM <= 16 && 16 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12, class X13, class X14, class X15,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr, typename subst<X13, T, V>::expr, typename subst<X14, T, V>::expr, typename subst<X15, T, V>::expr> expr;
};
#endif

#if FROM <= 17 && 17 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12, class X13, class X14, class X15, class X16,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr, typename subst<X13, T, V>::expr, typename subst<X14, T, V>::expr, typename subst<X15, T, V>::expr, typename subst<X16, T, V>::expr> expr;
};
#endif

#if FROM <= 18 && 18 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12, class X13, class X14, class X15, class X16, class X17,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr, typename subst<X13, T, V>::expr, typename subst<X14, T, V>::expr, typename subst<X15, T, V>::expr, typename subst<X16, T, V>::expr, typename subst<X17, T, V>::expr> expr;
};
#endif

#if FROM <= 19 && 19 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12, class X13, class X14, class X15, class X16, class X17, class X18,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr, typename subst<X13, T, V>::expr, typename subst<X14, T, V>::expr, typename subst<X15, T, V>::expr, typename subst<X16, T, V>::expr, typename subst<X17, T, V>::expr, typename subst<X18, T, V>::expr> expr;
};
#endif

#if FROM <= 20 && 20 <= TO
template<class X0, class X1, class X2, class X3, class X4, class X5, class X6, class X7, class X8, class X9, class X10, class X11, class X12, class X13, class X14, class X15, class X16, class X17, class X18, class X19,
         class T, class V>
struct subst<F<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16, X17, X18, X19>,
             T, V> {
  typedef F<typename subst<X0, T, V>::expr, typename subst<X1, T, V>::expr, typename subst<X2, T, V>::expr, typename subst<X3, T, V>::expr, typename subst<X4, T, V>::expr, typename subst<X5, T, V>::expr, typename subst<X6, T, V>::expr, typename subst<X7, T, V>::expr, typename subst<X8, T, V>::expr, typename subst<X9, T, V>::expr, typename subst<X10, T, V>::expr, typename subst<X11, T, V>::expr, typename subst<X12, T, V>::expr, typename subst<X13, T, V>::expr, typename subst<X14, T, V>::expr, typename subst<X15, T, V>::expr, typename subst<X16, T, V>::expr, typename subst<X17, T, V>::expr, typename subst<X18, T, V>::expr, typename subst<X19, T, V>::expr> expr;
};
#endif

#if FROM > 20 || TO > 20
#error "Repetition range too high."
#endif
