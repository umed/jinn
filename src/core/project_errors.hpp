#pragma once

#include <stdexcept>

namespace jinn::core {

struct ProjectExistsError : public std::runtime_error {
    ProjectExistsError();
};

} // namespace jinn::core
