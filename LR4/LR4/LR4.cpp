#include "Header.h"


int main()
{
	//list* head, * cur;
	//head = init(1);
	//cur = head;
	//for (int i = 2; i < 9; i++) {
	//	
	//	cur = addelem(cur, i);
	//}
	//listprint(head);
	//
	//reverse(head);

	int n = 0, k = 0;
	point* head = nullptr;
    
	cout << "Enter size: ";
	cin >> n;
	head = make_list(n);
	cout << endl;

	outListHead(head);
	cout << endl;

	reverse(head);
	cout << endl;

    return 0;
}

