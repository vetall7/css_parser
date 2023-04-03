#pragma once
template<typename T>
class single1_list {
public:
	single1_list();
	~single1_list();
	size_t GetSize() const{
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
		T data;
		Node(T data = T(), Node* pNext = nullptr) : data (data) , pNext (pNext){
		}
	};
	size_t Size;
	Node<T>* head;
};

