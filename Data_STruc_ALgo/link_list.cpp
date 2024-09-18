#include <iostream>
#include <memory>
#include <utility>


class Node {
public:
	int value;
	std::unique_ptr<Node> next;
	 Node(int value) : value(value), next(nullptr) {}
};

class LinkedList {
private:
	std::unique_ptr<Node> head;
	Node* tail;
	int length;

public:
	LinkedList(int value){
		std::unique_ptr<Node> newNode = std::make_unique<Node>(Node(value));
		head = std::move(newNode);
		tail = head.get();
		length = 1;
	}

	 void append(int value){
    	std::unique_ptr<Node> newNode = std::make_unique<Node>(Node(value));
    	if(length == 0){
    		head = std::move(newNode);
    		tail = head.get();
    	}
    	else {
    		tail->next = std::move(newNode);
    		tail = tail->next.get();
    	}
    	length++;
    }

    void deleteLast() {
    if (length == 0) return;

    if (length == 1) {
        head = nullptr; 
        tail = nullptr;
    } else {
        Node* temp = head.get();
        Node* pre = nullptr;

        while (temp->next) {
            pre = temp;
            temp = temp->next.get();
        }

        tail = pre;               // Update tail to the second-to-last node
        tail->next = nullptr;     // Release ownership of the last node (via unique_ptr)
    }

    length--;
}

void prepend(int value) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);

    if (length == 0) {
        head = std::move(newNode);  // Move ownership to head
        tail = head.get();          // Set tail to point to the new head
    } else {
        newNode->next = std::move(head);  // Link the new node to the current head
        head = std::move(newNode);        // Update head to the new node
    }
    length++;
}

void deleteFirst() {
    if (length == 0) return;

    if (length == 1) {
        head = nullptr;  // Automatically deletes the node managed by head
        tail = nullptr;
    } else {
        std::unique_ptr<Node> temp = std::move(head);  // Move ownership to temp
        head = std::move(temp->next);                  // Move ownership of the next node to head
    }

    length--;
}


Node* getByIndex(int index) {
    if (index < 0 || index >= length) {
        std::cout << "Index out of bounds" << std::endl;
        return nullptr;
    }
    Node* temp = head.get(); 
    for (int i = 0; i < index; i++) {
        temp = temp->next.get(); 
    }
    return temp;
}

bool setByIndex(int index, int value) {
    Node* temp = getByIndex(index);  // Call getByIndex to retrieve the node
    if (temp) {
        temp->value = value;  // If the node is found, update the value
        return true;
    }
    return false;  // If the node is not found (index out of bounds), return false
}

bool insert(int index, int value) {
    if (index < 0 || index > length) {
        std::cout << "Index out of bounds" << std::endl;
        return false;
    }

    if (index == 0) {
        prepend(value);  // Insert at the head (index 0)
        return true;
    }

    if (index == length) {
        append(value);  // Insert at the tail (index = length)
        return true;
    }

    Node* temp = head.get();
    for (int i = 0; i < index - 1; i++) {
        temp = temp->next.get();  // Traverse to the node just before the insertion point
    }

    std::unique_ptr<Node> newNode = std::make_unique<Node>(value);
    newNode->next = std::move(temp->next);  // Connect the new node to the next node
    temp->next = std::move(newNode);        // Connect the previous node to the new node

    length++;
    return true;
}

void deleteNode(int index) {
    if (index < 0 || index >= length) {
        std::cout << "Index out of bounds" << std::endl;
        return;
    }

    if (index == 0) {
        // Call deleteFirst() to handle the deletion of the first node
        deleteFirst();
        return;
    }

    // General case: delete a node in the middle or end
    Node* prev = head.get();
    for (int i = 0; i < index - 1; i++) {
        prev = prev->next.get();  // Traverse to the node just before the one to delete
    }

    std::unique_ptr<Node> temp = std::move(prev->next);  // Temporarily hold the node to delete
    prev->next = std::move(temp->next);  // Skip over the deleted node

    if (index == length - 1) {
        // If deleting the last node, update the tail
        tail = prev;
    }

    length--;
}

void reverseList() {
    if (length <= 1) return;  // No need to reverse if the list has 0 or 1 node

    Node* prev = nullptr;                // This will be the new tail (set to null initially)
    Node* current = head.release();      // Transfer ownership from head to current
    tail = current;                      // The current head will become the new tail

    while (current != nullptr) {
        Node* next = current->next.release();  // Get next node and release its ownership
        current->next.reset(prev);        // Reverse the next pointer
        prev = current;                   // Move prev to the current node
        current = next;                   // Move to the next node
    }

    head.reset(prev);                     // Set the new head to the last node
}



    void printList(){
    	Node* temp = head.get();
    	while(temp != nullptr){
    		std::cout << temp->value << std::endl;
    		temp = temp->next.get();
    	}
    }

   
	void getLength(){
		std::cout<< "length : "<< length << std::endl;

	}

  void getHead() {
        if (head) {
            std::cout << "Head: " << head->value << std::endl;
        } else {
            std::cout << "Head is null" << std::endl;
        }
    }

    void getTail() {
        if (tail) {
            std::cout << "Tail: " << tail->value << std::endl;
        } else {
            std::cout << "Tail is null" << std::endl;
        }
    }
};

int main(){

    auto myLinkedList = std::make_unique<LinkedList>(LinkedList(2));

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

    std::cout <<"Get value: " << myLinkedList->getByIndex(2)->value <<std::endl;
    myLinkedList->setByIndex(2, 7);
    std::cout <<"Get value: " << myLinkedList->getByIndex(2)->value <<std::endl;
    myLinkedList->insert(1,10);

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