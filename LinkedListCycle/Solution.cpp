bool hasCycle(ListNode *head)
{
    if(NULL == head) return false;

    ListNode* one_step = head;
    ListNode* two_step = head->next;

    while(NULL != two_step && NULL != two_step->next)
    {
	if(one_step == two_step) return true;

	one_step =  one_step->next;
	two_step =  two_step->next->next;
    }

    return false;
}
