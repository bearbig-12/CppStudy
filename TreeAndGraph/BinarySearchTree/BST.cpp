#include "BST.h"

BST::Node::Node()
{
	mKey = 0;
	mName = " ";
	mpRight = nullptr;
	mpLeft = nullptr;

}

BST::Node::Node(const Node& node)
{
	this->mKey = node.mKey;
	this->mName = node.mName;
	mpRight = nullptr;
	mpLeft = nullptr;
}

BST::Node::Node(int key, std::string name)
{
	this->mKey = key;
	this->mName = name;
	mpRight = nullptr;
	mpLeft = nullptr;
}

BST::Node::Node(int key, std::string name, Node* right, Node* left)
{
	this->mKey = key;
	this->mName = name;
	mpRight = right;
	mpLeft = left;
}

BST::Node::~Node()
{
}


BST::Node* BST::CreateNode(int key, std::string name)
{
	return new Node(key, name);
}

BST::Node* BST::Insert(Node* parent, int key, std::string name)
{
	if (parent == nullptr)
	{
		return CreateNode(key, name);
	}
	if (parent->mKey < key)
	{
		parent->mpRight = Insert(parent->mpRight, key, name);
	}
	else if (parent->mKey > key)
	{
		parent->mpLeft = Insert(parent->mpLeft, key, name);
	}
	return parent;
}

BST::Node* BST::PrintNode(Node* node)
{
	std::cout << "Key : " << node->mKey << " - " << "Name : " << node->mName << std::endl;
	return node;
}

void BST::PreOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	PrintNode(node);
	PreOrder(node->mpLeft);
	PreOrder(node->mpRight);
}

void BST::InOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	InOrder(node->mpLeft);
	PrintNode(node);
	InOrder(node->mpRight);
}

bool BST::Find_key(Node* node, int key)
{
	if (node == nullptr)
	{
		std::cout << "BST is Empty" << std::endl;
		return false;
	}
	if (node->mKey == key)
	{
		std::cout << "Found!!" << node->mKey << " , " << node->mName << std::endl;
		return true;
	}
	else if (node->mKey < key)
	{
		Find_key(node->mpRight, key);
	}
	else
	{
		Find_key(node->mpLeft, key);
	}
}

bool BST::Find_Name(Node* node, std::string name)
{
	if (node == nullptr)
	{
		std::cout << "BST is Empty" << std::endl;
		return false;
	}

	if (node->mpLeft != nullptr)
	{
		Find_Name(node->mpLeft, name);
	}
	if (node->mName == name)
	{
		std::cout << "Found!!" << node->mKey << " > " << node->mName << std::endl;
		return true;
	}
	if (node->mpRight != nullptr)
	{
		Find_Name(node->mpRight, name);
	}
}

BST::Node* BST::Delete(Node* node, int key)
{
	if (node == nullptr)
	{
		std::cout << "Tree is Empty" << std::endl;
		return node;
	}
	if (node->mKey > key)
	{
		node->mpLeft = Delete(node->mpLeft, key);
	}
	else if (node->mKey < key)
	{
		node->mpRight = Delete(node->mpRight, key);
	}
	else
	{
		// Node is Leaf Node
		if (node->mpLeft == nullptr && node->mpRight == nullptr)
		{
			delete node;
			node = nullptr;
		}
		else if (node->mpRight == nullptr) 
		{
			Node* space = node->mpLeft;
			delete node;
			return space;
		}
		else if (node->mpLeft == nullptr)	
		{					
			Node* space = node->mpRight;
			delete node;
			return space;
		}
		//node has 2 child
		else if (node->mpLeft != nullptr && node->mpRight != nullptr)
		{
			Node* temp = GetSimilarNode(node->mpRight);
			node->mKey = temp->mKey;
			node->mName = temp->mName;
			node->mpRight = Delete(node->mpRight, node->mKey);
			
		}
	} 
	return node;
}

BST::Node* BST::GetSimilarNode(Node* node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->mpLeft == nullptr)
	{
		return node;
	}
	while (node->mpLeft != nullptr)
	{
		node = node->mpLeft;
	}
	return node;
}
