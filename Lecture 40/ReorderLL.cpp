#include<bits/stdc++.h>
using namespace std;
const int N = 0;

class ListNode {
public:
	int val;
	ListNode *next;

	// ListNode() : val(0), next(nullptr) {}
	// ListNode(int x) : val(x), next(nullptr) {}
	// ListNode(int x, ListNode *next) : val(x), next(next) {}

	ListNode() {
		val = 0;
		next = NULL;
	}

	ListNode(int x) {
		val = x;
		next = NULL;
	}
	ListNode(int x, ListNode* ptr) {
		val = x;
		next = ptr;
	}
};

class Solution {
public:

	ListNode* MidPoint2(ListNode* head) {

		if (head == NULL or head->next == NULL) {
			return head;
		}

		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != NULL and fast->next != NULL) {

			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}

	void ReverseIterative(ListNode* &head) {

		ListNode* current = head;
		ListNode* prev = NULL;
		ListNode* n;

		while (current != NULL) {
			n = current->next;
			current->next = prev;
			prev = current;
			current = n;
		}
		head = prev;
	}


	void reorderList(ListNode* head) {
		if (head == NULL or head->next == NULL) {
			return;
		}

		//Find the Mid Point:
		ListNode* m = MidPoint2(head);
		ListNode* h1 = head;//Head of my first Linked List.

		ListNode* h2 = m->next;
		ReverseIterative(h2);

		m->next = NULL;//Breaking the current LL into two parts.

		ListNode* x, *y;

		while (h2 != NULL) {
			x = h1->next;
			h1->next = h2;
			h1 = x;

			y = h2->next;
			h2->next = h1;
			h2 = y;
		}
	}
};

int main() {

}