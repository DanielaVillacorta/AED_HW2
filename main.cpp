#include <iostream>
using namespace std;

template <typename T>
struct Node {
    Node* next;
    Node* prev;
    T data;

    Node(T val = T(), Node* nxt = nullptr, Node* prv = nullptr): data(val), next(nxt), prev(prv) {}
};

template <typename T>
class CDLinkedList {
    Node<T>* head;
public:
    CDLinkedList() {
        head = new Node<T>();
        head->next = head;
        head->prev = head;
    }
};

int main(){

    return 0;
}
