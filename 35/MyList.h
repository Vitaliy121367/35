#pragma once
#include <iostream>
using std::cout;
using std::endl;

namespace mylist {

	template<typename T>
	class Node {
	public:
		T info;
		Node* next;

		Node(T value) { info = value; next = nullptr; }
		void showNode() {
			cout << "INFO: " << info << "\tNEXT: " << next << endl;
		}
	};

	template <typename T>
	class MyList {
		Node<T>* head;
		Node<T>* current;
	public:
		MyList() { head = current = nullptr; }

		void push_back(T value) {
			Node<T>* el = new Node<T>(value);

			if (head == nullptr) {
				head = el;
				current = el;
			}
			else {
				current->next = el;
				current = el;
			}
		}

		void showList() {
			Node<T>* p = head;
			while (p != nullptr) {
				p->showNode();
				p = p->next;
			}
			cout << endl;
		}
	};

}