#pragma once
#define DEFAULT_STACK  20
#define _SCL_SECURE_NO_WARNINGS
template <class T>
class Stack {
public:
	Stack(unsigned int capacity = DEFAULT_STACK);  // constructs a stack with initial capacity of capacity
	~Stack();  // destructor
	void replaceContainer();
	bool isEmpty() const;
	// returns true if stack is empty, and false otherwise   
	void push(T &k);
	// put k on top of the stack;
	// PRECONDITION: stack cannot be full
	T pop();
	// Remove and return the top element from the stack;
	// PRECONDITION: stack cannot be empty already
	T peek() const;
	// return the top element without modifying the stack; 
	// PRECONDITION: stack cannot be empty
	int getSize() { return _size; }
private:
	int _size;
	T * m_container;
	int  m_top;
	unsigned int  m_max_capacity;
};

template <class T>
Stack<T> ::Stack(unsigned int capacity) {
	_size = 0;
	m_max_capacity = capacity;
	m_container = new T[capacity];
	m_top = -1;
}

template <class T>
Stack<T>::~Stack() {
	delete m_container;
}

template <class T>
void Stack<T>::replaceContainer() {
	T* newContainer;
	newContainer = new T[m_max_capacity * 2];
	m_max_capacity = m_max_capacity * 2;
	std::copy(m_container, m_container + m_top + 1, newContainer);
	delete[] m_container;
	m_container = newContainer;

}
//doubles the size of the underlying array (probably don't use this)

template <class T>
bool Stack<T> ::isEmpty() const {
	return (m_top == -1);
}


template <class T>
void Stack<T> ::push(T &k) {
	_size++;
		if (m_top == (m_max_capacity - 1)) {
			replaceContainer();
		}
		m_top++;
		m_container[m_top] = k;
	
}

template <class T>
T Stack<T> ::pop() {
	_size--;
	// PRECONDITION: stack should not be empty
	T returnVal = m_container[m_top];
	m_top--;
	return returnVal;
}

template <class T>
T Stack<T> ::peek() const {
	// PRECONDITION: stack should not be empty
	return m_container[m_top];
}
