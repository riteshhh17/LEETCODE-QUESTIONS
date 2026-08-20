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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            ListNode* curr=head;
            head=head->next;
            delete curr;
        }
        ListNode* temp=head;
        ListNode* curr=nullptr;
        
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val == val){
                curr=temp->next;
                temp->next=curr->next;
                delete curr;
                }
                else{
                    temp=temp->next;
                }

        }
    
    return head;  
    }
};