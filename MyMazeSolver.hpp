#ifndef MYMAZESOLVER_HPP
#define MYMAZESOLVER_HPP


#include "MazeSolver.hpp"
#include "Maze.hpp"
#include "MazeSolution.hpp"

class MyMazeSolver: public MazeSolver
{
public:
	void solveMaze(const Maze& maze, MazeSolution& mazeSolution) override;
	void recursive(int x, int y, const Maze& maze, MazeSolution& mazeSolution);
	std::vector<Direction> findPath(int x, int y,const Maze& maze, MazeSolution& mazeSolution);
private:
 	std::vector<std::pair<int,int>> visited;                                                                           
};

#endif