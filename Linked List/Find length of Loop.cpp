class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
       
        if(head==NULL ||head->next == NULL) return NULL;
        int cnt = 1;
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next !=  NULL){
            fast= fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                fast = fast -> next;
                while(fast != slow){
                    cnt++;
                    fast = fast->next;
                }
                return cnt;
            }
        }
        return NULL;
    }
};