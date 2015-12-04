/*
 * linkedlist.h
 *
 *  Created on: Dec 4, 2015
 *      Author: zonglin
 */

#ifndef MATRIX_LIST_LINKEDLIST_H_
#define MATRIX_LIST_LINKEDLIST_H_

namespace std
{

class linkedlist
{
private:
	int size_;
	struct helper{
		helper* next_;
		helper* previous_;
		double* value_;
	};
	helper head_;
	helper tail_;
public:
	linkedlist();
	void add(double* element);
	void insert(double* element, int index);
	void remove(int index);
	double* operator[](int index);
	virtual ~linkedlist();
};

} /* namespace std */

#endif /* MATRIX_LIST_LINKEDLIST_H_ */
