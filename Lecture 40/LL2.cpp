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

void ReverseIterative(node* &head) {

	node* current = head;
	node* prev = NULL;
	node* n;

	while (current != NULL) {
		n = current->next;
		current->next = prev;
		prev = current;
		current = n;
	}

	//Current is at NULL and Hence prev is at the last node.
	head = prev;
}

node* ReverseRecursive(node* head) {

	//Base Case:

	if (head == NULL or head->next == NULL) {
		return head;
	}

	node* new_head = ReverseRecursive(head->next);

	node* current = head;
	current->next->next = current;
	current->next = NULL;

	return new_head;

}

void cycle_creation(node*&head) {
	node* temp = head;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = head->next->next->next;
}

//Assume LL will be atleast of 2 length.
bool iscycle(node* head) {
	node* fast = head;
	node* slow = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast) {
			return true;
		}
	}

	return false;
}

void break_cycle(node* head) {
	node* fast = head;
	node* slow = head;

	while (fast != NULL and fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast) {
			break;
		}
	}

	//Now fast and slow pointer both are standing at the Meeting Point.
	slow = head;
	node* prev = head;

	while (prev->next != fast) {
		prev = prev->next;
	}

	//Now My fast is at the Meeting Point, slow is at the head and prev is just one step before fast.

	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
		prev = prev-> next;
	}

	//Now My prev is standing at the last node and fast and slow are at the origin of the cycle.

	prev->next = NULL;//Cycle is now broken.
}


int main() {

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

	cout << iscycle(head) << endl;
	cycle_creation(head);
	cout << iscycle(head) << endl;
	break_cycle(head);
	cout << iscycle(head) << endl;

}







