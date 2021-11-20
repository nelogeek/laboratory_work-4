#include <iostream>
#include <iomanip>


using namespace std;

struct point
{
	int data; // поле данных
	struct point* next; // указатель на следующий элемент
	struct point* pred; // указатель на предыдущий элемент
};

point* make_point()
{
	point* head = new(point);//указатель на первый элемент
	cout << "\n<< ";
	cin >> head->data;//вводим значение информационного поля
    head->next = 0, head->pred = 0;
	return head;//возвращаем beg как результат функции
}

point* make_list(int n)
//создание списка
{
	point* p, * head;
    head = make_point();//создаем первый элемент
	for (int i = 0; i < n - 1; i++)
	{
		p = make_point();//создаем один элемент
		//добавление элемента в начало списка
		p->next = head;//связываем р с первым элементом
        head->pred = p;//связываем первый элемент с p
        head = p;// p становится первым элементом списка
	}
	return head;
}

void outListHead(point* head)
//печать списка
{
	point* p = head;//начало списка
	while (head != NULL && head->next != NULL)
        head = head->next;

	while (head != NULL)
	{
		cout << head->data << "\t";
        head = head->pred;//переход к следующему элементу
	}
}

void reverse(point* head)
{
    
     
	point* p = head;//начало списка
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;//переход к следующему элементу
	}
}

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

void removeHead(Node* head) {
    if (head)
    {
        Node* temp = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
    }

    else if (!head)
        cout << "head is null" << endl;
}

//-------------------------------------------------------------

void removeTail(Node* tail) {
    
        tail->prev = NULL;
        delete tail;

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

//---------------------------------------------------------------------



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
