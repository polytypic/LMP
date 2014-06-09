// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

# include "boost/lmp/int.hpp"

using namespace boost::lmp;

// ## Two factorials
//
// In this tutorial example, we'll look at two Lazy TMP implementations of
// the factorial function $n!$. The first one is a straightforward
// implementation that is easy to read as well as write. The second one is
// an optimized implementation that takes advantage of the strictness
// inherent in the computation of the factorial function.
//
// Before we go meta, let's take a look at a recursive run-time
// implementation of the factorial function:
//<
int_type fact(int_type n) {
  return 0 == n
    ? 1
    : n * fact(n - 1);
}
//>
// Using Lazy TMP, we can translate the above recursive factorial into a
// template metaprogram rather easily. All we have to do is to
// \begin{itemize}
// \item replace uses of operators (`0 ==', `? :', `*' and `- 1') with
//       calls to appropriate metafunctions (`is_0', `if_', `times', and
//       `pred'),
// \item replace `return' with inheritance `:', and
// \item remove the type annotations (`int_type'),
// \end{itemize}
// while we write the template definition.
//
// ### The ordinary implementation
//
// The following `ord_fact' metafunction is a straightforward translation
// of the previous `fact' function.
//<
template<class N>
struct ord_fact
  : if_<is_0<N>,
        one,
        times<N, ord_fact<pred<N> > > > {};
//>
// We call the above metafunction the \emph{ordinary} implementation,
// because it uses the ``ordinary'' programming style in Lazy TMP.
// Ordinarily, a Lazy TMP metafunction is just a straightforward
// translation of an algorithm to a purely functional form.
//
// Like in purely functional programming in general, we can read the above
// definition of the `ord_fact' metafunction as an equation:
//<
//   ord_fact<n> = if_<is_0<n>,
//                     one,
//                     times<n, ord_fact<pred<n>>>>
//>
// The equation says that we can replace an instance of the left hand side
// pattern `ord_fact<n>' with an instance of the right hand side pattern
// `if_<...>', and vice versa, in any context without changing the meaning
// of the expression.
//
// Programming in Lazy TMP corresponds to programming in a lazy and
// untyped purely functional programming language. We say that Lazy TMP is
// \begin{description}
// \item [lazy], because in Lazy TMP an actual parameter to a function is
//       evaluated only if the evaluation of the function body requires
//       evaluation of the parameter. As a consequence, we don't need a
//       separation between control structures (e.g. `if_') and functions
//       (e.g. `times').
// \item [purely functional], because in Lazy TMP there is no state that
//       could be modified by assignment. Functions correspond to
//       mathematical functions.
// \item [untyped], because formal parameters are not declared with a type
//       nor are the types of actual parameters checked in any way before
//       a function application is performed. Type related errors, such as
//       passing a list instead of an integer to the factorial function,
//       are not detected until the erroneous call is actually evaluated.
// \end{description}
// The correspondence makes it easier to understand programming in Lazy
// TMP. Understanding Lazy TMP is roughly the same as understanding lazy
// purely functional programming. The latter is a fairly well understood
// paradigm of programming and you can find many introductory level books
// on it (e.g. \cite{thompson:1999, rabhi:1999}).
//
// ### Lazy evaluation of functions
//
// Although the previous `ord_fact' metafunction works correctly, it may
// behave inefficiently. The evaluation of a lazy metaprogram may
// effectively build large and complicated types whose representation may
// take a significant amount of space and whose manipulation by a C++
// compiler may take considerable time. The complicated types are the
// expressions built during the evaluation of the program. We can
// understand this precisely by using \emph{equational reasoning}.
//
// Let's see how the evaluation of an invocation of the expression
//<
//     ord_fact<int_<2>>
//>
// proceeds. By the definition of `ord_fact' and an understanding of `if_'
// (we'll ignore the implementation details of `if_' and other primitive
// metafunctions) we can simplify the above expression:
//<
//     ord_fact<int_<2>>
//   = if_<is_0<int_<2>>,
//         int_<1>,
//         times<int_<2>,
//               ord_fact<pred<int_<2>>>>>
//   = times<int_<2>, ord_fact<pred<int_<2>>>>
//>
// We can then use the definitions again to simplify the subexpression
// `ord_fact<pred<int_<2>>>':
//<
//     ord_fact<pred<int_<2>>>
//   = if_<is_0<pred<int_<2>>>,
//         int_<1>,
//         times<pred<int_<2>>,
//               ord_fact<pred<pred<int_<2>>>>>>
//   = times<pred<int_<2>>, ord_fact<pred<pred<int_<2>>>>>
//>
// And again to simplify `ord_fact<pred<pred<int_<2>>>>':
//<
//     ord_fact<pred<pred<int_<2>>>>
//   = if_<is_0<pred<pred<int_<2>>>>,
//         int_<1>,
//         times<pred<pred<int_<2>>>,
//               ord_fact<pred<pred<pred<int_<2>>>>>>>
//   = int_<1>
//>
// At this point we have arrived at the \emph{value} `int_<1>', which can
// not be simplified further. To complete the trace, we should substitute
// the result
//<
//   int_<1>
//>
// for
//<
//   ord_fact<pred<pred<int_<2>>>>
//>
// and so on until we arrive at the solution to the original equation
// `ord_fact<int_<2>>'. We'll leave it as an exercise to the reader.
//
// The above chains of equations, plus the substitution left as an
// exercise, effectively trace the evaluation of the expression
// `ord_fact<int_<2>>'. Concretely, we can translate the above chains of
// equations into the types built during the evaluation of
// `ord_fact<int_<2>>'. Below is a presentation of the types using the
// notation `A : B' to denote that `A' is inherited from `B'.
//<
//     ord_fact<int_<2>>
//   : if_<is_0<int_<2>>,
//         int_<1>,
//         times<int_<2>,
//               ord_fact<pred<int_<2>>>>>
//   : times<int_<2>, ord_fact<pred<int_<2>>>>
//   : int_<2>
//
//     ord_fact<pred<int_<2>>>
//   : if_<is_0<pred<int_<2>>>,
//         int_<1>,
//         times<pred<int_<2>>,
//               ord_fact<pred<pred<int_<2>>>>>>
//   : times<pred<int_<2>>, ord_fact<pred<pred<int_<2>>>>>
//   : int_<1>
//
//     ord_fact<pred<pred<int_<2>>>>
//   : if_<is_0<pred<pred<int_<2>>>>,
//         int_<1>,
//         times<pred<pred<int_<2>>>,
//               ord_fact<pred<pred<pred<int_<2>>>>>>>
//   : int_<1>
//>
// Also, we should not forget that all the subexpression above, such as
//<
//   pred<int_<2>>
//>
// and
//<
//   times<int_<2>>,
//         ord_fact<int_<2>>>
//>
// are also types. The following presents the structure of the rest of the
// types actually evaluated during the evaluation of `ord_fact<int_<2>>':
//<
//   pred<int_<2>> : int_<1>
//   pred<pred<int_<2>>> : int_<0>
//
//   is_0<int_<2>> : false_
//   is_0<pred<int_<2>>> : false_
//   is_0<pred<pred<int_<2>>> : true_
//
//   times<int_<2>,
//         ord_fact<pred<int_<2>>>> : int_<2>
//   times<pred<int_<2>>,
//         ord_fact<pred<pred<int_<2>>>>> : int_<1>
//>
// Ignoring the implementation details of `if_' and other primitive
// metafunctions, as well as the structure of unevaluated expressions,
// like
//<
//   pred<pred<pred<int_<2>>>>,
//>
// the above is a complete presentation of the evaluation of
// `ord_fact<int_<2>>'.
//
// ### An optimized implementation
//
// We can optimize the factorial function by taking advantage of the
// strictness inherent in the computation of factorials. After the
// evaluation of the given actual parameter, the evaluation of the
// factorial can proceed in a completely strict fashion. This avoids the
// buildup of complicated expressions.
//
// We'll first define the ``lazy case'' of the `opt_fact' metafunction:
//<
template<class N>
struct opt_fact
  : opt_fact<int_<N::eval::value> >::eval {};
//>
// The above effectively forces the evaluation of the parameter `n' given
// to `opt_fact' and then reverts the evaluation to some other case
// (specialization) of the `opt_fact' template, which we'll define below.
// We can force the evaluation safely, because the factorial function
// \emph{always} has to examine the value of the only parameter it is
// given.
//
// A parameter that always needs to be evaluated is called \emph{strict}
// and the function is said to be \emph{strict in the parameter}. In
// general, however, a lazy metafunction can't simply force the evaluation
// of all the parameters it is given. The determination of which
// parameters are strict and which aren't is called \emph{strictness
// analysis}. It is possible to give algorithms for strictness analysis,
// but all such algorithms will be incomplete in the sense that they do
// not find \emph{all} the strict parameters. The incompleteness is
// explained by the fact that complete strictness analysis would solve the
// halting problem, which is known to be undecidable.
//
// We then need to define the ``strict cases'' of the `opt_fact'
// metafunction. First the recursive case:
//<
template<int_type N>
struct opt_fact<int_<N> >
  : int_<N * opt_fact<int_<N-1> >::eval::value> {};
//>
// The recursive case takes advantage of the strictness by forcing the
// evaluation of the recursive call immediately. The last case is the base
// case of the recursion:
//<
template<>
struct opt_fact<zero>
  : one {};
//>
// This completes the implementation of the optimized factorial
// metafunction `opt_fact'.
//
// ### Evaluation of optimized lazy metafunctions
//
// To understand why `opt_fact' might be more efficient than `ord_fact' we
// can use equational reasoning to simplify the expression
// `opt_fact<succ<one>>'. We use the actual parameter `succ<one>' instead
// of `int_<2>' to show how the lazy case behaves. First we'll simplify
// `opt_fact<succ<int_<1>>>':
//<
//     opt_fact<succ<int_<1>>>
//   = opt_fact<int_<succ<int_<1>>::eval::value>>::eval
//>
// At this point we note that `succ<int_<1>>::eval::value = 2' and
// continue with `opt_fact<int_<2>>':
//<
//     opt_fact<int_<2>>
//   = int_<2 * opt_fact<int_<2-1>>::eval::value>
//>
// Noting that `2 - 1 = 1' we continue with `opt_fact<int_<1>>':
//<
//     opt_fact<int_<1>>
//   = int_<1 * opt_fact<int_<1-1>>::eval::value>
//>
// Noting that `1 - 1 = 0' we arrive at the base case
// `opt_fact<int_<0>>':
//<
//     opt_fact<int_<0>>
//   = int_<1>
//>
// We could now substitute back the results and build a representation of
// the evaluated types. However, it should be quite obvious that the
// evaluation of `opt_fact<succ<int_<1>>>' builds far fewer and far
// simpler types than the evaluation of `ord_fact<int_<2>>'. Complex type
// expressions like
//<
//   is_0<pred<pred<int_<2>>>
//>
// and
//<
//   times<pred<int_<2>>,
//         ord_fact<pred<pred<int_<2>>>>>
//>
// are never built by the `opt_fact' metafunction. This is the reason why
// the `opt_fact' metafunction may be evaluated more efficiently than the
// `ord_fact' metafunction.
//
// Safe optimizations, like the ones used in the `opt_fact' metafunction,
// do not change the way a metafunction is used. Both the `ord_fact' and
// the `opt_fact' templates implement the same metafunction. In
// particular, users of either implementation do not need to explicitly
// evaluate the actual parameter they give to the metafunction. The
// metafunctions take internally care of evaluating their parameters when
// appropriate.
//
// Optimizations, that definitely complicate the implementation of lazy
// metafunctions, are only necessary when a metaprogram would evaluate too
// inefficiently without them. In practise, a library of carefully
// optimized higher-order metafunctions should be able to eliminate the
// need to optimize most of the metafunctions built on top of the
// optimized higher-order metafunctions.
//
// ### Demonstration
//
// As a final measure, let's write a simple ad hoc demonstration of the
// use of the factorial metafunctions.
//<
#include <iostream>

int main() {
  std::cout << "    fact: " <<          fact(8)                << '\n';
  std::cout << "ord_fact: " << ord_fact<int_<8> >::eval::value << '\n';
  std::cout << "opt_fact: " << opt_fact<int_<8> >::eval::value << '\n';
}
//>
// If everything goes well, all the factorial functions agree on the
// result. Of couse, the above is nothing like an exhaustive test of the
// metafunctions.
//
// ### Summary
//
// We have seen two Lazy TMP implementations of the factorial function.
// Both implementations compute the same function, but the optimized
// version can be significantly faster, because it builds fewer and less
// complicated types during evaluation. Optimization is only needed when a
// metaprogram would otherwise be too slow.
//
// We can understand the behavior of Lazy TMP metaprograms by using
// equational reasoning. Lazy TMP corresponds to programming in a lazy and
// untyped purely functional language. Purely functional programming is a
// fairly well understood paradigm of programming. The correspondence
// between Lazy TMP and lazy functional programming makes it easier to
// understand Lazy TMP.
