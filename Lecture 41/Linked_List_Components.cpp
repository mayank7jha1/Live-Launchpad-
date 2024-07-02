/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	int numComponents(ListNode* head, vector<int>& nums) {

		int freq[10005] = {0};

		for (int i = 0; i < nums.size(); i++) {
			freq[nums[i]]++;
		}

		int components = 0;

		while (head) {

			if (freq[head->val] == 1 and (head->next == NULL  or freq[head->next->val] == 0)) {
				components++;
			}

			head = head->next;
		}

		return head;

	}
};




// 1->2->3->4


// nums[1,4]

// components=2;

/*
	Main Kab ye keh sakta hu ki component ka count increase karega:

	Jab Mera current node ke ander ki value freq array >0 hain i.e nums array me ye current
	node ki value exist karti hain and next node hain vo null i.e. linked list khatam hogyi.
	tab mai component ka count badhaunga.


	ya fir


	Jab Mera current node ke ander ki value freq array >0 hain i.e nums array me ye current
	node ki value exist karti hain and next node ki value freq array me zero i.e. mera
	next node nums me exist nahi karta hence main ye keh sakta hu ki component ka count bada do.


	Samaj?



	(freq[head->val]==1 and head->next==NULL)

	or

	(freq[head->val]==1 and freq[head->next->val]==0)


	I Have clubbed these two.

	freq[head->val] and (head->next==NULL or freq[head->next->val]==0)

	component++;



*/