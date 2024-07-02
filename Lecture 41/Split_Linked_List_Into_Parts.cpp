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
	int len(ListNode* head) {

		int ans = 0;
		while (head) {
			ans++;
			head = head->next;
		}

		return ans;
	}

	vector<ListNode*> splitListToParts(ListNode* head, int k) {
		vector<ListNode*>ans;

		int n = len(head);
		int ME = n / k;
		int EE = n % k;
		int count = 1;//This is me saying itne parts maine bana diye hain
		// k me se. Maine 1 se initiaise isliye kiya hain kyuki
		//aakhari part nahi banana.

		if (ME == 0) {
			// k>n
			//Every Part can only have one element at max.

			//I want to break LL after one node k times.

			for (int i = 0; i < k; i++) {

				if (head != NULL) {
					ListNode* n = head->next;

					//Break Your LL.
					head->next = NULL;
					ans.push_back(head);
					head = n;

				} else {
					ans.push_back(NULL);
				}
			}

		} else {

			//k<=n

			while (head != NULL) {
				ans.push_back(head);

				//Now I have to break the LL according to
				//ME+1/0 for EE.

				int x = (EE > 0) ? 1 : 0;
				EE--;

				for (int i = 0; i < ME + x; i++) {
					head = head->next;
				}

				//Now my head is at the breakage point.

				ListNode* n = head->next;
				head->next = NULL;

				head = n;

				count++;

				if (count == k) {
					//You are at the last part:
					ans.push_back(head);
					break;
				}

			}
		}
		return ans;
	}
};