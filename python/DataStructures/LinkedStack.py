#/usr/bin/env python3
# LinkedStack implementation
# From Michael T. Goodrich's Data Structures and Algorithms in Python

class LinkedStack():
    """LIFO Stack implementation using a singly linked list for storage."""

    # Nested _Node class
    class _Node:
        """Lightweight, nonpublic class for storing a singly linked node."""
        __slots__ = '_element', '_next'     # Streamline memory usage.

        def __init__(self, element, next):  # Inititalize node's fields
            self._element = element         # Reference to user's element.
            self._next = next               # Reference to next node

    # LinkedStack methods
    def __init__(self):
        """Create an empty stack."""
        self._head = None                   # Reference to the head node.
        self._size = 0                      # Number of stack elements.

    def __len__(self):
        """Return the number of elements in the stack."""
        return self._size

    def is_empty(self):
        """Return True if the stack is empty."""
        return self._size == 0

    def push(self, e):
        """Add element e to the top of the stack."""
        self._head = self._Node(e, self._head) # Create and link a new node
        self._size += 1

    def top(self):
        """Return (but do not remove) the element at the top of the stack.


        Raise Empty exception if the stack is empty.
        """
        if self.is_empty():
            raise Empty('Stack is empty')
        return self._head._element      # Top of stack is at head of list.

    def pop(self):
        """Remove and return the element from the top of the stack (i.e., LIFO)

        Raise Empty exception if the stack is empty.
        """
        if self.is_empty():
            raise Empty('Stack is empty')
        top = self._head._element
        self._head = self._head._next   # Bypass the former top node
        self._size -= 1
        return top



def main():
    stack = LinkedStack()
    for i in range(10):
        stack.push(i)

    print('Length: {}'.format(len(stack)))
    print('Top: {}'.format(stack.top()))

    for i in range(len(stack)):
        print(stack.pop(), end=' ')

    print()

if __name__ == '__main__':
    main()
