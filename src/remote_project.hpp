#pragma once

#include <string>
#include <vector>
#include <ranges>
#include <format>

#include "project.hpp"

class RemoteProject : public Project {
public:
    RemoteProject(const std::string& serverName, const std::string& path);
};
