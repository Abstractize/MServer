//
// Created by abstractize on 25/09/18.
//

#ifndef MSERVER_LIST_H
#define MSERVER_LIST_H


class List {
private:
    typedef struct node{
        int value = 0;
        struct node *next = nullptr;
    };
    int lenght;
    node *head;
public:
    List(int value){
        lenght = value;
        head = new node();
        node *tmp = head;
        for (int i= value-1; i >= 0; i--){
            tmp->next = new node();
            tmp = tmp->next;
        }
    }
};


#endif //MSERVER_LIST_H
