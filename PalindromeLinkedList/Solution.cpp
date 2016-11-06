/**
 ** Definition for singly-linked list.
 ** struct ListNode {
 **     int val;
 **     ListNode *next;
 **     ListNode(int x) : val(x), next(NULL) {}
 ** };
 **/
class Solution {
    public:
	    bool isPalindrome(ListNode* head) 
	    {
		if(NULL == head) return false;
		if(NULL == head->next) return true;

		int counts = 0;
		ListNode* current = head;
		while(NULL != current)
		{
		    counts++;
		    current = current->next;
		}

		ListNode* previous = NULL;
		current = head;
		ListNode* forward = current->next;
		for(int i = 1; i <= counts/2; i++)
		{
		    current->next = previous;
		    previous = current;
		    current = forward;
		    forward = current->next;
		}

		ListNode* head1 = previous;
		ListNode* head2 = NULL;
		if((counts%2) == 0)
		    head2 = current;
		else
		    head2 = forward;

		while(NULL != head1 && NULL != head2)
		{
		    if(head1->val != head2->val) return false;
		    head1 = head1->next;
		    head2 = head2->next;
		}

		return true;
	    }
};
