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

	bool isPalindrome(ListNode* head) {

		ListNode* m = MidPoint2(head);
		ListNode* h1 = head;
		ListNode* h2 = m->next;
		m->next = NULL;

		ReverseIterative(h2);

		while (h1 != NULL and h2 != NULL) {
			if (h1->val != h2->val) {
				return false;
			}

			h1 = h1->next;
			h2 = h2->next;
		}

		return true;

	}

	//1->2
	//h1
	//h2 NULL


};

int main() {

}