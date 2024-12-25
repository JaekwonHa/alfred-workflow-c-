#pragma once

#include <string>
#include <vector>
#include <ranges>
#include <format>

#include "project.hpp"

class RemoteProject : public Project {
public:
    RemoteProject(const std::string& path) : Project(path) {}

    auto isMatched(const std::vector<std::string>& keywords) const -> bool override;

    auto print() const -> std::string override;
};
