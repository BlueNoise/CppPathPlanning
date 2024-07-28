#ifndef CPP_PATH_PLANNING_ASTAR_H
#define CPP_PATH_PLANNING_ASTAR_H

//! @file astar.h
namespace cpp_path_planning
{
    //! @class Create an A* planner
    class AStar
    {
    public:
        AStar(int x, int y);
        void createGrid(int x, int y);

    private:
        int x_;
        int y_;
    };
} // namespace cpp_path_planning

#endif // CPP_PATH_PLANNING_ASTAR_H
