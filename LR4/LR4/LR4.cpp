#include <iostream>

using namespace std;

struct Node {

    int data;     //информационное поле

    Node* next;  //указатель на следующий узел

    Node* prev;  //указатель на предыдущий узел 

};

//--------добавить в начало-----------------------------------------

void AddHead(Node*& head, Node*& tail, int val) {

    Node* temp = new Node;

    temp->data = val;

    if (head == NULL) { head = temp; tail = temp; } //первый узел

    else {
        temp->next = head;

        head->prev = NULL;

        head = temp;

    }

}

//--------добавить в конец-----------------------------------------

void AddTail(Node*& head, Node*& tail, int val) {

    Node* temp = new Node;

    temp->data = val;

    if (tail == NULL) { head = temp; tail = temp; } //первый узел

    else {
        temp->prev = tail;

        temp->next = NULL;

        tail = temp;

    }

}

//-------------------------------------------------------------

void remove(Node*& head, Node*& tail, Node* p) {

    //проверка на принадлежность  узла к концам списка

    if (head == p) { removeHead(head); return; }

    if (tail == p) { removeTail(tail); return; }

    //если p существует

    if (p) {

        p->prev->next = p->next;            //изменяем указатель next левого соседа p->prev удаляемого узла  

        p->next->prev = p->prev;            //изменяем указатель prev правого соседа p->next удаляемого узла 

        delete p;                                    //удаляем узел

    }

}

//-----------вывод--------------------------------------------------

void outListHead(Node* head) {

    Node* temp = head;

    while (temp != NULL) {

        cout << setw(5) << temp->data << ' ';

        temp = temp->next;

    }

    cout << endl;

}



void outListTail(Node* tail) {

    Node* temp = tail;

    while (temp != NULL) {

        cout << setw(5) << temp->data << ' ';

        temp = temp->prev;                             // переход - меняем указатель предыдущего узла

    }

    cout << endl;

}

//-------подсчет количества узлов------------------------------

int countDList(Node* tail) {

    Node* temp = tail;

    int count = 0;

    while (temp != NULL) {

        count++;

        temp = temp->prev;

    }

    return count;

}

//-------------------------------------------------------------


int main()
{
    Node* head = NULL, * tail = NULL;



}

