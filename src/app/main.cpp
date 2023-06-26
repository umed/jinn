#include <cli/base/app.hpp>
#include <cli/commands/registrar.hpp>

#include <cstdlib>
#include <iostream>

using jinn::cli::base::App;
using jinn::cli::commands::registerCommands;

int main(int argc, char** argv)
{
    App app;
    registerCommands(app);

    try {
        return app.run(argc, argv);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_FAILURE;
}
