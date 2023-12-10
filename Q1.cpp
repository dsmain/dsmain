#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insertAtBeginning(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPosition(int i, int x) {
        if (i == 0) {
            insertAtBeginning(x);
            return;
        }

        Node* newNode = new Node(x);
        Node* current = head;
        int position = 0;

        while (current && position < i - 1) {
            current = current->next;
            position++;
        }

        if (!current) {
            std::cout << "Position out of bounds." << std::endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void removeFromBeginning() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void removeFromPosition(int i) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        if (i == 0) {
            removeFromBeginning();
            return;
        }

        Node* current = head;
        int position = 0;

        while (current && position < i - 1) {
            current = current->next;
            position++;
        }

        if (!current || !current->next) {
            std::cout << "Position out of bounds." << std::endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    Node* searchElement(int x) {
        Node* current = head;

        while (current) {
            if (current->data == x) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    SinglyLinkedList linkedList;
    linkedList.insertAtBeginning(3);
    linkedList.insertAtBeginning(2);
    linkedList.insertAtBeginning(1);
    linkedList.display();

    linkedList.insertAtPosition(1, 5);
    linkedList.display();

    linkedList.removeFromBeginning();
    linkedList.display();

    linkedList.removeFromPosition(1);
    linkedList.display();

    Node* searchResult = linkedList.searchElement(5);
    if (searchResult) {
        std::cout << "Element 5 found at position: " << searchResult->data << std::endl;
    } else {
        std::cout << "Element 5 not found." << std::endl;
    }

    return 0;
}
