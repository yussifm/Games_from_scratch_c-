#include <iostream>
#include <memory>
#include <utility>

class Node {
public:
    int value;
    std::shared_ptr<Node> next;   // Shared pointer for the next node
    std::weak_ptr<Node> prev;     // Weak pointer for the previous node to avoid cyclic references

    Node(int value) : value(value), next(nullptr), prev(std::weak_ptr<Node>()) {}
};

class LinkedList {
private:
    std::shared_ptr<Node> head;   // Head node of the list
    std::shared_ptr<Node> tail;   // Tail node of the list
    int length;                   // Length of the list

public:
    LinkedList(int value) {
        // Initialize list with a single node
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void append(int value) {
        // Add a new node at the end of the list
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if (length == 0) {
            // If the list is empty, initialize head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Update tail node pointers to include the new node
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        // Remove the last node in the list
        if (length == 0) return;

        if (length == 1) {
            // If there's only one node, reset head and tail to null
            head = nullptr;
            tail = nullptr;
        } else {
            // Set the tail to the previous node and remove the last node
            tail = tail->prev.lock();  // Use lock to get a shared_ptr from weak_ptr
            tail->next = nullptr;
        }
        length--;
    }

    void prepend(int value) {
        // Add a new node at the beginning of the list
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        if (length == 0) {
            // If the list is empty, initialize head and tail
            head = newNode;
            tail = newNode;
        } else {
            // Update head node pointers to include the new node
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        // Remove the first node in the list
        if (length == 0) return;

        if (length == 1) {
            // If there's only one node, reset head and tail to null
            head = nullptr;
            tail = nullptr;
        } else {
            // Set the head to the next node and remove the first node
            head = head->next;
            head->prev.reset();  // Reset prev to avoid dangling weak pointer
        }
        length--;
    }

    std::shared_ptr<Node> getByIndex(int index) {
        // Retrieve a node by its index
        if (index < 0 || index >= length) {
            std::cout << "Index out of bounds" << std::endl;
            return nullptr;
        }
        std::shared_ptr<Node> temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    bool setByIndex(int index, int value) {
        // Set the value of a node at a specific index
        std::shared_ptr<Node> temp = getByIndex(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        // Insert a new node at a specific index
        if (index < 0 || index > length) {
            std::cout << "Index out of bounds" << std::endl;
            return false;
        }

        if (index == 0) {
            // Insert at the head (beginning) of the list
            prepend(value);
            return true;
        }

        if (index == length) {
            // Insert at the tail (end) of the list
            append(value);
            return true;
        }

        // General case: Insert in the middle of the list
        std::shared_ptr<Node> newNode = std::make_shared<Node>(value);
        std::shared_ptr<Node> temp = getByIndex(index - 1);
        
        newNode->next = temp->next;           // Link the new node to the next node
        newNode->prev = temp;                 // Set the new node's previous pointer
        temp->next->prev = newNode;           // Update the next node's previous pointer
        temp->next = newNode;                 // Link the previous node to the new node

        length++;
        return true;
    }

    void deleteNode(int index) {
        // Delete a node at a specific index
        if (index < 0 || index >= length) {
            std::cout << "Index out of bounds" << std::endl;
            return;
        }

        if (index == 0) {
            // Delete the first node
            deleteFirst();
            return;
        }

        if (index == length - 1) {
            // Delete the last node
            deleteLast();
            return;
        }

        // General case: Delete a node in the middle of the list
        std::shared_ptr<Node> temp = getByIndex(index);
        temp->prev.lock()->next = temp->next;  // Update previous node's next pointer
        temp->next->prev = temp->prev;         // Update next node's previous pointer

        length--;
    }

    void reverseList() {
        // Reverse the entire linked list
        if (length <= 1) return;

        std::shared_ptr<Node> temp = nullptr;
        std::shared_ptr<Node> current = head;
        tail = head;

        while (current != nullptr) {
            // Reverse pointers for each node
            temp = current->prev.lock();
            current->prev = current->next;
            current->next = temp;
            current = current->prev.lock();
        }

        if (temp) {
            // Update head to the new first node
            head = temp->prev.lock();
        }
    }

    void printList() {
        // Print all node values in the list
        std::shared_ptr<Node> temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << std::endl;
            temp = temp->next;
        }
    }

    void getLength() {
        // Print the length of the list
        std::cout << "Length: " << length << std::endl;
    }

    void getHead() {
        // Print the value of the head node
        if (head) {
            std::cout << "Head: " << head->value << std::endl;
        } else {
            std::cout << "Head is null" << std::endl;
        }
    }

    void getTail() {
        // Print the value of the tail node
        if (tail) {
            std::cout << "Tail: " << tail->value << std::endl;
        } else {
            std::cout << "Tail is null" << std::endl;
        }
    }
};

int main() {
    // Create a linked list with an initial value of 2
    auto myLinkedList = std::make_unique<LinkedList>(2);

    // Perform various operations on the list
    myLinkedList->append(3);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();

    myLinkedList->deleteLast();
    myLinkedList->append(4);
    myLinkedList->append(5);
    myLinkedList->prepend(1);

    myLinkedList->deleteFirst();
    std::cout << "Get value: " << myLinkedList->getByIndex(2)->value << std::endl;
    myLinkedList->setByIndex(2, 7);
    std::cout << "Get value: " << myLinkedList->getByIndex(2)->value << std::endl;
    myLinkedList->insert(1, 10);

    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();

    myLinkedList->reverseList();
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();

    return 0;
}
