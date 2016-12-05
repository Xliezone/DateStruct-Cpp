#include <iostream>
#include <vector>

using namespace std;

typedef struct Node
{
	int weight = 0;
	Node* left = nullptr;
	Node* right = nullptr;
}* huffmanTree;

typedef struct Heap
{
	int size = 0;
	vector<huffmanTree> element;
}* Minheap;

void precDown(Minheap& h, int index)
{
	auto data = h->element[index];
	auto parent = index;
	while (parent*2 <= h->size)
	{
		auto child = parent * 2;
		if (child < h->size && h->element[child]->weight > h->element[child+1]->weight)
		{
			child++;
		}
		if (data->weight <= h->element[child]->weight)
		{
			break;
		}
		h->element[parent] = h->element[child];
		parent = child;
	}
	h->element[parent] = data;
}

void build(Minheap& h)
{
	for (int i = h->size/2; i > 0; i--)
	{
		precDown(h,i);
	}
}

huffmanTree delet(Minheap& h)
{
	auto data = h->element[1];
	auto last = h->element[h->size];
	h->size--;
	auto parent = 1;
	while (parent*2 <= h->size)
	{
		auto child = parent * 2;
		if (child < h->size && h->element[child]->weight > h->element[child + 1]->weight)
		{
			child++;
		}
		if (last->weight <= h->element[parent]->weight)
		{
			break;
		}
		h->element[parent] = h->element[child];
		parent = child;
	}
	h->element[parent] = last;
	return data;
}

void insert(Minheap& h, huffmanTree T)
{
	h->size++;
	h->element.push_back(T);
	auto pos = h->size;
	while (T->weight < h->element[h->size / 2]->weight) {
		h->element[pos] = h->element[pos / 2];
		pos /= 2;
	}
	h->element[pos] = T;
}

huffmanTree huffman(Minheap& h)
{
	int i;
	huffmanTree T;
	build(h);
	for (int i = 1; i < h->size; i++)
	{
		T = new Node;
		T->left  = new Node;
		T->left = delet(h);
		T->right = delet(h);
		T->weight = T->left->weight + T->right->weight;
		insert(h, T);
	}
	T = delet(h);
	return T;
}