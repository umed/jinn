#pragma once

#include <memory>
#include <string>

namespace CLI {

class App;

}

namespace jinn::cli::base {

struct Command {
    virtual ~Command() = default;

    virtual void execute() = 0;
};

using CommandUPtr = std::unique_ptr<Command>;
using CommandPtr = std::shared_ptr<Command>;

} // namespace jinn::cli::base
