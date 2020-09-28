```c++
// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 快慢指针
    ListNode* cache = new ListNode(0);
    cache->next = head;
    ListNode *pre = cache; // 不能令pre为head，因为若需删除head则结果无法保存
    ListNode *cur = cache;
    for (int i = 0; i < n; ++i)
        cur = cur->next;
    while (cur->next != nullptr) {
        cur = cur->next;
        pre = pre->next;
    }
    pre->next = pre->next->next;
    return cache->next;
}
```

