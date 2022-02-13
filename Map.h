#pragma once

#include <iostream>

using namespace std;

template <class _Key, class _Value> class Map
{
  private:
	struct node
    {
	  public:
		node* next;
		_Key key;
		_Value val;
		node(const _Key k) : next(nullptr) { key = k; };

		~node() { delete next; }

		node(const node& s) : next(nullptr)
        {
			key = s.key;
			val = s.val;
		};

	  private:
		node& operator=(const node&);
	};

	node* head;

	node* nodeFind(const _Key key) const
    {
		node* c = head;
		while (c) {
			if (key == c->key)
            {
				return c;
			}
			c = c->next;
		};
		return nullptr;
	}

	void clear()
    {
		while (head)
        {
			node* t = head->next;
			delete head;
			head = t;
		}
	}

	void swap(Map& m)
    {
		node* t = head;
		head = m.head;
		m.head = t;
	}

  public:
	Map() { head = nullptr; }
	Map(const Map& m)
    {
		node *source, **destination;
		head = NULL;
		source = m.head;
		destination = &head;

		while (source)
        {
			*destination = new node(*source);
			source = source->next;
			destination = &((*destination)->next);
		}
	}

	~Map() { delete head; }

	Map& operator=(const Map& m)
    {
		if (&m == this) {
			return *this;
		}

		Map t(m);
		swap(t);

		return *this;
	}

	_Value* find(const _Key& key)
    {
		node* c = nodeFind(key);
		if (!c)
        {
			c = head;
		}

		return &c->val;
	}
	void add(const _Key& key, const _Value& value)
    {
		node* newnode = nodeFind(key);

		if (!newnode)
        {
			newnode = new node(key);
			newnode->next = head;
			head = newnode;
			head->val = value;
		}
        else
        {
			newnode->val = value;
		}
	}

	friend ostream& operator<<(ostream& out, const Map& m)
    {
		node* itr = m.head;

		while (itr)
        {
			out << "Key: " << itr->key << "\t";
			out << "Value: " << itr->val << "\n";
			itr = itr->next;
		}

		return out;
	}
};
