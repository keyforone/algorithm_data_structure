ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* start = head;
    while((NULL != start) && (NULL != start->next))
    {
	if(start->val == start->next->val)
	    start->next = start->next->next;
	else
	    start = start->next;
    }

    return head;
}
