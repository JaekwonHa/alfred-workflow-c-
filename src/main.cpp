#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <vector>
#include <filesystem>
#include <ranges>
#include <memory>

#include <boost/algorithm/string.hpp>

#include "project.hpp"
#include "local_project.hpp"
#include "remote_project.hpp"

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        std::cerr << std::format("Usage: {} <vscode_project directory> <keyword...>\n", argv[0]);
        return 1;
    }

    auto dirPath = std::filesystem::path(argv[1]);
    if (!std::filesystem::exists(dirPath) || !std::filesystem::is_directory(dirPath)) {
        std::cerr << std::format("Error: '{}' is not a valid directory\n", dirPath.string());
        return 1;
    }

    auto keywordRanges = std::ranges::subrange(argv + 2, argv + argc)
        | std::ranges::views::transform([](const std::string& keyword) { return boost::algorithm::to_lower_copy(keyword); });
    auto keywords = std::vector<std::string>(keywordRanges.begin(), keywordRanges.end());

    auto projects = std::vector<std::unique_ptr<Project>>();
    for (const auto& entry : std::filesystem::directory_iterator(dirPath)) {
        if (!entry.is_regular_file()) continue;

        auto file = std::ifstream(entry.path());
        if (!file.is_open()) continue;

        std::string line;
        while (std::getline(file, line)) {
            if (entry.path().filename() == "local") {
                projects.push_back(std::make_unique<LocalProject>(line));
            } else {
                projects.push_back(std::make_unique<RemoteProject>(line));
            }
        }
    }

    return 0;
}
