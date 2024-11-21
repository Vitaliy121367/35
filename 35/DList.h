#pragma once
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class DNode {
public:
	T info;
	DNode* prev;
	DNode* next;

	DNode(T value) { info = value; next= prev = nullptr; }
	void showDNode() {
		cout << "INFO: " << info<<endl;
		cout << "\tPREV: " << prev << endl;
		cout << "\tNEXT: " << next << endl;
	}
};
template <typename T>
class DList {
	DNode<T>* head;
	DNode<T>* current;
public:
	DList() { head = current = nullptr; }

	void push_back(T value) {
		DNode<T>* el = new DNode<T>(value);
		if (head == nullptr) {
			head = el;
			current = el;
		}
		else {
			current->next = el;
			el->prev = current;
			current = el;
		}
	}
	void showList() {
		DNode<T>* p = head;
		while (p != nullptr) {
			p->showDNode();
			p = p->next;
		}
		cout << endl;
	}

	void showRList() {
		DNode<T>* p = current;
		while (p != nullptr) {
			p->showDNode();
			p = p->prev;
		}
		cout << endl;
	}
	
	DNode<T>* search(T value) {
		DNode<T>* p = head;
		while (p != nullptr) {
			if (p->info == value)
			{
				return p;
			}
			p = p->next;
		}
		return nullptr;
	}

	void destruct() {
		DNode<T>* p = head;
		DNode<T>* pdel = head;
		while (p != nullptr) {
			cout << "Del: ";
			p->showDNode();
			pdel = p;
			p = p->next;
			if (pdel != nullptr)
			{
				delete pdel;
			}
		}
	}
};