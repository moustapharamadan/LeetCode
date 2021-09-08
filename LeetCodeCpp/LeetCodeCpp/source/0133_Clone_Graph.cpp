#include "../pch.h"
#include "../header/0133_Clone_Graph.hpp"

class CloneGraph : public ::testing::Test, public LEETCODE_0133::Solution {
};

TEST_F(CloneGraph, test1)
{
	using namespace LEETCODE_0133;
	std::map<int, Node*> nodeMap;
	nodeMap[1] = new Node(1);
	nodeMap[2] = new Node(2);
	nodeMap[3] = new Node(3);
	nodeMap[4] = new Node(4);
	Node* node = nodeMap[4];
	node->neighbors.push_back(nodeMap[1]);
	node->neighbors.push_back(nodeMap[3]);
	node = nodeMap[3];
	node->neighbors.push_back(nodeMap[4]);
	node->neighbors.push_back(nodeMap[2]);
	node = nodeMap[2];
	node->neighbors.push_back(nodeMap[3]);
	node->neighbors.push_back(nodeMap[1]);
	node = nodeMap[1];
	node->neighbors.push_back(nodeMap[2]);
	node->neighbors.push_back(nodeMap[4]);
	Node* result = cloneGraph(node);
}