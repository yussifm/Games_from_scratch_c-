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

    auto myLinkedList = std::make_unique<LinkedList>(LinkedList(4));
    
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->printList();
    

	return 0;

}