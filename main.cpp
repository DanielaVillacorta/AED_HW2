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

    bool empty() {
        return 0;
    }

    T back() {
        if (empty()){throw std::out_of_range("List is empty");}

        return head->prev->data;
    }

    void push_back(T val) {
        Node<T>* newNode = new Node(val);

        newNode->prev=head->prev;
        newNode->next =head;
        newNode->prev->next = newNode;
        head->prev = newNode;
    }

    T pop_back() {
        if (empty()){throw std::out_of_range("List is empty");}

        Node<T>* temp = head->prev;
        T val = temp->data;
        head->prev->prev->next =  head;
        head->prev = head->prev->prev;
        delete temp;
        return val;
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
        if (empty()){return 0;}

        int i = 0;
        Node<T>* temp = head->next;
        while (temp != head) {
            i++;
            temp = temp->next;
        }
        return i;
    }

    void remove(int pos) {
        if(empty()) {throw std::out_of_range("List is empty");}

        if(pos<0 || pos>=size()) {throw std::out_of_range("Index out of range");}

        Node<T>* temp = head->next;
        int i = 0;
        while (i < pos) {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
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
