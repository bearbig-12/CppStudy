#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
class BST
{
	class Node
	{

	public:
		int mKey;
		std::string mName;
	public:
		Node* mpRight;
		Node* mpLeft;

		Node();
		Node(const Node& node);
		Node(int key, std::string name);
		Node(int key, std::string name, Node* right, Node* left);
		~Node();

	};
public:
	Node* mpRoot{};
public:
	Node* CreateNode(int key, std::string name);
	Node* Insert(Node* parent, int key, std::string name);
	Node* PrintNode(Node* node);
	void  PreOrder(Node* node);
	void  InOrder(Node* node);
	bool  Find_key(Node* node, int key);
	bool  Find_Name(Node* node, std::string name);
	Node* Delete(Node* node, int key);
	Node* GetSimilarNode(Node* node);
};

