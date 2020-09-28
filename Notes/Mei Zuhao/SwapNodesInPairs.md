```c++
// 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

void exchange(ListNode* pre, ListNode* left, ListNode* right) {
    // 辅助函数，参数分别为交换结点的前一个结点、需要交换的两个结点
    // 交换前pre->left->right
    pre->next = right;
    left->next = right->next;
    right->next = left;
    // 交换后pre->right->left
}

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next)
        return head;
    ListNode* ans = head->next; // 保存结果
    ListNode* pre = new ListNode(0);
    ListNode* left = head;
    ListNode* right = head->next;
    while (right != nullptr) {
        exchange(pre, left, right);
        // 交换后pre->right->left
        pre = left;
        left = left->next;
        if (left == nullptr) // left若为空结点则遍历结束
            break;
        right = left->next;
    }
    return ans;
}
```