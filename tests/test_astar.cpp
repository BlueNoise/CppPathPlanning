#include <gtest/gtest.h>

#include <cpp_path_planning/astar.h>

TEST(AStarTest, FirstTest)
{
    cpp_path_planning::AStar planner = cpp_path_planning::AStar(1, 2);
}
