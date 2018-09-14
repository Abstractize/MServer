//
// Created by gabriel on 08/09/18.
//

#include "DoubleList.h"
template <class T>
bool DoubleList<T>::isEmpty() {
    if (this->lenght == 0){
        return true;
    } else{
        return false;
    }
};
template <class T>
bool DoubleList<T>::search(T Reference) {
    node tmp = head;
    if (head->data == Reference){
        return true;
    }else{
        tmp = head->next();
        for (int i = 1 ; i < lenght; i++){
            if (tmp.data == Reference){
                return  true;
            }else{
                tmp = tmp.next();
            }
        }
        return false;
    }

};
template <class T>
void DoubleList<T>::append(T reference) {
    if (head == NULL){
        head = new node(reference);
        tail = head();
        lenght++;
    }
    else{
        node tmp = new node(reference);
        tmp.next = this->head;
        tail->next = tmp;
        lenght++;
    }
}
template <class T>
void DoubleList<T>::del(T reference) {
    node tmp = head;
    if (head->data == reference){
        tail->next = head->next;
        head = head->next;
        head->prev = tail;
    }else{
        tmp = head->next();
        for (int i = 1 ; i < lenght; i++){
            if (tmp.data == reference){
                tmp.prev->next = tmp.next;
                tmp.next->prev = tmp.prev;
                break;
            }else{
                tmp = tmp.next();
            }
        }
    }

};


