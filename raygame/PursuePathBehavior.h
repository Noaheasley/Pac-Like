#pragma once
#include "PathfindBehavior.h"

class PursuePathBehavior : public PathfindBehavior
{
public:
	PursuePathBehavior(Maze* maze) :PathfindBehavior(maze) {}

	void BFS(int startX, int startY, int goalX, int goalY);
	Node* getNode(int xPos, int yPos);
protected:
	virtual MathLibrary::Vector2 findDestination(Agent* owner) override;

private:
	std::vector<Node*> m_nodes;
};

