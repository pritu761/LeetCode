class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) 
            return nullptr;
        
        Node* curr = head;
        while(curr != nullptr) {
            // if the current node has a child then flatten the child first
            if (curr->child != nullptr) {
                // \U0001f4cc STEP 1: Save the "after" part
                Node* nextNode = curr->next;
                
                // \U0001f4cc STEP 2: Find where the child chain ends
                Node* childTail = curr->child;
                while(childTail->next != nullptr) {
                    childTail = childTail->next;
                }
                
                // \U0001f4cc STEP 3: Connect child tail to saved "after" part
                if(nextNode != nullptr) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }
                
                // \U0001f4cc STEP 4: Connect current to child head
                curr->next = curr->child;
                curr->child->prev = curr;
                // Clean up!
                curr->child = nullptr;
            }
            // move forward if the curr node has no child
            curr = curr->next;
        }
        return head;
    }
};