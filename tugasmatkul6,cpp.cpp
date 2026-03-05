#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() {
        head = NULL;
    }

    // Insert FIRST
    void insertFirst(int value) {
        Node* newNode = new Node(value);

        if (head != NULL) {
            head->prev = newNode;
            newNode->next = head;
        }

        head = newNode;
    }

    // Insert LAST
    void insertLast(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert NEXT
    void insertNext(int prevData, int value) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == prevData) {
                Node* newNode = new Node(value);

                newNode->next = temp->next;
                newNode->prev = temp;

                if (temp->next != NULL) {
                    temp->next->prev = newNode;
                }

                temp->next = newNode;
                return;
            }

            temp = temp->next;
        }

        cout << "Node tidak ditemukan" << endl;
    }

    // DELETE FIRST NODE
    void deleteFirst() {
        if (head == NULL) return;

        Node* temp = head;
        head = head->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete temp;
    }

    // DELETE LAST
    void deleteLast() {
        if (head == NULL) return;

        Node* temp = head;

        if (temp->next == NULL) {
            head = NULL;
            delete temp;
            return;
        }

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        delete temp;
    }

    // Hapus node tertentu
    void deleteNode(int value) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == value) {

                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }

                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }

                delete temp;
                return;
            }

            temp = temp->next;
        }

        cout << "Node tidak ditemukan" << endl;
    }

    
    void display() {
        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main() {
    DoubleLinkedList dll;

    dll.insertFirst(10);
    dll.insertFirst(5);
    dll.insertLast(20);
    dll.insertLast(30);

    cout << "Setelah insert:" << endl;
    dll.display();

    dll.insertNext(20, 25);
    cout << "Setelah insertNext:" << endl;
    dll.display();

    dll.deleteFirst();
    cout << "Setelah deleteFirst:" << endl;
    dll.display();

    dll.deleteLast();
    cout << "Setelah deleteLast:" << endl;
    dll.display();

    dll.deleteNode(20);
    cout << "Setelah deleteNode 20:" << endl;
    dll.display();

    return 0;
}