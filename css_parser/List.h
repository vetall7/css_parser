#pragma once


template<typename T>
class list {
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
public:
	list();
	~list();
	int GetSize() const {
		return Size;
	}
	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void clear();
	void remove_element(size_t index);
	T& search_reverse(int index);
	T& operator[](const int index) const;

	class Iterator {
	private:
		Node<T>* current_node;
	public:
		Iterator(Node<T>* node) : current_node(node) {}
		bool operator==(const Iterator& other) const {
			return current_node == other.current_node;
		}
		bool operator!=(const Iterator& other) const {
			return !(*this == other);
		}
		T& operator*() const {
			return current_node->data;
		}
		Iterator& operator++() {
			current_node = current_node->pNext;
			return *this;
		}
		Iterator operator++(int) {
			Iterator iterator = *this;
			++(*this);
			return iterator;
		}
	};

	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		return Iterator(nullptr);
	}
};

