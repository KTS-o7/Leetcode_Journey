class MyQueue {
private:
    stack<int> s1, s2;  // Two stacks to implement the queue

    // Helper function to move elements from s1 to s2 if s2 is empty
    void moveElements() {
        if (s2.empty()) {
            // Transfer elements from s1 to s2 until s1 is empty
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

public:
    MyQueue() {}  // Constructor for initializing the queue

    // Function to add an element to the back of the queue
    void push(int x) {
        s1.push(x);
    }

    // Function to remove and return the element from the front of the queue
    int pop() {
        moveElements();  // Ensure elements are in the correct stack (s2)

        // Retrieve and remove the front element from s2
        int front = s2.top();
        s2.pop();
        return front;
    }

    // Function to return the element at the front of the queue without removing it
    int peek() {
        moveElements();  // Ensure elements are in the correct stack (s2)

        // Return the front element of s2 without removing it
        return s2.top();
    }

    // Function to check if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

// Time complexity: O(1) for push(), O(1) amortized for pop(), O(1) amortized for peek(), O(1) for empty()
// Space complexity: O(n) for n elements in the queue

/*Code explained:
Initialization:

Create two stacks, s1 and s2, to represent the queue.
Function push(x):

Add an element x to the back of the queue by pushing it onto s1.
Function pop():

If s2 is empty, move elements from s1 to s2 using the moveElements helper function.
Retrieve and remove the front element from s2 (since elements are in the correct order after the move).
Return the retrieved element.
Function peek():

If s2 is empty, move elements from s1 to s2 using the moveElements helper function.
Return the front element of s2 without removing it.
Helper Function moveElements():

If s2 is empty:
While s1 is not empty, transfer elements from s1 to s2 by pushing the top element from s1 to s2 and popping it from s1.
Function empty():

Return true if both s1 and s2 are empty, indicating an empty queue.*/