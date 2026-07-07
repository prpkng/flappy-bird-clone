#pragma once

#include <tuple>
#include <type_traits>

template<typename... Ts>
struct type_list {};

//------------------------------------------------------------
// type_list utilities
//------------------------------------------------------------

template<typename List>
struct type_list_size;

template<typename... Ts>
struct type_list_size<type_list<Ts...>>
    : std::integral_constant<std::size_t, sizeof...(Ts)>
{
};

template<typename List>
inline constexpr std::size_t type_list_size_v =
type_list_size<List>::value;


//------------------------------------------------------------
// callable_traits
//------------------------------------------------------------

template<typename T>
struct callable_traits;


// Free function

template<typename R, typename... Args>
struct callable_traits<R(Args...)>
{
    using return_type = R;
    using args = type_list<Args...>;

    static constexpr std::size_t arity = sizeof...(Args);
};


// Function pointer

template<typename R, typename... Args>
struct callable_traits<R(*)(Args...)>
    : callable_traits<R(Args...)>
{
};


// Function reference

template<typename R, typename... Args>
struct callable_traits<R(&)(Args...)>
    : callable_traits<R(Args...)>
{
};


// Member function

template<typename C, typename R, typename... Args>
struct callable_traits<R(C::*)(Args...)>
    : callable_traits<R(Args...)>
{
    using class_type = C;
};


// Const member function

template<typename C, typename R, typename... Args>
struct callable_traits<R(C::*)(Args...) const>
    : callable_traits<R(Args...)>
{
    using class_type = C;
};


// Functors / lambdas

template<typename T>
struct callable_traits
    : callable_traits<decltype(&T::operator())>
{
};


//------------------------------------------------------------
// first_type Utility
//------------------------------------------------------------

template<typename List>
struct first_type;

template<typename T, typename... Rest>
struct first_type<type_list<T, Rest...>>
{
    using type = T;
};

template<typename C, typename T, typename... Rest>
struct first_type<type_list<C*, T, Rest...>>
{
    using type = T;
};

template<typename List>
using first_type_t = typename first_type<List>::type;
