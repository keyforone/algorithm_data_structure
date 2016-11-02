bool isAscendingOrder(ListNode* root)
{
    while(NULL != root->next)
    {
	if(root->val > root->next->val) return false;
	root = root->next;
    }

    return true;
}

ListNode* reverseListByAscending(ListNode* root, bool isAscendingOrder)
{
    if(isAscendingOrder) return root;

    ListNode* previous = root;
    ListNode* current = previous->next;
    previous->next = NULL;

    while(NULL != current)
    {
	ListNode* t = current->next;
	current->next = previous;
	previous = current;
	current = t;
    }

    return previous;
}

ListNode* mergeLists(ListNode* l1, ListNode * l2, bool isAscending)
{
    ListNode* head = NULL;
    ListNode* current =  head;

    while(NULL != l1 && NULL != l2)
    {
	ListNode* t;
	if(l1->val == l2->val) { t =  l1; l1 = l1->next; }
	else if((l1->val < l2->val) && isAscending) { t = l1; l1 = l1->next; }
	else if((l1->val < l2->val) && !isAscending) { t = l2; l2 = l2->next; }
	else if((l1->val > l2->val) && isAscending) { t = l2; l2 = l2->next; }
	else { t = l1; l1 = l1->next; }

	if(NULL == head) { head = t; current = head; current->next = NULL; }
	else { current->next = t; current = t; current->next = NULL; }
    }

    if(NULL == l1) { current->next = l2; }
    else { current->next = l1; }

    return head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(NULL == l1 && NULL == l2) return NULL;
    if(NULL == l1) return l2;
    if(NULL == l2) return l1;

    bool l1_order = isAscendingOrder(l1);
    bool l2_order = isAscendingOrder(l2);

    if(l1_order = l2_order) return mergeLists(l1, l2, l1_order);

    l1 = reverseListByAscending(l1, l1_order);
    l2 = reverseListByAscending(l2, l2_order);

    return mergeLists(l1, l2, true);
}
