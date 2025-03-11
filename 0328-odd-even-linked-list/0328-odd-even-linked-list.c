/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(!head || !head->next || !head->next->next) return head;
        
        struct ListNode *odd = head;
        struct ListNode *even = head->next;
        struct ListNode *even_start = head->next;
        
        while(odd->next && even->next){
            odd->next = even->next; 
            even->next = odd->next->next; 
            odd = odd->next;
            even = even->next;
        }
        odd->next = even_start; 
        return head; 
};