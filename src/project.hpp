#pragma once

#include <string>
#include <vector>

class Project {
protected:
    std::string name;
    std::string url;

public:
    Project() = delete;
    Project(const std::string& path) {
        name = path.substr(path.find_last_of('/') + 1);
        url = path;
    }

    virtual auto isMatched(const std::vector<std::string>& keywords) const -> bool = 0;
    virtual auto print() const -> std::string = 0;
};
