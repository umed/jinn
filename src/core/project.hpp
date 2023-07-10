#pragma once

#include <string>
#include <string_view>
#include <vector>

namespace jinn::core {

constexpr auto ProjectFileName = "jinn.toml";

constexpr auto DefaultVersion = "0.0.1";
constexpr auto DefaultStdVersion = "c++20";

struct Project {
    std::string name;
    std::string version = DefaultVersion;

    std::string stdVersion = DefaultStdVersion;

    std::vector<std::string> authors;

    static Project load(std::string_view path);
    void dump() const;
};

bool IsProjectFileExists();
void FailIfProjectExists();

} // namespace jinn::core
