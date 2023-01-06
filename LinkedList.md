class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    
        //iterative version
        // if (nullptr == head || nullptr == head->next) {
        //     return head;
        // }
        // ListNode* prev = nullptr;
        // ListNode* cur = head;
        // while (nullptr != cur) {
        //     auto tmp = cur->next;
        //     cur->next = prev;
        //     prev = cur;
        //     cur = tmp;
        // }
        // return prev;
        
        //recursion version
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        auto nextNode = head->next;
        auto reversedNodeHead = reverseList(nextNode);
        nextNode->next = head;
        head->next = nullptr;
        return reversedNodeHead;
    }
};
