#pragma once
#include <iostream>


template<class Type>
class DequeNode {
private:
	Type information;
	DequeNode<Type>* next;
	DequeNode<Type>* prev;
public:
	DequeNode(const Type& newInformation = Type{}, DequeNode<Type>* newNext = nullptr, DequeNode<Type>* newPrev = nullptr);
	~DequeNode();
	
	Type &getInformatinon();
	void setInformation(const Type& newInformation);

	DequeNode<Type>* getNext();
	void setNext(DequeNode<Type>* newNext);
	
	DequeNode<Type>* getPrev();
	void setPrev(DequeNode<Type>* newPrev);
};

template<class Type>
class Deque
{
private:
	int dequeSize;
	DequeNode<Type>* start;
	DequeNode<Type>* end;
public:
	Deque();
	~Deque();
	
	void pushTop(const Type &newElement);
	void pushBack(const Type& newElement);

	Type &top() const;
	Type &back() const;

	void popTop() throw(std::exception);
	void popBack() throw(std::exception);

	int size();

	void sort(bool(*compare)(Type&, Type&), const int sortingType);

	void clear();
	bool isEmpty();

	class iterator:public std::iterator<std::bidirectional_iterator_tag, Type>{
	private:
		DequeNode <Type>* current;
	public:
		iterator();
		iterator(DequeNode<Type>* newCurrent);
		iterator(const iterator &other);
		iterator& operator=(const iterator &other);
		Type &operator*() const;
		Type *operator->() const;
		bool operator==(const iterator& other) const;
		bool operator!=(const iterator& other) const;
		iterator& operator++();
		iterator operator++(int);
		iterator& operator--();
		iterator operator--(int);
	};
	
	typename Deque<Type>::iterator it_begin();
	typename Deque<Type>::iterator it_end();
};

template<class Type>
inline DequeNode<Type>::DequeNode(const Type& newInformation, DequeNode<Type>* newNext, DequeNode<Type>* newPrev)
{
	this->information = newInformation;
	this->next = newNext;
	this->prev = newPrev;
}

template<class Type>
inline DequeNode<Type>::~DequeNode()
{
	free(this->next);
	free(this->prev);
}

template<class Type>
inline Type &DequeNode<Type>::getInformatinon()
{
	return this->information;
}
	
template<class Type>
inline void DequeNode<Type>::setInformation(const Type& newInformation)
{
	this->information = newInformation;
}

template<class Type>
inline DequeNode<Type>* DequeNode<Type>::getNext()
{
	return this->next;
}

template<class Type>
inline void DequeNode<Type>::setNext(DequeNode<Type>* newNext)
{
	this->next = newNext;
}

template<class Type>
inline DequeNode<Type>* DequeNode<Type>::getPrev()
{
	return this->prev;
}

template<class Type>
inline void DequeNode<Type>::setPrev(DequeNode<Type>* newPrev)
{
	this->prev = newPrev;
}

template<class Type>
inline Deque<Type>::Deque()
{
	this->start = this->end = nullptr;
	this->dequeSize = 0;
}

template<class Type>
inline Deque<Type>::~Deque()
{
	DequeNode<Type>* currentNode = this->start;
	for (int i = 0; i < this->size(); i++) {
		DequeNode<Type>* next = currentNode->getNext();
		free(currentNode);
		currentNode = next;
	}
	this->dequeSize = 0;
}

template<class Type>
inline void Deque<Type>::pushTop(const Type& newElement)
{
	DequeNode<Type> *newNode = new DequeNode<Type>(newElement);
	if (!dequeSize) {
		this->start = this->end = newNode;
	}
	else {
		this->start->setPrev(newNode);
		newNode->setNext(this->start);
		this->start = newNode;
	}
	dequeSize++;
}

template<class Type>
inline void Deque<Type>::pushBack(const Type& newElement)
{
	DequeNode<Type> *newNode = new DequeNode<Type>(newElement);
	if (!dequeSize) {
		this->start = this->end = newNode;
	}
	else {
		this->end->setNext(newNode);
		newNode->setPrev(this->end);
		this->end = newNode;
	}
	dequeSize++;
}

template<class Type>
inline Type& Deque<Type>::top() const
{
	if (!this->dequeSize) {
		throw(std::exception("Appeal to nonexistent element"));
	}
	return this->start->getInformatinon();
}

template<class Type>
inline Type& Deque<Type>::back() const
{
	if (!this->dequeSize) {
		throw(std::exception("Appeal to nonexistent element"));
	}
	return this->end->getInformatinon();
}

template<class Type>
inline void Deque<Type>::popTop() throw(std::exception)
{
	if (!this->dequeSize) {
		throw(std::exception("Appeal to nonexistent element"));
	}
	DequeNode<Type>* deleteNode = this->start;
	if (this->dequeSize != 1) {
		this->start = deleteNode->getNext();
	}
	if (this->dequeSize == 1) {
		this->start = this->end = nullptr;
	}
	free(deleteNode);
	this->dequeSize--;
}

template<class Type>
inline void Deque<Type>::popBack() throw(std::exception)
{
	if (!this->dequeSize) {
		throw(std::exception("Appeal to nonexistent element"));
	}
	DequeNode<Type>* deleteNode = this->end;
	if (this->dequeSize != 1) {
		this->end = deleteNode->getPrev();
	}
	if (this->dequeSize == 1) {
		this->start = this->end = nullptr;
	}
	free(deleteNode);
	this->dequeSize--;
	if (this->dequeSize) {
		this->start->setPrev(this->end);
	}
}

template<class Type>
inline int Deque<Type>::size()
{
	return this->dequeSize;
}

template<class Type>
inline void Deque<Type>::sort(bool(*compare)(Type&, Type&), const int sortingType)
{
	DequeNode <Type>* currentNode;
	for (int i = 0; i < this->dequeSize; i++) {
		currentNode = this->start;
		while (currentNode->getNext() != nullptr) {
			if ( (compare(currentNode->getInformatinon(), currentNode->getNext()->getInformatinon()) && sortingType == 1) ||
				(!compare(currentNode->getInformatinon(), currentNode->getNext()->getInformatinon()) && sortingType == 2)) {
				Type temp = currentNode->getInformatinon();
				currentNode->setInformation(currentNode->getNext()->getInformatinon());
				currentNode->getNext()->setInformation(temp);
			}
			currentNode = currentNode->getNext();
		}
	}
}

template<class Type>
inline void Deque<Type>::clear()
{
	DequeNode<Type>* currentNode = this->start;
	for (int i = 0; i < this->size(); i++) {
		DequeNode<Type>* next = currentNode->getNext();
		free(currentNode);
		currentNode = next;
	}
	this->dequeSize = 0;
}

template<class Type>
inline bool Deque<Type>::isEmpty()
{
	return (!this->dequeSize);
}

template<class Type>
inline typename Deque<Type>::iterator Deque<Type>::it_begin()
{
	return Deque<Type>::iterator(this->start);
}

template<class Type>
inline typename Deque<Type>::iterator Deque<Type>::it_end()
{
	if (this->end == nullptr) {
		return Deque<Type>::iterator();
	}
	return Deque<Type>::iterator(this->end->getNext());
}

template<class Type>
inline Deque<Type>::iterator::iterator()
{
	this->current = nullptr;
}

template<class Type>
inline Deque<Type>::iterator::iterator(DequeNode<Type>* newCurrent)
{
	this->current = newCurrent;
}

template<class Type>
inline Deque<Type>::iterator::iterator(const iterator& other)
{
	this->current = other.current;
}

template<class Type>
inline typename Deque<Type>::iterator& Deque<Type>::iterator::operator=(const iterator& other)
{
	this->current = other.current;
	return (*this);
}

template<class Type>
inline typename Type& Deque<Type>::iterator::operator*() const
{
	return this->current->getInformatinon();
}

template<class Type>
inline typename Type* Deque<Type>::iterator::operator->() const
{
	return &(this->current->getInformatinon());
}

template<class Type>
inline typename bool Deque<Type>::iterator::operator==(const iterator& other) const
{
	if (this->current == other.current) {
		return true;
	}
	return false;
}

template<class Type>
inline typename bool Deque<Type>::iterator::operator!=(const iterator& other) const
{
	if (this->current == other.current) {
		return false;
	}
	return true;
}
template<class Type>
inline typename Deque<Type>::iterator& Deque<Type>::iterator::operator++()
{
	Deque<Type>::iterator temp;
	this->current = this->current->getNext();
	return temp;
}

template<class Type>
inline typename Deque<Type>::iterator Deque<Type>::iterator::operator++(int)
{
	this->current = this->current->getNext();
	return (*this);
}

template<class Type>
inline typename Deque<Type>::iterator& Deque<Type>::iterator::operator--()
{
	Deque<Type>::iterator temp;
	this->current = this->current->getPrev();
	return temp;
}

template<class Type>
inline typename Deque<Type>::iterator Deque<Type>::iterator::operator--(int)
{
	this->current = this->current->getPrev();
	return (*this);
}

