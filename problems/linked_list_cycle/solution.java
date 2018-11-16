/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null)
        {
          return false; 
        }
        ListNode fast = head;
        ListNode slow = head;
        while(fast.next!=null)
        {
            fast=fast.next;
            if(fast.next==null)
            {
                return false;
            }
            fast=fast.next;
            slow=slow.next;
            if(fast==slow)
            {
                return true;
            }
            
        }
        return false;
    }
};