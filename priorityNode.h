#pragma once
struct nodePQ{
	int info=0;
	//bst logic
	nodePQ* left = nullptr;
	nodePQ* right = nullptr;
	nodePQ* parent = nullptr;
	//linked list logic
	nodePQ* back = nullptr;
	nodePQ* next = nullptr;
};