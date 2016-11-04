ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(NULL == head || NULL == head->next) return NULL;

    vector<ListNode*> vlist;
    ListNode* current = head;
    while(NULL != current)
    {   
	vlist.push_back(current);
	current = current->next;
    } 

    if( n == vlist.size() ) { head = vlist[1]; }
    else { vlist[vlist.size()-n-1]->next = vlist[vlist.size()-n]->next; }

    return head;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    if(NULL == head) return NULL;

    ListNode* previous = NULL;
    ListNode* last = head;
    int windowsize = n;
    while(windowsize != 1)
    {
	last = last->next;
	windowsize--;
    }

    while(NULL != last->next)
    {
	if(NULL == previous) previous = head;
	else previous = previous->next;
	last = last->next;
    }

    if(NULL == previous) return head->next;
    else { previous->next = previous->next->next; return head; }
}
