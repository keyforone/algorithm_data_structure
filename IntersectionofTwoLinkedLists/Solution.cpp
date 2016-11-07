ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(NULL == headA || NULL == headB) return NULL;

    int lengthA = 0;
    ListNode* currentA = headA;
    while(NULL != currentA)
    {
	lengthA++;
	currentA = currentA->next;
    }

    int lengthB = 0;
    ListNode* currentB = headB;
    while(NULL != currentB)
    {
	lengthB++;
	currentB = currentB->next;
    }

    currentA = headA;
    currentB = headB;
    if(lengthA != lengthB)
    {
	if(lengthA < lengthB)
	{
	    for(int i = 0; i < (lengthB-lengthA); i++)
		currentB = currentB->next;
	}
	else
	{
	    for(int i = 0; i < (lengthA-lengthB); i++)
		currentA = currentA->next;
	}
    }

    while(NULL != currentA && NULL != currentB)
    {
	if(currentA == currentB) return currentA;
	currentA = currentA->next;
	currentB = currentB->next;
    }

    return NULL;
}
