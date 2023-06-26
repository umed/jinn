#pragma once

#include <cli/base/command.hpp>

#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>

namespace jinn::cli::base {

struct App final {
    CLI::App app;

    App();

    void addCommand(std::string name, std::string description, auto&& commandCreator)
    {
        auto appSubCommand = app.add_subcommand(name, description);

        appSubCommand->callback([command = commandCreator(appSubCommand)]() mutable {
            command->execute();
        });
    }

    int run(int argc, char** argv);
};

} // namespace jinn::cli::base
