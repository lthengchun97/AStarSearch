# About A Star Search Algorithm

The purpose of using A Star Search Algorithm is for **pathfinding** and **graph traversal**. It will help us find the nearest way to reach the destination which helped us saved a lot of time. It is the process of plotting an efficiently directed path between multiple points, called nodes. It will determine the **heuristic distance** between each nodes to consider that it will go through what way, the shortest distance compare to each other nodes will be choosen as the best path. A star search are widely use on the GPS system and also for developing games such as WARCRAFT III.

# On this A Star Search Algorithm

We are using AVL method to help us sort all the nodes to their corresponding position, which is left(**near**) and right (**far**). AVL and then will help us rotate the tree to a stable tree, which make us no need to worry about the **backtrack issue**. 

# Coding Methodology

The heuristic distance between each node will be find by:

    float findDistance(Node *current, Node *end);

The A star node convert to normal node will be done by:

    void createNodeAvl(Node *node,A_Node *data);
    
The compare function which determine it is near to the end or far to the end will be as:

    int compareNode(Node *node, Node *refNode,float d_ideal,Node *end);
    
The function which help to add the node to the tree will be:

    #define avladdNode(root,nodeToAdd,d_optimal,end)  addNode(root,nodeToAdd,(compare)compareNode,d_optimal,end)
    
The main function which will return all the passed nodes and total distance travelled will be:

    Node* Asearch(Node **current, Node *end,int backtrack,float totalDistance);
    
# References

1. https://en.wikipedia.org/wiki/A*_search_algorithm
2. https://www.geeksforgeeks.org/a-search-algorithm/

