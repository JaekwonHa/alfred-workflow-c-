#include <gtest/gtest.h>
#include "local_project.hpp"
#include "remote_project.hpp"

TEST(LocalProject, isMatched) {
    auto project = LocalProject("local", "/Users/user/workspace/repo2/alfred-workflow-c++");

    EXPECT_TRUE(project.isMatched({"alfred", "workflow", "c++"}));
}

TEST(RemoteProject, isMatched) {
    auto project = RemoteProject("remote", "/Users/user/workspace/repo2/alfred-workflow-c++");

    EXPECT_TRUE(project.isMatched({"alfred", "workflow", "c++"}));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
