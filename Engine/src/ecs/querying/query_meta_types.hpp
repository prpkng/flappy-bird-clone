#pragma once


#include "ecs/scheduling/callable_traits.hpp"
#include <type_traits>


// ======= TAG TYPES ================

template <typename T>
struct With {};


template <typename T>
struct Without {};


template <typename T>
struct Res {};

// ======= "IS" TRAITS ==============

template <typename T>
struct is_with : std::false_type {};

template <typename T>
struct is_with<With<T>> : std::true_type{};

template <typename T>
struct is_without : std::false_type {};

template <typename T>
struct is_without<Without<T>> : std::true_type{};


template <typename T>
struct is_resource : std::false_type {};

template <typename T>
struct is_resource<Res<T>> : std::true_type{};


template <typename T>
struct is_component {
    static constexpr bool value = 
        !is_with<T>::value &&
        !is_without<T>::value &&
        !is_resource<T>::value;
};
