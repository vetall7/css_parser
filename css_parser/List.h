#pragma once

template<typename T>
class list {
public:
	list();
	~list();
	int GetSize() {
		return Size;
	}
	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void clear();
	void insert(T data, int index);

	T& operator[](const int index);

private:

	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		Node* pPrior;
		T data;
		Node(T data = T(), Node* pPrior = nullptr, Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrior = pPrior;
		}
	};
	int Size;
	Node<T>* head;
	Node<T>* tail;
};

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
	if (head == nullptr) {
		head = new Node<T>(data); // creating the node and returns address
		tail = head;
	}
	else {

		tail->pNext = new Node<T>(data);
		tail->pNext->pPrior = tail;
		tail = tail->pNext;
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
void list<T>::insert(T data, int index) {
	if (index == 0) {
		head->data = data;
	}
	else {
		Node<T>* element = new Node<T>(data);
		Node<T>* temp1 = this->head;
		Node<T>* temp2 = this->head;
		for (int i = 0; i < index; i++) {
			temp1 = temp1->pNext;
			if (i == index - 2) temp2 = temp1;
		}
		temp2->pNext = element;
		element->pNext = temp1;
	}
}

template<typename T>
void list<T>::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;
	head->pPrior = nullptr;
	delete temp;
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
T& list<T>::operator[](const int index)
{
	Node<T>* curr = this->head;
	int counter = 0;

	while (counter - 1 != index - 1) {
		curr = curr->pNext;
		counter++;
	}
	return curr->data;
}

