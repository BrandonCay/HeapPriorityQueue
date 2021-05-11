#include "linkedPriorityBT.h"
#include "priorityNode.h"
#include <iostream>
using namespace std;

linkedBSPQ::linkedBSPQ() {
	last = lastParent = root = &rootHeader;
	root->next = nullptr;
	left = false;
}

inline void linkedBSPQ::insertNode(const int & val) {
	//creation
	last->next = new nodePQ;
	//swapping last's place
	last->next->back = last;
	last = last->next;
	last->parent = lastParent;

	//set parent according to left. IF: adding to left of parent THEN connect it to its left. 
	//Otherwise: connect it to the parent's right and move the parent to the next node
	if (left) {
		lastParent->left = last;
	}
	else {
		lastParent->right = last;
		lastParent = lastParent->next;
	}
	last->info = val;
	left = !left;
}

linkedBSPQ::linkedBSPQ(int arr[], int size) {
	last = lastParent = root = &rootHeader;
	left = false;
	for (int i = 0; i < size; ++i) {
		insertNode(arr[i]);
	}
	for (nodePQ* currP = last->parent; currP != root; currP = currP->back) {
		heapify(currP);
	}
}

inline void linkedBSPQ::heapify(nodePQ* curr) {
	int temp = curr->info;
	nodePQ* largest, *leftc=curr->left, *rightc=curr->right;
	largest = (rightc == nullptr) ? leftc : ((leftc->info > rightc->info) ? leftc : rightc);
	while (leftc != nullptr && largest->info > temp) {
		curr->info = largest->info;//single swap. child value TO parent. continues to do so until finds suitable place for temp
		curr = largest;
		leftc = curr->left;
		rightc = curr->right;
		largest = (rightc == nullptr) ? leftc : ((leftc->info > rightc->info)? leftc : rightc);
	}
	curr->info = temp;//completes swap. Parent TO child
}

void linkedBSPQ::enqueue(const int& val) {
	insertNode(val);//creates node
	//need to heapify now.
	//starts from bottom, traverses upwards and brings unsorted parents down. DOWNARD heapify starts from a parent then travels down while bring parents down if unsorted
	nodePQ* curr = last, *cparent = curr->parent;
	while (cparent != root && val > cparent->info) {
		curr->info = cparent->info;
		curr = cparent;
		cparent = curr->parent;
	}
	curr->info = val;
}

bool linkedBSPQ::dequeue(int& rem) {
	if (last == root)
		return false;
	nodePQ* curr = root->right;
	rem=curr->info;
	curr->info = last->info;
	if (left) {
		lastParent = lastParent->back;
		lastParent->right = nullptr;
	}
	else {
		lastParent->left=nullptr;
	}
	last = last->back;
	delete last->next;
	last->next = nullptr;
	
	left = !left;//toggle

	if (root != last)
		heapify(curr);//starts from top and traverses downwards until t

	return true;
}

void linkedBSPQ::display() {
	nodePQ* curr = root->right;
	while (curr != nullptr) {
		cout << curr->info << " ";
		curr = curr->next;
	}
	cout << endl;
}