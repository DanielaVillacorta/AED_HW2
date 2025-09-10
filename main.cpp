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

    void clear() {
        auto pt1 = head->next;
        while(pt1!= head) {
            auto temp = pt1;
            pt1 = pt1->next;
            delete temp;
        }
        head->next = head;
        head->prev = head;
    }

    int size() {
        return 0;
    }

    bool empty() {
        return 0;
    }

    T operator[](int pos) {
        if(pos<0 or pos>=this->size()) {
            throw std::out_of_range("Index out of range");
        }
        Node<T>* temp = head->next;
        int i = 0;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        return temp->data;
    }

    void reverse() {
        Node<T>* actual = head;
        do {
            Node<T>* ptr = actual->next;
            actual->next = actual->prev;
            actual->prev = ptr;
        }while(actual!=head);
    }
};

int main(){

    return 0;
}
