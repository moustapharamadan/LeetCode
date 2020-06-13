struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
void deleteNode(ListNode* node) {
    ListNode* temp = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
    delete temp;
}
