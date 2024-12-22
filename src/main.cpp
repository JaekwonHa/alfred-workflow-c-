#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <vector>
#include <filesystem>
#include <ranges>

#include "project.hpp"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << std::format("Usage: {} <vscode_project directory>\n", argv[0]);
        return 1;
    }

    auto dirPath = std::filesystem::path(argv[1]);

    if (!std::filesystem::exists(dirPath) || !std::filesystem::is_directory(dirPath)) {
        std::cerr << std::format("Error: '{}' is not a valid directory\n", dirPath.string());
        return 1;
    }

    auto files = std::filesystem::directory_iterator(dirPath)
        | std::views::filter([](const auto& entry) { return entry.is_regular_file(); })
        | std::views::transform([](const auto& entry) { return entry.path(); });

    auto projects = std::vector<Project>();
    for (const auto& filePath : files) {
        std::cout << std::format("Reading file '{}'\n", filePath.string());
    }

    return 0;
}
