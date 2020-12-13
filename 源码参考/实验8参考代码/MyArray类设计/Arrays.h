/*************************************************
* Head File   : Arrays.h
* File Usage  : 数组类设计
/**************************************************/

#ifndef __ARRAYS_H__
#define __ARRAYS_H__

class MyArray
{

private:
	int *ps;
	int size;

public:
	
	MyArray(int _size=20);
	MyArray(const MyArray &r);
	~MyArray();

	void show();
	MyArray& modifyArray();

	MyArray& operator=( const MyArray &r);
	MyArray operator+( const MyArray &r);

	friend MyArray operator-(MyArray &r1, MyArray &r2);

};
	

#endif

