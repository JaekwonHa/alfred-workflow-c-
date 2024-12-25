#include "remote_project.hpp"

auto RemoteProject::isMatched(const std::vector<std::string>& keywords) const -> bool {
    return true;
}

auto RemoteProject::print() const -> std::string {
    throw std::runtime_error("Not implemented");
}
