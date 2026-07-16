#pragma once

#include "ecs/querying/query_filtering.hpp"


template <typename Components, typename Includes, typename Excludes,
          typename Resources>
struct query_description {
    using components = Components;
    using includes = Includes;
    using excludes = Excludes;
    using resources = Resources;
};

template <typename List>
struct build_query {
    using value = query_description<
        filter_t<List, is_component>,
        filter_t<List, is_with>,
        filter_t<List, is_without>,
        filter_t<List, is_resource>>;
};

template <typename List>
using build_query_t = build_query<List>::value;

//
// template <typename... Args>
// struct build_query<type_list<Args...>>
// {
//     using value = query_description<
//         filter_t<
// };
