//
// Created by gabriel on 08/09/18.
//

#ifndef MSERVER_DOUBLELIST_H
#define MSERVER_DOUBLELIST_H
#define NULL 0

template <class T>
class DoubleList {
    struct node {
        T data;
        struct node *next;
        struct node *prev;
        node(T Reference){
            T data = Reference;
            next = NULL;
            prev = NULL;
        }
    };
private:

    int lenght = 0;
    node *head, *tail;

public:
    DoubleList<T>(){
        head = NULL;
        tail = NULL;
    };

    bool isEmpty();
    bool search(T reference);
    void append(T reference);
    void del(T reference);

};


#endif //MSERVER_DOUBLELIST_H
