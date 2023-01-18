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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* i=head;
        ListNode* prev=NULL;
        while(i!=NULL){
            ListNode* j=i;
            int sum=0;
            sum+=j->val;
            j=j->next;
            while(j!=NULL && sum!=0){
                sum+=j->val;
                j=j->next;
            }
            if(sum==0){
                if(prev==NULL){
                    head=j;
                    i=head;
                }else{
                    prev->next=j;
                    i=j;
                }
            }else{
                prev=i;
                i=i->next;
            }
        }
        return head;
    }
};