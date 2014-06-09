#ifndef BOOST_LMP_TRAITS_HPP_VK_20043010
#define BOOST_LMP_TRAITS_HPP_VK_20043010

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#include "boost/type_traits.hpp"

#include "boost/lmp/box.hpp"
#include "boost/lmp/cons.hpp"
#include "boost/lmp/int.hpp"
#include "boost/lmp/nil.hpp"

#include <cstddef>

namespace boost { namespace lmp {

  // value traits

  template<class T, template<T> class V, template<class> class F>
  struct value_trait_1 {
    typedef value_trait_1 eval;

    template<class X0>
    struct with {
      typedef V<F<typename X0::eval::type>::value> eval;
    };
  };

  template<class T, template<T> class V, template<class, class> class F, class X0>
  struct value_trait_bind_1_of_2 {
    typedef value_trait_bind_1_of_2 eval;

    template<class X1>
    struct with {
      typedef V<F<X0, typename X1::eval::type>::value> eval;
    };
  };

  template<class T, template<T> class V, template<class, class> class F>
  struct value_trait_2 {
    typedef value_trait_2 eval;

    template<class X0>
    struct with {
      typedef value_trait_bind_1_of_2<T, V, F, typename X0::eval::type> eval;
    };
  };

  // type traits

  template<template<class> class F>
  struct type_trait_1 {
    typedef type_trait_1 eval;

    template<class X0>
    struct with {
      typedef box<typename F<typename X0::eval::type>::type> eval;
    };
  };

  // traits (TBD: Support all Boost Type Traits)

  struct function_result_type_trait {
    typedef function_result_type_trait eval;

    template<class X0>
    struct with {
      typedef box<typename function_traits<typename X0::eval::type>::result_type> eval;
    };
  };

  namespace traits_private {
    template<int I, class FT>
    struct get_arg_type {};

    template<class FT> struct get_arg_type<0, FT> { typedef box<typename FT::arg1_type> eval; };
    template<class FT> struct get_arg_type<1, FT> { typedef box<typename FT::arg2_type> eval; };
    template<class FT> struct get_arg_type<2, FT> { typedef box<typename FT::arg3_type> eval; };
    template<class FT> struct get_arg_type<3, FT> { typedef box<typename FT::arg4_type> eval; };
    template<class FT> struct get_arg_type<4, FT> { typedef box<typename FT::arg5_type> eval; };
    template<class FT> struct get_arg_type<5, FT> { typedef box<typename FT::arg6_type> eval; };
    template<class FT> struct get_arg_type<6, FT> { typedef box<typename FT::arg7_type> eval; };
    template<class FT> struct get_arg_type<7, FT> { typedef box<typename FT::arg8_type> eval; };
    template<class FT> struct get_arg_type<8, FT> { typedef box<typename FT::arg9_type> eval; };

    template<int I, int N, class FT>
    struct arg_types {
      typedef cons<typename get_arg_type<I, FT>::eval,
                   typename arg_types<I+1, N, FT>::eval> eval;
    };

    template<int N, class FT>
    struct arg_types<N, N, FT> {
      typedef nil eval;
    };
  }

  struct function_arg_types_trait {
    typedef function_arg_types_trait eval;

    template<class X0>
    struct with {
      typedef typename traits_private::arg_types<0,
                                                 function_traits<typename X0::eval::type>::arity,
                                                 function_traits<typename X0::eval::type> >::eval eval;
    };
  };
 
  // TBD: type_with_alignment<?>

  struct aligned_storage_trait {
    typedef aligned_storage_trait eval;

    template<class X0>
    struct with {
      typedef box<typename aligned_storage<X0::eval::value>::type> eval;
    };
  };

  template<class X0>
  struct extent_trait_bind_1_of_2 {
    typedef extent_trait_bind_1_of_2<X0> eval;

    template<class X1>
    struct with {
      typedef int_<extent<typename X0::eval::type, X1::eval::value>::value> eval;
    };
  };

  struct extent_trait {
    typedef extent_trait eval;

    template<class X0>
    struct with {
      typedef extent_trait_bind_1_of_2<X0> eval;
    };
  };

  typedef type_trait_1<add_const> add_const_trait;
  typedef type_trait_1<add_cv> add_cv_trait;
  typedef type_trait_1<add_pointer> add_pointer_trait;
  typedef type_trait_1<add_reference> add_reference_trait;
  typedef type_trait_1<add_volatile> add_volatile_trait;

  typedef type_trait_1<remove_all_extents> remove_all_extents_trait;
  typedef type_trait_1<remove_const> remove_const_trait;
  typedef type_trait_1<remove_cv> remove_cv_trait;
  typedef type_trait_1<remove_extent> remove_extent_trait;
  typedef type_trait_1<remove_pointer> remove_pointer_trait;
  typedef type_trait_1<remove_reference> remove_reference_trait;
  typedef type_trait_1<remove_volatile> remove_volatile_trait;

  typedef value_trait_1<int_type, int_, alignment_of> alignment_of_trait;
  typedef value_trait_1<int_type, int_, rank> rank_trait;

  typedef value_trait_1<bool, bool_, has_nothrow_assign> has_nothrow_assign_trait;
  typedef value_trait_1<bool, bool_, has_nothrow_constructor> has_nothrow_constructor_trait;
  typedef value_trait_1<bool, bool_, has_nothrow_copy> has_nothrow_copy_trait;
  typedef value_trait_1<bool, bool_, has_trivial_assign> has_trivial_assign_trait;
  typedef value_trait_1<bool, bool_, has_trivial_constructor> has_trivial_constructor_trait;
  typedef value_trait_1<bool, bool_, has_trivial_copy> has_trivial_copy_trait;
  typedef value_trait_1<bool, bool_, has_trivial_destructor> has_trivial_destructor_trait;
  typedef value_trait_1<bool, bool_, has_virtual_destructor> has_virtual_destructor_trait;

  typedef value_trait_1<bool, bool_, is_abstract> is_abstract_trait;
  typedef value_trait_1<bool, bool_, is_arithmetic> is_arithmetic_trait;
  typedef value_trait_1<bool, bool_, is_array> is_array_trait;
  typedef value_trait_1<bool, bool_, is_class> is_class_trait;
  typedef value_trait_1<bool, bool_, is_compound> is_compound_trait;
  typedef value_trait_1<bool, bool_, is_const> is_const_trait;
  typedef value_trait_1<bool, bool_, is_empty> is_empty_trait;
  typedef value_trait_1<bool, bool_, is_enum> is_enum_trait;
  typedef value_trait_1<bool, bool_, is_floating_point> is_floating_point_trait;
  typedef value_trait_1<bool, bool_, is_function> is_function_trait;
  typedef value_trait_1<bool, bool_, is_fundamental> is_fundamental_trait;
  typedef value_trait_1<bool, bool_, is_integral> is_integral_trait;
  typedef value_trait_1<bool, bool_, is_member_function_pointer> is_member_function_pointer_trait;
  typedef value_trait_1<bool, bool_, is_member_object_pointer> is_member_object_pointer_trait;
  typedef value_trait_1<bool, bool_, is_member_pointer> is_member_pointer_trait;
  typedef value_trait_1<bool, bool_, is_object> is_object_trait;
  typedef value_trait_1<bool, bool_, is_pod> is_pod_trait;
  typedef value_trait_1<bool, bool_, is_pointer> is_pointer_trait;
  typedef value_trait_1<bool, bool_, is_polymorphic> is_polymorphic_trait;
  typedef value_trait_1<bool, bool_, is_reference> is_reference_trait;
  typedef value_trait_1<bool, bool_, is_scalar> is_scalar_trait;
  typedef value_trait_1<bool, bool_, is_stateless> is_stateless_trait;
  typedef value_trait_1<bool, bool_, is_union> is_union_trait;
  typedef value_trait_1<bool, bool_, is_void> is_void_trait;
  typedef value_trait_1<bool, bool_, is_volatile> is_volatile_trait;

  typedef value_trait_2<bool, bool_, is_base_of> is_base_of_trait;
  typedef value_trait_2<bool, bool_, is_convertible> is_convertible_trait;
  typedef value_trait_2<bool, bool_, is_same> is_same_trait;

} }

#endif
