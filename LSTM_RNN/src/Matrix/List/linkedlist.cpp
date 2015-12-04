/*
 * linkedlist.cpp
 *
 *  Created on: Dec 4, 2015
 *      Author: zonglin
 */

#include "linkedlist.h"
#include <stdexcept>

namespace std
{
linkedlist::linkedlist()
{
	size_ = 0;
	head_.next_ = &tail_;
	head_.previous_ = 0;
	tail_.previous_ = &head_;
	tail_.next_ = 0;
}

void linkedlist::add(double* element)
{
	insert(element, size_);
}

void linkedlist::insert(double* element, int index)
{
	if(index > size_)
		throw runtime_error("index out of bound");
	helper* newelement = new helper();
	newelement->value_ = element;
	helper* current = &head_;
	for(int i = 0; i < index; i++)
	{
		current = current->next_;
	}
	newelement->previous_ = current;
	newelement->next_ = current->next_;
	current->next_->previous_ = newelement;
	current->next_ = newelement;
	size_ ++;
}

void linkedlist::remove(int index)
{
	if(index >= size_)
		throw runtime_error("index out of bound");
	helper* current = &head_;
	for(int i = 0; i <= index; i++)
		current = current->next_;
	current->previous_->next_ = current->next_;
	current->next_->previous_ = current->previous_;
	delete current;
}

double* linkedlist::operator[](int index)
{
	if(index >= size_)
		throw runtime_error("index out of bound");
	helper* current = &head_;
	for(int i = 0; i <= index; i++)
		current = current->next_;
	return current->value_;
}

linkedlist::~linkedlist()
{
	for(int i = 0; i < size_; i++)
		remove(i);
}

} /* namespace std */
