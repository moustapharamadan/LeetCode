#include "../pch.h"
#include "../header/0138_Copy_List_with_RandomPointer.hpp"

class CopyRandomList : public ::testing::Test, public LEETCODE_0138::Solution {
};

TEST_F(CopyRandomList, Test1)
{
	using Node = LEETCODE_0138::Node;
	Node* head = new Node(7);
	Node* currentNode = head;						//7
	head->next = new Node(13);
	head->random = nullptr;
	currentNode = currentNode->next;				//13
	currentNode->next = new Node(11);
	currentNode->random = head;
	currentNode = currentNode->next;				//11
	currentNode->next = new Node(10);
	currentNode->random= new Node(1);
	currentNode = currentNode->next;				//10
	currentNode->next = head->next->next->random;
	currentNode->random = head->next->next;
	currentNode = currentNode->next;				//1
	currentNode->next = nullptr;
	currentNode->random = head;

	Node* result=copyRandomList(head);
}

TEST_F(CopyRandomList, Test2)
{
	using Node = LEETCODE_0138::Node;
	Node* head = new Node(3);
	Node* currentNode = head;						//3
	head->next = new Node(3);
	head->random = nullptr;
	currentNode = currentNode->next;				//3
	currentNode->next = new Node(3);
	currentNode->random = head;
	currentNode = currentNode->next;				//3
	currentNode->next = nullptr;
	currentNode->random = nullptr;

	Node* result = copyRandomList(head);
}
