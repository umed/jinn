#pragma once

#include <stdexcept>

namespace jinn::core {

struct ProjectExistsError : public std::runtime_error {
    ProjectExistsError();
};

struct NoProjectError : public std::runtime_error {
    NoProjectError();
};

} // namespace jinn::core
