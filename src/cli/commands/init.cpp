#include "init.hpp"

#include <core/project.hpp>

#include <CLI/App.hpp>

#include <iostream>

namespace jinn::cli::commands {

struct NewCommand : public base::Command {
    std::string projectName;

    NewCommand(CLI::App* app);

    void execute() override;
};

NewCommand::NewCommand(CLI::App* app)
{
    app->add_option("project_name", projectName);
}

void NewCommand::execute()
{
    core::FailIfProjectExists();

    auto project = core::Project {
        .name = projectName,
    };
    project.dump();
}

base::CommandPtr createNewCommand(CLI::App* app)
{
    return std::make_unique<NewCommand>(app);
}

} // namespace jinn::cli::commands
