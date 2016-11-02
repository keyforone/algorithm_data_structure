ListNode* swapPairs(ListNode* head) 
{
    if(NULL == head) return NULL;
    if(NULL == head->next) return head;

    ListNode* new_head;

    ListNode* previous = NULL;
    ListNode* current = head;

    while(NULL != current && NULL != current->next)
    {
	if(NULL == previous)
	{
	    new_head = current->next;

	    ListNode* forward = current->next->next;
	    current->next->next = current;
	    current->next = forward;

	    previous =  current;
	    current = forward;
	}
	else
	{
	    ListNode* forward = current->next->next;
	    previous->next = current->next;
	    current->next->next = current;
	    current->next = forward;

	    previous = current;
	    current = forward;
	}
    }
    return new_head;
}
