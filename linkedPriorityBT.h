#pragma once
#include "priorityNode.h"
class linkedBSPQ {
	bool left;
	nodePQ* lastParent;
	nodePQ* last;
	nodePQ* root;//points to rootHeader. Actual root is root->right
	nodePQ* rootNode = nullptr;//?
	nodePQ rootHeader;
	inline void insertNode(const int& val);
	inline void heapify(nodePQ* curr);
	inline void deepCopy(linkedBSPQ&);
public:
	//constructors and big 3
	linkedBSPQ();
	linkedBSPQ(int [], int);
	linkedBSPQ(const linkedBSPQ&);
	~linkedBSPQ() {

	}
	linkedBSPQ& operator=(linkedBSPQ&);
	//
	void enqueue(const int&);
	bool dequeue(int&);
	void display();
	bool isEmpty();
	void makeEmpty();
};