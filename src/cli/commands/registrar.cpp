#include "registrar.hpp"

#include "init.hpp"

namespace jinn::cli::commands {

void registerCommands(base::App& app)
{
    app.addCommand("new", "creat new project", createNewCommand);
}

} // namespace jinn::cli::commands
