#include "LinkedList.h"
#include <iostream>

template <typename T>
class LinkedList {
private:
    template <typename U>
    struct Node {
        U data;
        Node<U>* next;
        Node(U value) : data(value), next(nullptr) {}
    };

    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() {
        DeleteAll();
    }

    void AddToHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!newNode)
            throw std::bad_alloc();
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!newNode)
            throw std::bad_alloc();
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            throw std::logic_error("Attempting to delete from an empty list");
        }
    }

    void DeleteFromTail() {
        if (head) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            }
            else {
                Node<T>* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }
        else {
            throw std::logic_error("Attempting to delete from an empty list");
        }
    }

    void DeleteAll() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void Show() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        LinkedList<int> list;
        list.DeleteFromHead();
    }
    catch (const std::logic_error& e) {
        std::cerr << "Logic error: " << e.what() << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }

    return 0;
}

template class LinkedList<int>;