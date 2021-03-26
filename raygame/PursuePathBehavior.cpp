#include "PursuePathBehavior.h"
#include "Node.h"

MathLibrary::Vector2 PursuePathBehavior::findDestination(Agent* owner)
{
    MathLibrary::Vector2 targetPosition = getTarget()->getWorldPosition();
    MathLibrary::Vector2 targetVelocity = getTarget()->getVelocity();
    return targetPosition + targetVelocity;
}

void PursuePathBehavior::BFS(int startX, int startY, int goalX, int goalY)
{
	
	//get a refrence to the start and end node
	Node* start = getNode(startX, startY);
	Node* goal = getNode(goalX, goalY);

	//if the start or the end is null return
	if (!start || !goal)
		return;

	//set the color to start and mark it as visited
	start->color = ColorToInt(GREEN);
	start->visited = true;

	//set the iterator to be the start node
	Node* currentNode = start;

	//Create a queue to store the nodes
	std::deque<Node*> queue;
	//add the start node to the queue
	queue.push_front(start);

	//search for the goal while the queue isnt empty
	while (!queue.empty())
	{
		//set the current node to be the first item in the que
		currentNode = queue[0];
		queue.pop_front();
		//check if the the iterator is the goal node
		if (currentNode == goal)
		{
			//set the current node color to be yellow and mark it as found
			currentNode->color = ColorToInt(YELLOW);
			return;
		}

		//if the node wasn't the goal loop through it's edges to get it's neighbours

		for (int i = 0; i < currentNode->edges.size(); i++)
		{
			//create a pointer to store the node at the other end of the edge
			Node* currentEdgeEnd = nullptr;

			//set the pointer to be the opposite
			if (currentNode == currentNode->edges[i]->connectedNode2)
				currentEdgeEnd = currentNode->edges[i]->connectedNode1;
			else
				currentEdgeEnd = currentNode->edges[i]->connectedNode2;

			//if the node at the opposite end hasn't been visited mark it as visited end ass it to the queue

			if (!currentEdgeEnd->visited)
			{
				currentEdgeEnd->color = ColorToInt(RED);
				currentEdgeEnd->visited = true;
				queue.push_front(currentEdgeEnd);
			}
		}
	}
}

Node* PursuePathBehavior::getNode(int xPos, int yPos)
{
	if (xPos < 0 || yPos < 0)
		return nullptr;

	for (int i = 0; i < m_nodes.size(); i++)
	{
		if (m_nodes[i]->graphPosition == MathLibrary::Vector2(xPos, yPos))
			return m_nodes[i];
	}
	return nullptr;
}