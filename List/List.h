#pragma once

#include <malloc.h>

#pragma warning(disable : 6011)

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
		Iterator(Node* node = nullptr) noexcept
			: _node(node) {}

		Iterator& operator++() noexcept
		{
			_node = _node->_next;
			return *this;
		}

		bool operator==(const Iterator& iterator) noexcept
		{
			return _node == iterator._node;
		}

		bool operator!=(const Iterator& iterator) noexcept
		{
			return _node != iterator._node;
		}

		T& operator*() noexcept
		{
			return _node->_data;
		}

	private:
		Node* _node;
	};

public:
	Iterator begin(void) const noexcept
	{
		return Iterator(_head->_next);
	}

	Iterator end(void) const noexcept
	{
		return Iterator(_tail);
	}

public:
	List() noexcept
		: _size(0)
	{
		_head = static_cast<Node*>(malloc(sizeof(Node) * 2));
		_tail = _head + 1;

		_head->_prev = nullptr;
		_head->_next = _tail;

		_tail->_prev = _head;
		_tail->_next = nullptr;
	}

	~List() noexcept {}

	size_t size(void) const noexcept
	{
		return _size;
	}

	bool empty(void) const noexcept
	{
		return 0 == _size;
	}

private:
	size_t _size;
	Node* _head;
	Node* _tail;
};
