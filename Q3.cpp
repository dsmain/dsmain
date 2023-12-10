#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int x) {
        Node* newNode = new Node(x);

        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void remove(int x) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;

        do {
            if (current->data == x) {
                if (prev) {
                    prev->next = current->next;
                    delete current;
                    return;
                } else {
                    if (current->next == head) {
                        head = nullptr;
                    } else {
                        Node* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = head->next;
                        head = head->next;
                        delete current;
                    }
                    return;
                }
            }

            prev = current;
            current = current->next;
        } while (current != head);

        std::cout << "Element " << x << " not found." << std::endl;
    }

    Node* search(int x) {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return nullptr;
        }

        Node* current = head;

        do {
            if (current->data == x) {
                return current;
            }

            current = current->next;
        } while (current != head);

        std::cout << "Element " << x << " not found." << std::endl;
        return nullptr;
    }

    void display() {
        if (!head) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Node* current = head;

        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);

        std::cout << "Head" << std::endl;
    }
};

int main() {
    CircularLinkedList circularLinkedList;
    circularLinkedList.insert(1);
    circularLinkedList.insert(2);
    circularLinkedList.insert(3);
    circularLinkedList.display();

    circularLinkedList.remove(2);
    circularLinkedList.display();

    Node* searchResult = circularLinkedList.search(3);
    if (searchResult) {
        std::cout << "Element 3 found at address: " << searchResult << std::endl;
    }

    return 0;
}
