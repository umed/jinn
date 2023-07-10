#include "registrar.hpp"

#include "cli/commands/build_command.hpp"
#include "new_command.hpp"

namespace jinn::cli::commands {

void registerCommands(base::App& app)
{
    app.addCommand(createNewCommand);
    app.addCommand("build", "build project", createBuildCommand);
}

} // namespace jinn::cli::commands
