#include "filelist.hpp"
#include <cstdio>
#include <string>

FileDescList::FileDescList() {
    size = 0;
    root = nullptr;
}

FileDescList::FileDescList(const FileDesc &fle) {
    size = 1;
    isInit = 99;
    root = new LinkedList;
    root->f = fle;
    root->next = nullptr;
}

void FileDescList::insertNode(const FileDesc &fle) {
    isInit = 99;
    size += 1;
    LinkedList *present = root, *par = nullptr;
    LinkedList *newNode = new LinkedList;

    newNode->next = nullptr;
    newNode->f = fle;

    if (root == nullptr) {
        root = newNode;
        return;
    }
    while (present != nullptr) {
        par = present;
        present = present->next;
    }
    par->next = newNode;
}

FileDescList::~FileDescList() {
    if (isInit != 99) return;
    LinkedList *present = root, *next = root->next;
    while(next != nullptr) {
        delete present;
        present = next;
        next = next->next;
    }
    delete present;
}


void FileDescList::printList() {
    LinkedList *present = root;
    while(present != nullptr) {
        printf("%s\n", present->f.to_string().c_str());
        present = present->next;
    }
}

void FileDescList::sort() {
    mergeSort(&root);
}
void FileDescList::mergeSort(LinkedList **root) {
    LinkedList *head = *root; 
    
    LinkedList *a; 
    LinkedList *b; 
  
    if ((head == nullptr) || (head->next == nullptr)) { 
        return; 
    }
  
    splitList(head, &a, &b);  
    mergeSort(&a); 
    mergeSort(&b); 
    *root = sortedMerge(a, b); 
}

FileDescList::LinkedList *FileDescList::sortedMerge(LinkedList *a, LinkedList *b) {
    LinkedList *result = nullptr; 
  
    if (a == nullptr) 
        return b; 
    else if (b == nullptr) 
        return a;
    
    if (a->f <= b->f) { 
        result = a; 
        result->next = sortedMerge(a->next, b); 
    } else { 
        result = b; 
        result->next = sortedMerge(a, b->next); 
    } 
    return result; 
}

void FileDescList::splitList(LinkedList *source,\
    LinkedList **frontRef, LinkedList **backRef) {
    LinkedList *fast; 
    LinkedList *slow; 
    slow = source; 
    fast = source->next; 
  
    while (fast != nullptr) { 
    fast = fast->next; 
        if (fast != nullptr) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = nullptr; 
}

