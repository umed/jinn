#pragma once

#include <cli/base/command.hpp>

namespace jinn::cli::commands {

base::CommandPtr createNewCommand(CLI::App* app);

} // namespace jinn::cli::commands
