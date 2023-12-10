#include <iostream>
#include <queue>

class Queue {
private:
    std::queue<int> data;

public:
    // Enqueue (push) an element to the back of the queue
    void enqueue(int value) {
        data.push(value);
    }

    // Dequeue (pop) an element from the front of the queue
    void dequeue() {
        if (!isEmpty()) {
            data.pop();
        } else {
            std::cerr << "Error: Queue underflow." << std::endl;
            // You may want to handle the error differently
        }
    }

    // Get the front element of the queue without removing it
    int front() const {
        if (!isEmpty()) {
            return data.front();
        } else {
            std::cerr << "Error: Queue is empty." << std::endl;
            // You may want to handle the error differently
            return -1; // Placeholder value, you can choose a different approach
        }
    }

    // Check if the queue is empty
    bool isEmpty() const {
        return data.empty();
    }

    // Get the size of the queue
    size_t size() const {
        return data.size();
    }
};

int main() {
    // Example usage of the Queue ADT
    Queue myQueue;

    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    std::cout << "Front element: " << myQueue.front() << std::endl;
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    myQueue.dequeue();
    std::cout << "After dequeue, front element: " << myQueue.front() << std::endl;
    std::cout << "Queue size: " << myQueue.size() << std::endl;

    return 0;
}
