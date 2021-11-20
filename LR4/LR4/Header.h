#include <iostream>
#include <iomanip>


using namespace std;

struct point
{
	int data; // ���� ������
	struct point* next; // ��������� �� ��������� �������
	struct point* pred; // ��������� �� ���������� �������
};

point* make_point()
{
	point* head = new(point);//��������� �� ������ �������
	cout << "\n<< ";
	cin >> head->data;//������ �������� ��������������� ����
    head->next = 0, head->pred = 0;
	return head;//���������� beg ��� ��������� �������
}

point* make_list(int n)
//�������� ������
{
	point* p, * head;
    head = make_point();//������� ������ �������
	for (int i = 0; i < n - 1; i++)
	{
		p = make_point();//������� ���� �������
		//���������� �������� � ������ ������
		p->next = head;//��������� � � ������ ���������
        head->pred = p;//��������� ������ ������� � p
        head = p;// p ���������� ������ ��������� ������
	}
	return head;
}

void outListHead(point* head)
//������ ������
{
	point* p = head;//������ ������
	while (head != NULL && head->next != NULL)
        head = head->next;

	while (head != NULL)
	{
		cout << head->data << "\t";
        head = head->pred;//������� � ���������� ��������
	}
}

void reverse(point* head)
{
    
     
	point* p = head;//������ ������
	while (p != 0)
	{
		cout << p->data << "\t";
		p = p->next;//������� � ���������� ��������
	}
}

struct Node {
    int data;     //�������������� ����
    Node* next;  //��������� �� ��������� ����
    Node* prev;  //��������� �� ���������� ���� 
};
//--------�������� � ������-----------------------------------------

void AddHead(Node*& head, Node*& tail, int val) {

    Node* temp = new Node;

    temp->data = val;

    if (head == NULL) { head = temp; tail = temp; } //������ ����

    else {
        temp->next = head;

        head->prev = NULL;

        head = temp;

    }

}

//--------�������� � �����-----------------------------------------

void AddTail(Node*& head, Node*& tail, int val) {

    Node* temp = new Node;

    temp->data = val;

    if (tail == NULL) { head = temp; tail = temp; } //������ ����

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

    //�������� �� ��������������  ���� � ������ ������

    if (head == p) { removeHead(head); return; }

    if (tail == p) { removeTail(tail); return; }

    //���� p ����������

    if (p) {

        p->prev->next = p->next;            //�������� ��������� next ������ ������ p->prev ���������� ����  

        p->next->prev = p->prev;            //�������� ��������� prev ������� ������ p->next ���������� ���� 

        delete p;                                    //������� ����

    }

}

//-----------�����--------------------------------------------------

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

        temp = temp->prev;                             // ������� - ������ ��������� ����������� ����

    }

    cout << endl;

}

//---------------------------------------------------------------------



//-------������� ���������� �����------------------------------

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
