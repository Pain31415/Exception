#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> myList;

    myList.AddToHead(3);
    myList.AddToTail(5);
    myList.AddToHead(1);
    myList.AddToTail(7);

    std::cout << "Linked List: ";
    myList.Show();

    myList.DeleteFromHead();
    std::cout << "After deleting from head: ";
    myList.Show();

    myList.DeleteFromTail();
    std::cout << "After deleting from tail: ";
    myList.Show();

    myList.DeleteAll();
    std::cout << "After deleting all: ";
    myList.Show();

    return 0;
}