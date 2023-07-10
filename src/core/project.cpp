#include "project.hpp"

#include <core/project_errors.hpp>

#include <toml++/impl/parser.h>
#include <toml++/toml.h>

#include <filesystem>
#include <fstream>
#include <iostream>

namespace jinn::core {

bool IsProjectFileExists()
{
    return std::filesystem::exists(ProjectFileName);
}

void FailIfProjectExists()
{
    if (IsProjectFileExists()) {
        throw ProjectExistsError {};
    }
}

Project Project::load(std::string_view path)
{
    auto table = toml::parse(path);
    auto projectTable = table["project"];
    return Project {
        .name = projectTable["name"].value_or<std::string>(""),
        .version = table["project"].value_or<std::string>("0.0.1"),
    };
}

void Project::dump() const
{
    auto table = toml::table {
        { "name", name },
        { "version", version },
        { "std", stdVersion },
    };
    if (!authors.empty()) {
        toml::array authorsToml;
        for (const auto& author : authors) {
            authorsToml.emplace_back(author);
        }
        table.emplace("authors", authorsToml);
    }
    std::ofstream out(ProjectFileName);
    out << toml::table {
        { "project", table },
    };
}

} // namespace jinn::core
