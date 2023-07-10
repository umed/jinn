#include "build_generator.hpp"

#include <filesystem>
#include <fstream>
#include <ios>

namespace fs = std::filesystem;

namespace jinn::core {

/*
 * build {
 *   jinn.lock
 *
 *   files.txt: {
 *     file.cpp
 *     file2.cpp
 *   }
 *   files.hash - not used yet
 *
 *   includes.txt: {
 *     src/
 *     dep1/src/
 *     dep2/src/
 *   }
 *
 * }
 */

void updateFiles(const fs::path& projectRootDir, const fs::path& buildDir)
{

    auto filesPathStr = (buildDir / "files.txt").string();
    std::ofstream out(filesPathStr, std::ios::app);

    for (const auto& entry : fs::recursive_directory_iterator(projectRootDir / "src")) {
        if (entry.is_directory())
            continue;
        out << entry.path() << "\n";
    }
}

void updateIncludes(const fs::path& projectRootDir, const fs::path& buildDir)
{
    auto includesPathStr = (buildDir / "includes.txt").string();

    std::ofstream out(includesPathStr, std::ios::app);

    auto projectIncludePath = projectRootDir / "include/";
    if (fs::exists(projectIncludePath)) {
        out << projectIncludePath << '\n';
    }
    for (const auto& entry : fs::recursive_directory_iterator(projectRootDir / "src")) {
        if (!entry.is_directory())
            continue;
        out << entry.path() << '\n';
    }
}

BuildGenerator::BuildGenerator(
    Project& project, const fs::path& projectRootDir, const fs::path& buildDir)
{
    if (!fs::exists(buildDir)) {
        fs::create_directory(buildDir);
    }
    updateFiles(projectRootDir, buildDir);
    updateIncludes(projectRootDir, buildDir);
}

} // namespace jinn::core
