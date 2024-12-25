#include <gtest/gtest.h>

#include "project.hpp"

struct TestCase {
    std::string serverName;
    std::string path;
    std::vector<std::string> keywords;
    int expectedScore;
};

class ProjectParameterizedTestFixture : public ::testing::TestWithParam<TestCase> {};

TEST_P(ProjectParameterizedTestFixture, getScore) {
    auto [serverName, path, keywords, expectedSocre] = GetParam();

    auto project = Project::create(serverName, path);

    auto result = project->getScore(keywords);

    EXPECT_EQ(expectedSocre, result);
}

INSTANTIATE_TEST_SUITE_P(
    ProjectTest,
    ProjectParameterizedTestFixture,
    ::testing::Values(
        TestCase{"local", "/Users/user/workspace/repo2/alfred-workflow-c++", {"alfred", "workflow", "c++"}, 6},
        TestCase{"local", "/Users/user/workspace/repo2/alfred-workflow-c++", {"local"}, 3},
        TestCase{"local", "/Users/user/workspace/repo2/url-parser", {"alfred", "workflow", "c++"}, 0},
        TestCase{"local", "/Users/user/workspace/repo2/alfred-workflow-c++", {"alfred", "local"}, 5},
        TestCase{"remote", "/Users/user/workspace/repo2/alfred-workflow-c++", {"alfred", "local"}, 2}
    )
);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
