#include "local_project.hpp"

auto LocalProject::isMatched(const std::vector<std::string>& keywords) const -> bool {
    return true;
}

auto LocalProject::print() const -> std::string {
    throw std::runtime_error("Not implemented");
}
