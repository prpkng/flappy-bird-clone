#pragma once

#include "ecs/scheduling/callable_traits.hpp"
#include "query_meta_types.hpp"


template <typename... Lists>
struct concat;

// Zero lists concatenation
template <>
struct concat<>
{
    using type = type_list<>;
};

// One List concatenation
template<typename... Ts>
struct concat<type_list<Ts...>>
{
    using type = type_list<Ts...>;
};

// Variadic concatenation
// This concatenates the first two arguments to a single type_list and then passes
// the rest recursively to the same class until there are only one argument (see above struct)
//
// It works by calling concat<type_list<A..., B...> + Rest...>, repeating the process until
// there is only one list!
template <typename... A, typename... B, typename... Rest>
struct concat<
    type_list<A...>,
    type_list<B...>,
    Rest...>
{
    using type =
        typename concat<
            type_list<A..., B...>,
            Rest...
        >::type;
};

template <typename... Lists>
using concat_t = typename concat<Lists...>::type;

template <template<typename> class Predicate, typename T>
using keep_if = 
    std::conditional_t<
        Predicate<T>::value,
        type_list<T>,
        type_list<>
    >;

template <typename List, template<typename> class Predicate>
struct filter {};

template <typename... Ts, template<typename> class Predicate>
struct filter<type_list<Ts...>, Predicate>
{
    using type = 
        concat_t<
            keep_if<Predicate, Ts>...
        >;
};

template <typename List, template<typename> class Predicate>
using filter_t = 
    typename filter<List, Predicate>::type;

