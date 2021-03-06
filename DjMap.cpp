#include "DjMap.h"
#include <map>
#include <fstream>

using namespace std;

DjMap::DjMap()
{
}


DjMap::~DjMap()
{
	for (std::map<unsigned int, node*>::iterator itr = nodeMap.begin(); itr != nodeMap.end(); itr++)
	{
		delete itr->second;
	}
}

DjMap::DjMap(unsigned int num_nodes, unsigned int num_edges)
{
	this->node_count = num_nodes;
	this->edge_count = num_edges;
}

node * DjMap::getNode(unsigned int id)
{
	return nodeMap[id];
}

void DjMap::addNode(node * newNode)
{
	nodeMap[newNode->getId()]=newNode;
}




unsigned int DjMap::getEdgeCount(void)
{
	return edge_count;
}

void DjMap::addConnection(unsigned int A, unsigned int B)
{
	node* nodeA = nodeMap[A];
	node* nodeB = nodeMap[B];
	float distance = sqrt(pow(nodeA->getXpos()-nodeB->getXpos(),2)+pow(nodeA->getYpos() - nodeB->getYpos(),2));
	nodeA->addNbr(nodeB,distance);
	nodeB->addNbr(nodeA,distance);
}

bool DjMap::isValidRequest(request r1)
{
	if ((nodeMap.find(r1.root) == nodeMap.end())
		|| (nodeMap.find(r1.dest) == nodeMap.end()))
		return false;
	else
		return true;
}

