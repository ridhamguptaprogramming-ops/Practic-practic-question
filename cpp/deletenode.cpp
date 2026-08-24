#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void deletenode(Node* head, Node* target) {

    if (head == NULL || target == NULL) {
        return;
    }
    if (head == target) {
        return;
    }
    Node* temp = head;

    while (temp->next != NULL && temp->next != target) {
        temp = temp->next;
    }

    if (temp->next == target) {
        temp->next = target->next;
        delete target;
    }
}

int main() {

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    print(a);
    deletenode(a, d);
    print(a);

    return 0;
}