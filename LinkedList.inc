// Overloaded assignment operator
template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
	// Self-assignment check
	if (this == &rhs) { return *this; }

	// Clear the current list
	Purge(); 

	// Copy the variables 
	m_tail = rhs.m_tail;
	m_head = rhs.m_head;

	// Temporary node objects to be 
	Node<T> *searcher = m_head;
	Node<T> *rhs_searcher = rhs.m_head;
	Node<T> *follower = searcher;
	
	// Establishes the head of the new list
	searcher = new Node<T>;						
	searcher->m_data = rhs_searcher->m_data;	 
	m_head = searcher;							
	follower = m_head;							
	rhs_searcher = rhs_searcher->m_next;		

	// Cycle through each node on the rhs and copy the data to a new node
	while (rhs_searcher)
	{
		searcher = new Node<T>;
		searcher->m_data = rhs_searcher->m_data;
		follower->m_next = searcher;
		follower = searcher;
		if (!rhs_searcher->m_next) { m_tail = rhs_searcher; }
		rhs_searcher = rhs_searcher->m_next;
	}

	return *this;
}

// Add a new node at the beginning of the list
template <class T>
void LinkedList<T>::Prepend(T *source)
{
	Node<T> newnode = new Node<T>;		// Create a new node
	m_head->m_prev = newnode;			// Assign it to the head's previous pointer
	newnode->m_data = source;			// Give the new node the data
	newnode->m_next = m_head->m_next;	// Set the new node's next pointer to the current head's next pointer
	m_head = m_head->m_prev;			// Set the current head to point to the new node
}

// Add a new node at the end of the list
template <class T>
void LinkedList<T>::Append(T *source)
{
	Node<T> newnode = new Node<T>;		// Create a new node
	m_tail->m_next = newnode;			// Assign it to the tail's next pointer
	newnode->m_data = source;			// Give the new node the data
	newnode->m_prev = m_tail->m_prev;	// Set the new node's previous pointer to the current tail's previous pointer
	m_tail = m_tail->m_next;			// Set the current tail to point to the new node
}

// Delete the list
template <class T>
void LinkedList<T>::Purge()
{
	Node<T> *purger = 0;

	while (m_head)
	{
		purger = m_head;
		m_head = m_head->m_next;
		delete purger;
	}

	m_head, m_tail = 0;
}

// Find and extract a node from the list
template <class T>
Node<T>& LinkedList<T>::Extract(T target)
{
	Node<T> *searcher = m_head;
	Node<T> *follower = searcher;

	while (searcher != m_tail)
	{
		if (searcher->m_data == target)
		{
			follower->m_next = searcher->m_next;
			searcher->m_next->m_prev = follower;
			delete searcher;
		}
		else
		{
			follower = searcher;
			searcher = searcher->m_next;
		}
	}
}

// Find a node and insert a new node after it
template <class T>
void InsertAfter(T target, T *source)
{
	Node<T> *searcher = m_head;
	Node<T> *follower = searcher;

	while (searcher != m_tail)
	{
		if (searcher->m_data == target)
		{
			Node<T> *newnode = new Node<T>;
			newnode->m_data = source;
			follower->m_next = newnode;
			newnode->m_next = follower;
			follower->m_prev = newnode;
			newnode->m_prev = searcher;
		}
		else
		{
			follower = searcher;
			searcher = searcher->m_next;
		}
	}
}

// Find a node and insert a new node before it
template <class T>
void InsertBefore(T target, T *source)
{
	Node<T> *searcher = m_head;
	Node<T> *follower = searcher;

	while (searcher != m_tail)
	{
		if (searcher->m_data == target)
		{
			Node<T> *newnode = new Node<T>;
			newnode->m_data = source;
			follower->m_next = newnode;
			newnode->m_next = searcher;
			follower->m_prev = newnode;
			newnode->m_prev = follower;
		}
		else
		{
			follower = searcher;
			searcher = searcher->m_next;
		}
	}
}