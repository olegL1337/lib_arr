#include <string>
#include <iostream>
#include "DoublList.h"
using namespace std;
template<class T>
DoublyList<T>::DoublyList() {
	head = NULL;
	tail = NULL;
}
template<class T>
void DoublyList<T>::pushBack(T _data) {
	//(*tail).next=new Node(_data);
	if (head != NULL) {
		tail->next = new DoublyNode<T>(_data);
		tail->next->prev = tail;
		tail = tail->next;
	} else {
		head = new DoublyNode<T>(_data);
		tail = head;
	}
}
template<class T>
void DoublyList<T>::print(char *end_, char type) const {
	cout << endl;
	if (head == NULL) {
		cout << "List is emply" << endl;
		return;
	}
	if (type == '+') {
		DoublyNode<T> *ptr = head;
		while (ptr != NULL) {
			cout << ptr->data << end_;
			ptr = ptr->next;
		}
		cout << endl;
	}
	if (type == '-') {
		DoublyNode<T> *ptr = tail;
		while (ptr != NULL) {
			cout << ptr->data << end_;
			ptr = ptr->prev;
		}
		cout << endl;
	}
}
template<class T>
int DoublyList<T>::size() {
	int number = 0;
	if (head == NULL) {
		return 0;
	}
	DoublyNode<T> *ptr = head;
	while (ptr != NULL) {
		number++;
		ptr = ptr->next;
	}
	return number;
}
template<class T>
void DoublyList<T>::replace(int i, int j) {
	DoublyNode<T> *ptr1 = head;
	DoublyNode<T> *ptr2 = head;
	while (i != 0) {
		if (ptr1 == NULL) {
			cout << "Error: list index out of range" << endl;
			return;
		}
		ptr1 = ptr1->next;
		i--;
	}
	while (j != 0) {
		if (ptr2 == NULL) {
			cout << "Error: list index out of range" << endl;
			return;
		}
		ptr2 = ptr2->next;
		j--;
	}
	swap(ptr1->data, ptr2->data);
}
template<class T>
void DoublyList<T>::pop(int i) {
	if (i < 0 || i + 1 > size()) {
		cout << "Error: list index out of range" << endl;
		return;
	}
	DoublyNode<T> *ptr = head;
	while (i > 0) {
		if (ptr->next == tail) {
			delete ptr->next;
			ptr->next = NULL;
			tail = ptr;
			return;
		}
		i--;
		if (i == 0) {
			DoublyNode<T> *ptr1 = ptr->next;
			ptr->next = ptr->next->next;
			delete ptr1;
			return;
		} else
			ptr = ptr->next;
	}
	if (ptr == head && ptr == tail)
		clear();
	else {
		head = head->next;
		delete ptr;
	}
}
template<class T>
void DoublyList<T>::insert(int i, T elem) {
	DoublyNode<T> *ptr = head;
	if (i > size()) {
		cout << "Error: list index out of range" << endl;
		return;
	}
	if (i == size()) {
		puchBack(elem);
		return;
	}
	if (i == 0) {
		head = new DoublyNode<T>(elem);
		head->next = ptr;
		ptr->prev = head;
		return;
	}
	DoublyNode<T> *ptr1;
	while (i != 1) {
		ptr = ptr->next;
		i--;
	}
	ptr1 = ptr->next;
	ptr->next = new DoublyNode<T>(elem);
	ptr1->prev = ptr->next;
	ptr->next->prev = ptr;
	ptr->next->next = ptr1;
}
template<class T>
DoublyNode<T> * DoublyList<T>::getValue(int i) {
	DoublyNode<T> *ptr = head;
	for (int k = 0; k < i; k++) {
		ptr = ptr->next;
	}
	return ptr;
}
template<class T>
void DoublyList<T>::reverse() {
	int n = size();
	for (int i = 0; i < n / 2; i++) {
		replace(i, n - i - 1);
	}
}
template<class T>
void DoublyList<T>::clear() {
	if (head == NULL)
		return;
	DoublyNode<T> *ptr = head;
	while (ptr != NULL) {
		head = head->next;
		delete ptr;
		ptr = head;
	}
	head = NULL;
	tail = NULL;
}
template<class T>
void DoublyList<T>::sort(string sing) {
	if (sing == "+") {
		for (int i = 0; i < size() - 1; i++) {
			for (int j = 0; j < size() - i - 1; j++) {
				if (getValue(j) > getValue(j + 1)) {
					replace(j, j + 1);
				}
			}
		}
	}
}
template<class T>
int DoublyList<T>::find(T elem) {
	for (int i = 0; i < size(); i++) {
		if (getValue(i)->data == elem) {
			return i;
		}
	}
	return -1;
}
template<class T>
void DoublyList<T>::extend(DoublyList *doublylist) {
	for (int i = 0; i < doublylist->size(); i++) {
		puchBack(doublylist->getValue(i)->data);
	}
}
template<class T>
DoublyList<T>::~DoublyList() {
	if (head == NULL)
		return;
	DoublyNode<T> *ptr = head;
	while (ptr != NULL) {
		head = head->next;
		delete ptr;
		ptr = head;
	}
}
