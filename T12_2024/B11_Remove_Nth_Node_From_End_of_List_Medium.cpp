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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * c = head;
        int size = 1;
        while(c -> next != NULL) {
            size++;
            c = c -> next;
        }
        cout << size;
        if(n > size || size == 1) return NULL;
        if(size - n == 0) return head -> next;
        c = new ListNode(0, head);
        int i = 0;
        while(head -> next != NULL) {
            i++;
            if(i == size - n) {
                head -> next = head -> next -> next;
                break;
            }
            head = head -> next;
        }

        return c -> next;
    }
};
