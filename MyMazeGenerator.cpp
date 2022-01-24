#include "MyMazeGenerator.hpp"
#include "Maze.hpp"
#include "Direction.hpp"

#include <ics46/factory/DynamicFactory.hpp>

ICS46_DYNAMIC_FACTORY_REGISTER(
    MazeGenerator,
    MyMazeGenerator,
    "Daivic's Generator(Required)");


void MyMazeGenerator::generateMaze(Maze& maze)
{
	maze.removeAllWalls();
    maze.addAllWalls();
	visited.clear();
	c =0;
	visited.push_back(std::tuple<int,int>(0,0));
	recursive(0,0,maze);
}

std::tuple<int,int> MyMazeGenerator::findPath(int x,int y,Maze& maze)
{
	std::tuple<int,int> temp;
	bool up, down, left, right;
	Direction dir;
	while(true)
	{
		int rand = std::rand()%4;
		if(rand == 0){
			up = true;
			dir = Direction::up;
			if(y > 0){
				temp = std::tuple<int,int>(x,y-1);
			}


		}else if(rand == 1){
			down = true;
			dir = Direction::down;
			if( y < maze.getHeight()-1){
				temp = std::tuple<int,int>(x,y+1);
			}

		}else if(rand == 2){
			left = true;
			dir = Direction::left;
			if( x > 0){
				temp = std::tuple<int,int>(x-1,y);
			}

		}else if(rand == 3){
			right = true;
			dir= Direction::right;
			if(x < maze.getWidth()-1){
				temp = std::tuple<int,int>(x+1,y);
			}

		}
		if(up == true && down == true && left == true && right == true)
		{
			temp = visited[visited.size()-c-2];
			
			if(c+2 < visited.size()-1)
				c++;	
			break;
		}
		if(find(visited.begin(),visited.end(),temp)==visited.end())
		{
			visited.push_back(temp);
			maze.removeWall(x,y,dir);
			c=0;
			break;
		}
		
	}
	return temp;
}
void MyMazeGenerator::recursive(int x, int y, Maze& maze)
{
	std::tuple<int,int>temp = findPath(x,y,maze);
	int sz = maze.getHeight()*maze.getWidth();
	if(visited.size() != sz)
		recursive(std::get<0>(temp),std::get<1>(temp),maze);
	else
		return;
}
		