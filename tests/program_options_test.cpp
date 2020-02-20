#include "catch.hpp"
#include <chops/program_options.hpp>
#include <chops/lenses.hpp>

struct cmd_arg_model {
    int argc_;
    std::string program_name_;
    std::optional<int> verbosity_;
    float pi_;
    std::string path_;
    MAKE_LENSE(cmd_arg_model, argc, program_name, verbosity, pi, path);
};

TEST_CASE("basic command line parsing functionality", "[program_options]") {
    cmd_arg_model opts;
    int argc = 2;
    char* argv[2]{"main", "--verbosity=42 --pi=3.14f --path=~/foo"};
    chops::cmd_arg_parser::parse_cmd(opts, argc, argv);
    using chops::lenses::view;
    using chops::lenses::operator*;
    REQUIRE(opts * cmd_arg_model::program_name * view == std::string("main"));
    REQUIRE(opts * cmd_arg_model::argc * view == 2);
    REQUIRE((opts * cmd_arg_model::verbosity * view).value() == 42);
    REQUIRE(opts * cmd_arg_model::path * view == std::string("~/foo"));
    REQUIRE(opts * cmd_arg_model::pi * view == 3.14f);
}