ListNode* reverseList(ListNode* head)
{
    if(NULL == head) return NULL;

    stack<ListNode*> st;
    while(NULL != head)
    {
	st.push(head);
	head = head->next;
    }

    ListNode* new_head = st.top();st.pop();
    ListNode* forward = new_head;
    while(!st.empty())
    {
	forward->next = st.top();
	forward = st.top();
	st.pop();
    }
    forward->next = NULL;

    return new_head;
}

ListNode* reverseList(ListNode* head)
{
    if(NULL == head) return NULL;

    ListNode* previous = head;
    ListNode* forward = previous->next;
    previous->next = NULL;

    while(forward != NULL)
    {
	ListNode* t = forward->next;
	forward->next = previous;
	previous = forward;
	forward = t;
    }

    return previous;
}

ListNode* reverseList(ListNode* head)
{
    if(NULL == head) return NULL;

    ListNode* new_head = reverseList(head->next);

    if(NULL == new_head)
    {
	head->next = NULL;
	return head;
    }
    else
    {
	head->next->next = head;
	head->next = NULL;
	return new_head;
    }
}
