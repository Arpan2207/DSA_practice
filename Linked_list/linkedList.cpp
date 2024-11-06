#include <iostream>
using namespace std;

class Node {

    public: 
    int data;
    Node* next;


    //constructor
    Node(int data) {
        this-> data = data;
        this -> next = NULL;
    }
    
    // destructor
    ~Node() {
        int value = this -> data;
        // memory free
        if(this->next != NULL) {
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {

    if(head == NULL) {
            Node* temp = new Node(data);
            head = temp;
            tail = temp;

    } else { 
            Node* temp = new Node(data);
            temp -> next = head;
            head = temp;
        }
    
}

void printList(Node* &head) {

    Node* temp = head;

    while (temp != NULL) {
        cout << temp -> data << " --> ";
        temp = temp -> next;
    }
    cout << "NULL"<< endl;
    cout << endl;
}

void insertAtTail(Node* &head, Node* &tail, int data) {

    if(tail == NULL) {
            Node* temp = new Node(data);
            head = temp;
            tail = temp;

    } else {
            Node* temp = new Node(data);
            tail -> next = temp;
            tail = tail -> next;
        }
    }
    

void insertAtPosition(Node* &head, Node* &tail, int pos, int data) {

    if(pos == 1) {
        insertAtHead(head, tail, data);
        return;

    //} else if (pos > )

    } else {

        Node* temp = new Node(data);
        Node* currNode = head;
        Node* prevNode = NULL;

        for(int i = 1; i < pos; i++) {
            prevNode = currNode;
            currNode = currNode -> next;
        }

        prevNode -> next = temp;
        temp -> next = currNode;
    } 

}

void deleteNode(Node* &head, int pos) {

    if (pos == 1) {
        Node* temp = head;
        head = head -> next;
        // memory free for the first node
        temp -> next = NULL;
        delete temp;
        
    } else {

        Node* currNode = head;
        Node* prevNode = NULL;

        for(int i = 1; i < pos; i++) {
            prevNode = currNode;
            currNode = currNode -> next;
        }
        // int count = 1;
        // while(count < pos) {
        //     prevNode = currNode;
        //     currNode = currNode -> next;
        //     count++;
        // }
        prevNode -> next = currNode -> next;
        currNode -> next = NULL;
        delete currNode;
    }
}




int main () {

    Node* head = NULL;
    Node* tail = NULL;

    printList(head);
    insertAtHead(head, tail, 33);

    printList(head);
    insertAtHead(head, tail, 22);
    
    printList(head);
    insertAtHead(head, tail, 11);
    
    printList(head);
    insertAtTail(head, tail, 44);

    printList(head);
    insertAtPosition(head, tail, 6, 666);
    
    printList(head);
    deleteNode(head, 1);

    printList(head);
    deleteNode(head, 3);

    printList(head);
    return 0;
}