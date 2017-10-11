/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(0) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			//int len1 = 0;
			//int len2 = 0;
			//while (l1)
			//{
			//	len1++;
			//	l1 = l1->next;
			//}

			//while (l2)
			//{
			//	len2++;
			//	l2 = l2->next;
			//}

			int extra = 0;
			int sum = 0;	
			ListNode* head = new ListNode(0);
			head->next = 0;
			ListNode* lastNode = head;
			while (l1 || l2)
			{
				sum = 0;
				if (l1 && l2)
				{
					sum = l1->val + l2->val + extra;	
					if (sum >= 10)
					{
						extra = 1; 	
						sum %= 10;
					}
					else
					{
						extra = 0;
					}
				}
				else if (l1)
				{
					sum = l1->val + extra;	
					if (sum >= 10)
					{
						extra = 1; 	
						sum %= 10;
					}
					else
					{
						extra = 0;
					}
				}
				else if (l2)
				{
					sum = l2->val + extra;	
					if (sum >= 10)
					{
						extra = 1; 	
						sum %= 10;
					}
					else
					{
						extra = 0;
					}
				}


				ListNode* newNode = new ListNode(sum);
				newNode->next = 0;
				lastNode->next = newNode;
				lastNode = newNode;
			}

			ListNode* returnNode = head->next;
			delete head;
			return returnNode;

		}
};
