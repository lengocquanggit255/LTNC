#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;
public:
    CircularLinkedList() {
        head = nullptr;
    }

    Node* get_list_head(){return head;}

    void append(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head;
        }
    }

    void printList() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            Node* current = head;
            do {
                cout << current->value << " ";
                current = current->next;
            } while (current != head);
            cout << endl;
        }
    }

    void josePhus(int n, int m){
    Node* temp;
        while (n != 1)
        {
            temp = head;
            for (int i = 0; i < m - 2; i++)
            {
                temp = temp->next;
            }
            Node* old = temp->next;
            temp->next = temp->next->next;
            head = temp->next;

            cout << old->value << " ";
            delete old;
            n--;
        }
    }
};


int main() {
    CircularLinkedList myList;
    int n,m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        myList.append(1);
    }
    myList.josePhus(n, m);
    cout << myList.get_list_head()->value;
}
