/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode* curl = head;
        ListNode* tail = head;
        int n = 1;
        while(tail->next) {
            tail = tail->next;
            n++;
        }
        k = k%n;
        if(k==0) return head;
        int i = 0;
        while(i < n - k -1) {
            curl = curl->next;
            i++;
        }
        ListNode* newh = curl -> next;
        curl->next = NULL;
        tail->next = head;
        return newh;
    }
};
