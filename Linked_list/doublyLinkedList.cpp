#include <iostream>
using namespace std;

class Node {
    
        public: 
        int data;
        Node* next;
        Node* prev;
    
        //constructor
        Node(int data) {
            this-> data = data;
            this -> next = NULL;
            this -> prev = NULL;
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
        head -> prev = temp;
        head = temp;
        }
        return;
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
        temp -> prev = tail;
        tail = temp;
    }
}
// made a function to get the length of the list for insertAtPos
int getLength(Node* &head) {

    Node* temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    return count;
}

// print length of the list
int printLength(Node* &head) {

    Node* temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    cout << "Length of the list is: " << count << endl;
    return count;
}


void insertAtPos(Node* &head, Node* &tail, int data, int pos) {

    if(pos == 1) {

        insertAtHead(head, tail, data);

    } else if (pos == (getLength(head) + 1)) {

        insertAtTail(head, tail, data);

    } else if (pos > (getLength(head) + 1)) {

        cout << "Invalid position" << endl;

    } else if (pos < 1) {

        cout << "Invalid position" << endl;

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
        currNode -> prev = temp;
        temp -> prev = prevNode;
    }
}


void deleteNode(Node* &head, Node* &tail, int pos) {

    if(pos == 1) {

        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;

    } else {

        Node* currNode = head;
        Node* prevNode = NULL;

        for(int i = 1; i < pos; i++) {
            prevNode = currNode;
            currNode = currNode -> next;
        }

        prevNode -> next = currNode -> next;
        currNode -> next -> prev = currNode -> prev; // = prevNode; works too
        currNode -> next = NULL;
        currNode -> prev = NULL;
        delete currNode;
    }
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;
    cout << endl;

    insertAtHead(head, tail, 10);
    printList(head);

    insertAtHead(head, tail, 20);
    printList(head);

    insertAtTail(head, tail, 30);
    printList(head);

    insertAtPos(head, tail, 40, 5);
    printList(head);

    cout << "head: " << head -> data << endl;
    cout << "tail: " << tail -> data << endl;

    printLength(head);

    return 0;
}
