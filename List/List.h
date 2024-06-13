#pragma once
#pragma warning( disable : 6011 )
#include <cstdlib>

template <typename T>
class List
{
private:
	struct Node
	{
		T _data;
		Node* _prev;
		Node* _next;
	};

public:
	class Iterator
	{
	public:
		Iterator(Node* node = nullptr) noexcept : _node(node) {}

	private:
		Node* _node;
	};

public:
	List() noexcept : _size(0)
	{
		_head = static_cast<Node*>(malloc(sizeof(Node) * 2));
		_tail = _head + 1;

		_head->_prev = nullptr;
		_head->_next = _tail;

		_tail->_prev = _head;
		_tail->_next = nullptr;
	}

	~List() noexcept {}

private:
	size_t _size;
	Node* _head;
	Node* _tail;
};
