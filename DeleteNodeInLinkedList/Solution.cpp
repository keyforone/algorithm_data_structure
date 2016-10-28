void deleteNode(ListNode* node)
{
    if((NULL == node) || (NULL == node->next)) return;

    node->val = node->next->val;
    node->next = node->next->next;
}
