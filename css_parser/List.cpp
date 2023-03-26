#include "List.h"

template <typename T>
list<T>::list() {
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
list<T>::~list()
{
	clear();
}

template<typename T>
void list<T>::push_back(T data)
{
	Node<T>* node = new Node<T>(data);
	if (head == nullptr) {
		head = node;
		tail = head;
	}
	else {
		tail->pNext = node;
		node->pPrior = tail;
		tail = node;
	}
	Size++;
}


template<typename T>
void list<T>::clear() {
	while (Size) { 
		pop_front();
	}
}

template<typename T>
void list<T>::remove_element(size_t index)
{
	if (index >= Size) {
		return;
	}
	if (index == 0) {
		pop_front();
		return;
	}
	if (index == Size - 1) {
		pop_back();
		return;
	}
	Node<T>* current = head;
	int i = 0;
	while (i != index) {
		current = current->pNext;
		i++;
	}
	current->pPrior->pNext = current->pNext;
	current->pNext->pPrior = current->pPrior;
	delete current;
	Size--;
}

template<typename T>
void list<T>::pop_front() {
	if (head == nullptr) {
		// the list is empty, do nothing
		return;
	}
	if (head == tail) {
		// there is only one element in the list
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<T>* temp = head;
		head = head->pNext;
		head->pPrior = nullptr;
		delete temp;
	}
	Size--;
}

template<typename T>
void list<T>::pop_back() {
	Node<T>* temp = tail;
	tail->pPrior->pNext = nullptr;
	tail = temp->pPrior;
	delete temp;
	Size--;
}


template<typename T>
void list<T>::push_front(T data) {
	if (head == nullptr) {
		head = new Node<T>(data);
		tail = head;
	}
	else {
		Node<T>* first_element = new Node<T>(data);
		first_element->pNext = head;
		head = first_element;
		head->pNext->pPrior = head;
	}
	Size++;
}


template<typename T>
T& list<T>::search_reverse(int index)
{
	Node<T>* current = tail;
	int counter = GetSize();
		while (current != nullptr) {
			if (counter == index) {
				return current->data;
			}
			current = current->pPrior;
			counter--;
		}
		return current->data;
}

template<typename T>
T& list<T>::operator[](const int index) const
{
	Node<T>* curr = this->head;
	int counter = 0;

	while (counter - 1 != index - 1) {
		curr = curr->pNext;
		counter++;
	}
	return curr->data;
}
