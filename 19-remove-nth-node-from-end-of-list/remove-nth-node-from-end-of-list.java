/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if(head==null) return null;
        ListNode temp=head;
        int len=0;
        while(temp!=null){
            len++;
            temp=temp.next;
        }
    
        if(len==n){
            temp=head;
            head=temp.next;
        
        }
        int k=len-n;
        int count=0;
        ListNode at=head;
        while(at!=null){
            count++;
            if(count==k){
                at.next=at.next.next;
            }
            at=at.next;
        }
        return head;
    }
}