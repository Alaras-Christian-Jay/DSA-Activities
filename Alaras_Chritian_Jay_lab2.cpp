#include <iostream>
#include <string>

using namespace std;

struct Node {
    string songName;
    Node *link;
};

Node* createNode(string data) {
    Node* newNode = new Node;
    newNode->songName = data;
    newNode->link = nullptr;
    return newNode;
}

void traverse(Node *head) {
    Node *temp = head;
    cout << "My Playlist" << endl;
    while (temp != nullptr) {
        cout << temp->songName << endl;
        temp = temp->link;
    }
    cout << "NULL" << endl;
}

Node* insertAtEnd(string data, Node *head) {
    if (head == nullptr) return createNode(data);
    Node *temp = head;
    while (temp->link != nullptr) temp = temp->link;
    temp->link = createNode(data);
    return head;
}

Node* insertAtBeginning(string data, Node *head) {
    Node* newNode = createNode(data);
    newNode->link = head;
    return newNode;
}

Node* insertAfter(string data, Node* afterNode, Node* head) {
    if (afterNode == nullptr) return head;

    Node *temp = head;
    while (temp != nullptr && temp->songName.compare(afterNode->songName) != 0) {
        temp = temp->link;
    }
    if (temp == nullptr) {
        cout << "No such song exist, please try again later." << endl;
        return head;
    }

    Node* newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "The linked list is empty" << endl;
        return head;
    }
    if (head->link == nullptr) {
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while (temp->link->link != nullptr) {
        temp = temp->link;
    }
    delete temp->link;
    temp->link = nullptr;
    return head;
}

Node* deleteAtBeginning(Node* head) {
    if (head == nullptr) {
        cout << "The linked list is empty" << endl;
        return nullptr;
    }
    Node* temp = head;
    head = head->link;
    delete temp;
    return head;
}

Node* deleteFromGivenNode(string givenNode, Node* head) {
    if (head == nullptr) {
        cout << "The linked list is empty." << endl;
        return nullptr;
    }
    if (head->songName.compare(givenNode) == 0) {
        return deleteAtBeginning(head);
    }
    Node *temp = head;
    Node *next = head->link;
    while (next != nullptr && next->songName.compare(givenNode) != 0) {
        temp = next;
        next = next->link;
    }
    if (next == nullptr) {
        cout << "No such node exist." << endl;
        return head;
    }
    temp->link = next->link;
    delete next;
    return head;
}

int main() {
    Node* head = createNode("Sanctuary by Joji");
    head = insertAtEnd("Blinding Lights by The Weeknd", head);
    traverse(head);
    head = insertAtEnd("Shape of You by Ed Sheeran", head);
    traverse(head);
    head = insertAtEnd("Someone You Loved by Lewis Capaldi", head);
    traverse(head);
   
    head = insertAtBeginning("Tibok by Earl Agustin", head);
    traverse(head);
    head = insertAtBeginning("Isa lang by Arthur Nery", head);
    traverse(head);
    head = insertAtBeginning("Superpower by Daniel Caesar", head);
    traverse(head);
    head = insertAtBeginning("Paraluman by Adie", head);
    traverse(head);
    
    head = insertAfter("Anak by Freddie Aguilar", head->link, head);
    traverse(head);
    head = insertAfter("Tadhana by Up Dharma Down", head->link, head);
    traverse(head);
    head = insertAfter("Prinsesa by 6cyclemind", head->link, head);
    traverse(head);



    traverse(head);
    cout << "--------------------" << endl;

    head = deleteAtEnd(head);
    traverse(head);
    cout << "--------------------" << endl;

    head = deleteAtBeginning(head);
    traverse(head);
    cout << "--------------------" << endl;

    head = deleteFromGivenNode("Anak by Freddie Aguilar", head);
    traverse(head);

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->link;
        delete current;
        current = next;
    }

    return 0;
}