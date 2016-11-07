ListNode* removeElements(ListNode* head, int val)
{
    ListNode* previous = NULL;
    ListNode* current = head;
    while(NULL != current)
    {
	if(current->val == val)
	{
	    if(NULL == previous)
	    {
		current = head = head->next;
	    }
	    else
	    {
		previous->next = current->next;
		current = current->next;
	    }
	}
	else
	{
	    previous = current;
	    current = current->next;
	}
    }

    return head;
}
