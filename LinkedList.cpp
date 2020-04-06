//
// Created by sarra on 3/30/2020.
//

#include "LinkedList.h"
#include <iostream>
#include "myDataClass.h"

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList &list) {
    cout << "copy constructor called" << endl;
    Node *listCursor = list.head;
    if (listCursor != nullptr) {
        head = new Node(listCursor->value, nullptr);
    }
    Node *cursor = head;
    while (listCursor->next != nullptr) {
        listCursor = listCursor->next;
        cursor->next = new Node(listCursor->value, nullptr);
    }
}

//Assignment Operator
LinkedList &LinkedList::operator=(const LinkedList &rhs) {
    cout << "assignment operator called" << endl;
    LinkedList tmp(rhs);
    swap(*this, tmp);
    return *this;
}

//Destructor

LinkedList::~LinkedList() {
    Node *tmp;
    Node *current = head;
    while (current != nullptr) {
        tmp = current->next;
        current->next = nullptr;
        delete current;
        current = tmp;
    }
}

//Functions. You may not need to use them all
void LinkedList::append(myDataClass obj) {
    //situations when there's empty list
    if (head == nullptr) {
        head = new Node(obj, nullptr);
    } else {
        Node *cursor = head;
        while (cursor->next != nullptr) {
            cursor = cursor->next;
        }
        cursor->next = new Node(obj, nullptr);
    }
}

bool LinkedList::Delete(myDataClass obj) {
    //empty list
    if (head = nullptr) {
        return false;
    }

    //item is the first node
    Node *current = head;
    Node *previous;
    if (head->value == obj) {
        head = head->next;
        current->next = nullptr;
        delete current;
        return true;
    }

    //item is in the list
    while (current != nullptr) {
        if (current->value == obj) {
            previous->next = current->next;
            current->next = nullptr;
            delete current;
            return true;
        }
        previous = current;
        current = current->next;
    }

    //item not find
    return false;
}

myDataClass LinkedList::find(myDataClass obj) {
    Node *cursor = head;
    while (cursor != nullptr) {
        if (cursor->value == obj) {
            return obj;
        }
        cursor = cursor->next;
    }
}

void LinkedList::printList() {
    Node *cursor = head;
    if (cursor == nullptr) {
        cout << "empty list" << endl;
    } else {
        while (cursor != nullptr) {
            cout << cursor->value << endl;
            cursor = cursor->next;
        }
    }
}

void LinkedList::InsertionSort() {

}

