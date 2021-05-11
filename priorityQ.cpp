#include "priorityQ.h"
#include <iostream>
#include <math.h>
using namespace std;

void maxHeap::reallocate() {
	int newSize = heapSize * 2;
	int* temp = new int[newSize];
	for (int i = 0; i < heapSize; ++i) {
		temp[i] = arr[i];
	}
	delete arr;
	arr = temp;
	heapSize = newSize;
}
void maxHeap::reallocate(int n) {
	int* temp = new int[n];
	for (int i = 0; i < heapSize && i<n; ++i) {
		temp[i] = arr[i];
	}
	delete arr;
	arr = temp;
	heapSize = n;
}
void maxHeap::display() {
	for (int i = 0; i < heapSize; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "size: " << heapSize << endl;
	cout << "items: " << cnt << endl;
	cout << "location: " << arr << endl;
}

void maxHeap::preorder(int i) {
	if (i >= heapSize) {
		return;
	}
	else {
		cout << arr[i] << endl;
		preorder(i * 2 + 1);
		preorder(i * 2 + 2);
	}
}
void maxHeap::enqueue(const int& val) {
	if (cnt == heapSize) {
		reallocate();
		cout << "allocation" << endl;
	}
	cout << "done!" << endl;
	int i = cnt;//tail with no node. PRETEND node is there
	for (; i != 0 && val > arr[(i - 1) / 2]; i = (i - 1) / 2)//travel up. //!=0 or else recursion due to arr[-0.5].cn-1because we're pretending its a childt
		arr[i] = arr[(i - 1) / 2];//brings the parent down
	arr[i] = val;
	cout << val << endl;
	++cnt;
}

bool maxHeap::dequeue(int &rem) {
	if (!cnt)
		return false;
	rem = arr[0];
	arr[0] = arr[cnt - 1];
	heapify(0);
	--cnt;
	int trySize = heapSize;
	while (cnt <= trySize / 2 && trySize>2)//attempts to change size to a reduced power of 2 IF no elements are lost
		trySize /= 2;
	if (trySize < heapSize)//if the size can be reduced by a factor of 2 THEN do it
		reallocate(trySize);
	return true;
}
maxHeap::maxHeap(int carr[], int size) {
	/*int newSize = sqrt(size) + 1;
	heapSize = newSize;
	arr = new int[pow(2, newSize)];
	*/
	//copy elements
	arr = new int[size];
	heapSize = size;
	for (int i = 0; i < size; ++i) {
		this->arr[i] = carr[i];
		cout << "inside: " << arr[i] << endl;
	}
	//heapfify
	for (int i = (heapSize- 2) / 2; i >= 0; --i) {//trys to find a valid child for each i to heapify. ((newSize-1)-1)/2 note: extra 1 is for the off the end 1.
		heapify(i);
	}
	//increase
	int newSize = 2;
	for (; newSize < size; newSize *= 2) {}//stops when newSize>=size
	int* temp = new int[newSize];
	for (int i = 0; i < heapSize; ++i) {
		temp[i] = arr[i];
	}
	delete arr;
	arr = temp;
	heapSize = newSize;
	cnt = size;
}
void maxHeap::heapify(int i) {//assumes i is a parent. IF not, then the function stops
	int leftChild, rightChild, largeChild;
	int parentData=arr[i];
	bool stop = false;
	leftChild = i * 2+1;
	while (leftChild < heapSize && !stop) {//leaf nodes won't be checked because the loop overflows. stops when the child is less than the parent
		rightChild = leftChild + 1;
		largeChild = (rightChild >= heapSize) ? leftChild : ((arr[leftChild] > arr[rightChild]) ? leftChild : rightChild);//assigns the larges child
		if (arr[largeChild] > parentData) {
			arr[i] = arr[largeChild];//replaces the parent with the child
			i = largeChild;//makes child new parent (heapifies downward)
			leftChild = i*2+1;//formula because pattern
		}
		else {
			stop = true;
		}
		cout << "copy parentData: " << parentData << endl;
		arr[i] = parentData;//lowers parentData. SWAPS the parentData
	}
}
