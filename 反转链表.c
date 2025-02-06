/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    if (head) {;
        if (head->next) {;
        } else {
            return head;
        }
        if (head->next->next) {; 
        } else {
            struct ListNode*prev=head->next;
            head->next->next = head;
            head->next = NULL;
            return prev;
        }
    } else {
        return NULL;
    }
    struct ListNode* n1 = head;
    struct ListNode* n2 = head->next;
    struct ListNode* n3 = head->next->next;
    while (n3){
        n2->next = n1;
        n1 = n2;
        n2 = n3;
        n3 = n3->next;
    }
    n2->next=n1;
    head -> next =NULL;
    return n2;
}
