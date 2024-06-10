#include<bits/stdc++.h>
using namespace std;
const int N = 0;

//Overview of your Data Type:
class node {
public:
	int data;
	node* next;

	node() {
		//Default Constructor
	}

	node(int inputdata) {
		data = inputdata;
		next = NULL;
	}
};

void InsertAtHead(node* &head, int x) {

	node* n = new node(x);
	// (*n).next = head;
	n->next = head;
	head = n;
}


int Length(node* head) {

	int l = 0;

	while (head != NULL) {
		l++;
		head = head->next;
	}
	return l;
}

int MidPoint1(node* head) {

	int mid = Length(head) / 2;
	//cout << mid << endl;

	while (mid > 0) {
		head = head->next;
		mid--;
	}
	return head->data;
}


//Second Mid Point in Case of Even Linked List:

int MidPoint2(node* head) {

	node* slow = head;//x
	node* fast = head;//2x

	while (fast != NULL and fast->next != NULL) {

		// fast = fast->next;
		// fast = fast->next;

		fast = fast->next->next;

		slow = slow->next;

	}

	//You have found the mid Point and currently slow is pointing to it.

	return slow->data;

}

//Logic for the first Mid Point.

node* MidPoint3(node* head) {

	node* slow = head;//x
	node* fast = head->next;//2x

	while (fast != NULL and fast->next != NULL) {

		// fast = fast->next;
		// fast = fast->next;

		fast = fast->next->next;

		slow = slow->next;

	}

	//You have found the mid Point and currently slow is pointing to it.

	return slow;

}

bool SearchIterative(node* head, int key) {

	while (head != NULL) {

		if (head->data == key) {
			return true;
		}
		head = head->next;
	}

	return false;
}


/*

	Solve(head,key): Current head se lekar end tak kya mujhe element mila?

	Solve(head->next,key): Current head se lekar end tak kya mujhe element mila?


	Current head se lekar end tak kya mujhe element mila1?=Current
	element ko check karo and baaki recusion ko bol do.

	Solve(head,key)=check the head + Solve(head->next,key);

*/

bool SearchRecursive(node* head, int key) {

	if (head == NULL) {
		return false;
	}

	//Task:
	if (head->data == key) {
		return true;
	}

	bool ans = SearchRecursive(head->next, key);

	return ans;
}



void Print(node* &head) {

	node* temp = head;//Extra variable

	// while (head != NULL) {
	// 	cout << head->data << "-->";
	// 	head = head->next;
	// }
	// cout << "NULL" << endl;

	while (temp != NULL) {
		cout << temp->data << "-->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}


int main() {
	//	int x;//x is a object only.

	//int x = 10;

	// int x(10);

	// node x(10);

	// cout << x.data << endl;
	// cout << x.next << endl;


	node* head = NULL;
	node* head1 = NULL;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		InsertAtHead(head, x);//Pass By value
		InsertAtHead(head1, x);
	}

	Print(head);
	Print(head1);

	cout << Length(head) << endl;
	cout << MidPoint1(head) << endl;
	cout << MidPoint2(head) << endl;

	cout << MidPoint3(head)->data << endl;

	cout << SearchIterative(head, 140) << endl;
	cout << SearchRecursive(head, 10) << endl;
}




// 50->40->30->20->10->NULL;






