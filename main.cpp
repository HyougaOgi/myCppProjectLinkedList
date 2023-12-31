#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(Node* node){
        this->head = node;
        this->tail = nullptr;
    }
    void push(int data){
        if(this->head == nullptr){
            this->head = new Node(data);
        }
        else if (this->tail == nullptr){
            this->tail = new Node(data);
            this->head->next = this->tail;
            this->tail->prev = this->head;
        }
        else{
            Node* node = new Node(data);
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = this->tail->next;
        }
    }
    Node* pop(int index){
        if(this->head == nullptr){
            return nullptr;
        }
        else if(this->tail == nullptr){
            Node* tmp = this->head;
            this->head = nullptr;
            return tmp;
        }
        else if(this->head == this->tail){
            Node* tmp = this->tail;
            this->tail = nullptr;
            return tmp;
        }
        else{
            Node* tmp = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = nullptr;
            return tmp;
        }
    }
    int getValue(int index){
        int count = 0;
        Node* iter = this->head;
        while(iter != nullptr) {
            if (count == index) {
                return iter->data;
            }
            iter = iter->next;
            count++;
        }
        return -1;
    }
};





int main() {

}


