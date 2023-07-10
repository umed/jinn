#include "project_errors.hpp"

#include <core/project.hpp>

#include <fmt/core.h>

#include <stdexcept>

namespace jinn::core {

ProjectExistsError::ProjectExistsError()
    : std::runtime_error(fmt::format("{} already exists\n", ProjectFileName))
{
}
NoProjectError::NoProjectError()
    : std::runtime_error(fmt::format("No project file"));
} // namespace jinn::core
