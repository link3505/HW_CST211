#ifndef Array_H
#define Array_H

using namespace std;

template <class Type>
class Array
{
public:

	Array();								// Default constructor
	Array(int length, int start_index = 0);	// Defined constructor
	Array(const Array &copy);				// Copy-constructor
	~Array() { delete[] m_array; }			// Destructor

	Array &operator=(const Array &rhs);		// Overloaded assignment operator
	Type &operator[](int index);			// Overloaded index operator

	int getLength() { return m_length; }	// Returns the length of the array
	int getStartIndex() { return m_start_index; }	// Returns the starting index of the array
	void setLength(int length);						// Sets the array's length
	void setStartIndex(int start_index) { m_start_index = start_index; } // Sets the starting index of the array
	
private:

	Type *m_array;		// The array pointer
	int m_length;		// The length of the array
	int m_start_index;	// The starting index of the array
};

#include "Array.inc"

#endif