#pragma once
class maxHeap {
	int* arr;
	int cnt;//1 past index. ACTUAL cnt
	int heapSize;
public:
	maxHeap(int n=1) :heapSize(n) {
		arr = new int[n];
		cnt = 0;
	}
	maxHeap(int arr[], int size);
	void heapify(int i);
	void preorder(int i = 0);
	void display();
	void enqueue(const int&);
	bool dequeue(int &);
	void reallocate();
	void reallocate(int);
	~maxHeap() {
		delete arr;
		heapSize = 0;
		arr = nullptr;
	}
	//pre: checks if element at index=i has a valid child
	//post: heapifies the member array downwards so long as a parent has a valid child

};