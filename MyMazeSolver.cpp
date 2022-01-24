#include "MyMazeSolver.hpp"
#include "Direction.hpp"
#include "MazeSolution.hpp"
#include "Maze.hpp"
#include <ics46/factory/DynamicFactory.hpp> 
ICS46_DYNAMIC_FACTORY_REGISTER(
    MazeSolver,
    MyMazeSolver,
    "Daivic's Maze Solver (Required)");



void MyMazeSolver::solveMaze(const Maze& maze, MazeSolution& mazeSolution)
{
  	std::pair<int,int> starting = mazeSolution.getStartingCell();
  	recursive(std::get<0>(starting),std::get<1>(starting),maze,mazeSolution);                     
}



std::vector<Direction> MyMazeSolver::findPath(int x, int y,const Maze& maze, MazeSolution& mazeSolution)
{
	std::vector<Direction> path = {};
	std::pair<int,int> cell;
	Direction d;


	d = Direction::up;
	cell = std::pair<int, int>(x,y-1);
	if(!maze.wallExists(x,y,d) && find(visited.begin(),visited.end(),cell)==visited.end())
	{
		path.push_back(d);
	}
	
	d = Direction::down;

	cell = std::pair<int, int>(x,y+1);
	if(!maze.wallExists(x,y,d) && find(visited.begin(),visited.end(),cell)==visited.end())
	{
		path.push_back(d);
	}
	d = Direction::left;

	cell = std::pair<int, int>(x-1,y);
	if(!maze.wallExists(x,y,d) && find(visited.begin(),visited.end(),cell)==visited.end())
	{
		path.push_back(d);
	}
	d = Direction::right;

	cell = std::pair<int, int>(x+1,y);
	if(!maze.wallExists(x,y,d) && find(visited.begin(),visited.end(),cell)==visited.end())
	{
		path.push_back(d);
	}
	return path;
}


void MyMazeSolver::recursive(int x, int y, const Maze& maze, MazeSolution& mazeSolution)
{
	Direction m;
	std::pair<int,int> cell;
	std::vector<Direction> path = findPath(x,y,maze,mazeSolution);
	if(mazeSolution.isComplete())
		return;
	if(path.size()>0)
	{
		for(int i=0;i<path.size();i++)
		{
			m = path[i];
			std::pair<int,int> temp;
			if(m == Direction::right)
			{ 
				temp = std::pair<int, int>(x+1,y);
			}
			else if(m == Direction::up)
			{
				temp = std::pair<int, int>(x,y-1);
			}
			else if(m == Direction::down)
			{
				temp = std::pair<int, int>(x,y+1);
			}
			else if(m == Direction::left)
			{
				temp = std::pair<int, int>(x-1,y);
			}
			if(find(visited.begin(),visited.end(),temp)==visited.end())
			{
				if(!mazeSolution.isComplete())
					mazeSolution.extend(m);
				cell = mazeSolution.getCurrentCell();
				visited.push_back(cell);
				recursive(cell.first,cell.second,maze,mazeSolution);
			}
		}
	}
	else if(path.size()==0)
	{

		mazeSolution.backUp();
		cell = mazeSolution.getCurrentCell();
		if(cell == mazeSolution.getStartingCell())
			return;
		recursive(cell.first,cell.second,maze,mazeSolution);
	}
	
}
