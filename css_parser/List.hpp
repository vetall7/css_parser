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
	void remove_element(size_t index);
	T& search_reverse(int index);
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

