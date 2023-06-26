#include "app.hpp"

namespace jinn::cli::base {

App::App()
    : app { "jinn, should add a more appropriate descriptoin later", "jinn" }
{
    app.require_subcommand(1, 1);
}

int App::run(int argc, char** argv)
{
    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError& e) {
        return app.exit(e);
    }
    return EXIT_SUCCESS;
}

} // namespace jinn::cli::base
