#include <iostream>
#include <vector>
#include "priorityQ.h"
#include "linkedPriorityBT.h"
using namespace std;
/*
class A {
public:
	int x=0;
	int* ptrx=nullptr;
public:
	A(int x2 = 0, int* ptrx2 = nullptr) {
		x = x2;
		ptrx = ptrx2;
	}
	void move(int&& x) {
		this->x = x;
	}
	void move(A&& a) {
		ptrx=a.ptrx;
		a.ptrx = nullptr;
		x = a.x;
	}
};
template<class T>
void insert(vector<T> &v);
*/
int main() {
	const int SIZE = 5;
	int arrL[SIZE] = { 1,2,3,4,5 };
	linkedBSPQ obj(arrL, SIZE);
	obj.display();
	obj.enqueue(6);
	obj.display();
	int num;
	obj.dequeue(num);
	obj.display();
	cout << num << endl;
	/* array queue
	const int SIZE = 4;
	int arr[SIZE] = {1,2,3,4};
	maxHeap obj(arr,SIZE);
	obj.enqueue(5);
	obj.display();
	obj.enqueue(6);
	obj.display();
	int rem;
	obj.dequeue(rem);
	obj.display();
	*/
/*
	A obj;
	int h = 12;
	A obj2(0, &h);
	A(0, &h);
	obj.move(A(0,&h));
	cout << *(obj.ptrx)<<endl;
	return 0;
	*/
	return 0;
}