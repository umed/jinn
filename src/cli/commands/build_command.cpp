#include "build_command.hpp"
#include "core/project.hpp"

#include <core/build_generator.hpp>
#include <core/project_errors.hpp>

#include <CLI/App.hpp>

#include <filesystem>

namespace fs = std::filesystem;

namespace jinn::cli::commands {

struct BuildCommand : public base::Command {
    std::string projectDir = fs::current_path().string();
    std::string buildDir = (fs::current_path() / "build/").string();

    BuildCommand(CLI::App* app)
    {
        app->add_option("--project", projectDir, "Project root directory location");
        app->add_option("--build", buildDir, "Project's build directory location");
    }

    void execute() override
    {
        if (!core::IsProjectFileExists()) {
            throw core::NoProjectError {};
        }

        core::Project{};

        core::BuildGenerator(projectDir, buildDir);
    }
};

base::CommandPtr createBuildCommand(CLI::App* app)
{
    return std::make_shared<BuildCommand>(app);
}

} // namespace jinn::cli::commands
