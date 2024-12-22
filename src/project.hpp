#pragma once

#include <string>
#include <vector>

class Project {
private:
    std::string name;
    std::string url;

public:
    Project() = delete;
    Project(const std::string& path);

    virtual auto isMatch(const std::vector<std::string>& keywords) const -> bool = 0;
    virtual auto print() const -> std::string = 0;
};
