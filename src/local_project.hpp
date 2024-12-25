#pragma once

#include <string>
#include <vector>
#include <ranges>
#include <format>

#include "project.hpp"

class LocalProject : public Project {
public:
    LocalProject(const std::string& serverName, const std::string& path);
};
