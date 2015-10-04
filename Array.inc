template <class Type>
Array<Type>::Array(int length, int start_index) : m_length(length), m_start_index(start_index)
{
	// Checks to see if the length is valid. 0-length strings are not allowed
	if (length <= 0) { throw 1; }

	// If the length is valid, allocate the array based on the length + 1 for the zero terminator
	m_array = new Type[length + 1];
	if (!m_array) { throw 2; }
}

template <class Type>
Array<Type>::Array(const Array &copy)
{
	// Delete the current array
	delete[] m_array;

	// Copy the variables 
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;

	// Create a new array and copy the data from the source to the new array
	m_array = new Type[m_length + 1];
	if (!m_array) { throw 2; }
	for (int idx = 0; idx < m_length; idx++) { m_array[idx] = rhs.m_array[idx]; }
}

template <class Type>
Array<Type> &Array<Type>::operator=(const Array &rhs)
{
	// Self-assignment check
	if (this == &rhs) { return *this; }

	// Delete the current array
	delete[] m_array;

	// Copy the variables 
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;

	// Create a new array and copy the data from the source to the new array
	m_array = new Type[m_length + 1];
	if (!m_array) { throw 2; }
	for (int idx = 0; idx < m_length; idx++) { m_array[idx] = rhs.m_array[idx]; }
	
	return *this;
}

template <class Type>
Type &Array<Type>::operator[](int index)
{
	// Checks to verify the position is correct, and if not, throw an exception
	if (index + m_start_index < m_start_index || index > m_length) { throw 3; }

	return m_array[index];
}

template <class Type>
void Array<Type>::setLength(int length)
{
	// Checks to see if the length is valid. 0-length strings are not allowed
	if (length <= 0) { throw 1; }

	// Create a new, temporary array to store a copy of the current array
	Type *TempArray = new Type[m_length + 1];
	for (int idx = 0; idx < m_length; idx++) { TempArray[idx] = m_array[idx]; }

	// Delete the current array
	delete[] m_array;

	// Set the length of the new array to the new value
	m_length = length;

	// Create a new array and copy the data from the temporary array to the new one
	m_array = new Type[m_length + 1];
	if (!m_array) { throw 2; }
	for (int idx = 0; idx < m_length; idx++) { m_array[idx] = TempArray[idx]; }

	delete[] TempArray;	
}