#ifndef FILEDESCLIST_HPP_
#define FILEDESCLIST_HPP_
#include "filedesc.hpp"

class FileDescList {
  private:
    int size;
    typedef struct LinkedList {
        LinkedList *next;
        FileDesc f;
    } LinkedList;
    LinkedList *root;

    void mergeSort(LinkedList **root);
    LinkedList *sortedMerge(LinkedList *a, LinkedList *b);
    void splitList(LinkedList *source, LinkedList **frontRef, LinkedList **backRef);
 
  public:
    FileDescList();
    FileDescList(const FileDesc &);
    ~FileDescList();
    void printList();
    void sort();
    void insertNode(const FileDesc &f);
    static bool destroyList(FileDescList *root);
};
#endif