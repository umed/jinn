#include <core/project.hpp>

#include <filesystem>

/*
 * build {
 *   jinn.lock
 *
 *   files.txt: {
 *     file.cpp
 *     file2.cpp
 *   }
 *
 *   includes.txt: {
 *     src/
 *     dep1/src/
 *     dep2/src/
 *   }
 *
 * }
 */
namespace jinn::core {

const std::filesystem::path DefaultBuildDir { "build/" };

struct BuildGenerator {
    explicit BuildGenerator(Project& project,
        const std::filesystem::path& projectRootDir = std::filesystem::current_path(),
        const std::filesystem::path& buildDir = DefaultBuildDir);
};

} // namespace jinn::core
