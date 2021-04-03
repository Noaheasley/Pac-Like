# AI Documentation

 Name: NodeGraph::findPath(Node* start, Node* end)
         
         Description: creates a path for the ai to follow
         Type:std::deque<NodeGraph::Node*> 
         
 Name: NodeGraph::checkList(std::deque<Node*> list, Node* lookingFor)
         
         Description: checks the list of nodes and edges
         Type:bool
         
 Name: NodeGraph::updateHS(Node* currentNode, Node* end)
         
         Description: updates the h Score
         Type:float

 Name: currentGScore
         
         Description: is the calculation for the current g Score node
         Type:float
         
 Name: currentHScore
         
         Description: is the calculation for the current h Score node
         Type:float
         
 Name: currentFScore
         
         Description: is the calculation for the current f Score node
         Type:float
         
 Name: currentNode
         
         Description: used as the iterator for the path
         Type:Node*
         
 Name: currentEdgeEnd
         
         Description: used as a node pointer to store the other end of the edge
         Type:Node*
