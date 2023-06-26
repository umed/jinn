#include "project.hpp"

#include <core/project_errors.hpp>

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
