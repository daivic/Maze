#ifndef MYMAZEGENERATOR_HPP
#define MYMAZEGENERATOR_HPP


#include "MazeGenerator.hpp"
#include "Maze.hpp"
class MyMazeGenerator : public MazeGenerator
{

public:
 	std::tuple<int,int> findPath(int x,int y,Maze& maze);
 	void generateMaze(Maze& maze) override;
 	void recursive(int x, int y, Maze& maze);

private:
 	std::vector<std::tuple<int,int>> visited;
 	int c = 0;

};



#endif