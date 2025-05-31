#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data; 
    Node* next;

    Node(int val) {
        data=val;
        next= nullptr;
    }
};

class LinkedList {
    private:
    Node* head;

    public: 
    LinkedList() {
        head = nullptr;
    }

    void insert(int val) {
        Node* newNode = new Node(val);
        if(head==nullptr) {
            head= newNode;

        }
        else {
            Node* temp =head;
            while(temp->next != nullptr) {
                temp= temp->next;
            }
            temp->next = newNode;

        }
    }

    void display () {
        Node* temp = head;
        while (temp != nullptr) {
            cout<<temp->data << "->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;

    }

    void deleteNode(int val) {
        if(head==nullptr) {
            cout<<"List is Empty" <<endl;
            return;
        }
        if(head->data == val) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout<<"Deleted" <<val <<endl;
            return;
        }
        Node * temp = head;
        while(temp->next != nullptr && temp->next->data !=val) {
                temp = temp->next;  
        }
        if(temp->next==nullptr) {
            cout<<"Value has not been found"<<endl;

        }
        else {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout<<"Deleted"<<val<<endl;

        }
    }

~LinkedList() {
            Node* temp = head;
            while(temp != nullptr) {
                Node* nextnode = temp->next;
                delete temp;
                temp= nextnode;

            }
        }
    
};

int main () {
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout<<"Linked List: "<<endl;
    list.display();

    list.deleteNode(20);

    cout<<"After Deletion : "<<endl;
    list.display();

    return 0;
}