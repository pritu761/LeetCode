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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int count = 0;
        //checking if k nodes exist in the linked list
        while(count<k){
            if(temp == NULL){
                return head;
                
            }
            temp=temp->next;
            count++;
        }
        //get the pointer to the next header where the linked list need not to be reversed
        ListNode* prevNode = reverseKGroup(temp,k);
        temp=head;
        count=0;
        while(count<k){
            ListNode*next = temp->next;
            temp->next = prevNode;
            prevNode = temp;
            temp = next;
            count++;
        }
        return prevNode;
    }
};