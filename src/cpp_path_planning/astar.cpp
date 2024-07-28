#include <cpp_path_planning/astar.h>

#include <vector>

namespace cpp_path_planning
{
    AStar::AStar(int x, int y) : x_(x), y_(y) {}

    void AStar::createGrid(int x, int y)
    {
        std::vector<std::vector<int>> grid;
    }
} // namespace cpp_path_planning
