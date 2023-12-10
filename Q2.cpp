#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);

        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int x) {
        Node* newNode = new Node(x);

        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeFromBeginning() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        delete temp;
    }

    void removeFromEnd() {
        if (!tail) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    DoublyLinkedList doublyLinkedList;
    doublyLinkedList.insertAtBeginning(3);
    doublyLinkedList.insertAtBeginning(2);
    doublyLinkedList.insertAtBeginning(1);
    doublyLinkedList.display();

    doublyLinkedList.insertAtEnd(4);
    doublyLinkedList.display();

    doublyLinkedList.removeFromBeginning();
    doublyLinkedList.display();

    doublyLinkedList.removeFromEnd();
    doublyLinkedList.display();

    return 0;
}
