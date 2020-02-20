#pragma once 
#include <chops/lenses.hpp>
#include <optional>
#include <sstream>

namespace detail {

// helper trait to check whether a type is an optional
template <typename T>
struct is_optional : std::false_type {};
template <typename T>
struct is_optional<std::optional<T>> : std::true_type {
    using type = T;
};

}
namespace chops::cmd_arg_parser {

template <typename T>
void parse_cmd(T& t, int argc, char** argv) {
    using lenses::set;
    using lenses::visit_at;
    using lenses::operator*;
    lenses::set(t * T::argc, argc);
    lenses::set(t * T::program_name, argv[0]);
    if(argc == 1)
        return;
    
    auto iss = std::istringstream{argv[1]};
    auto str = std::string{};
    
    while (iss >> str) {
        // remove --
        std::string opt = std::string(str).substr(2);
        // find =
        auto n = opt.find('=');
        std::string opt_name;
        std::copy(opt.begin(), opt.begin() + n, std::back_inserter(opt_name));
        std::string opt_val;
        std::copy(opt.begin() + n + 1, opt.end(), std::back_inserter(opt_val));
        if(T::has_member(t, opt_name)) {
            lenses::visit_at(t, [&](auto& field) {
                std::istringstream ss{opt_val};
                if constexpr(detail::is_optional<std::remove_reference_t<decltype(field)>>::value) {
                    using V = typename detail::is_optional<std::remove_reference_t<decltype(field)>>::type;
                    field = V{};
                    ss >> field.value();
                }
                else
                    ss >> field;
            }, T::member_index(t, opt_name));
        } else {
            std::exit(1);
        }
    }
}

}