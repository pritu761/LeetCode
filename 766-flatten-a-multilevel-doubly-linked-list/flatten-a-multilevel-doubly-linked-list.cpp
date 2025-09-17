class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        dfs(head);
        return head;
    }

    // helper returns the tail after flattening
    Node* dfs(Node* node) {
        Node* curr = node;
        Node* last = node;

        while (curr) {
            Node* nextNode = curr->next;
            
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = dfs(childHead);  // recursion gives us the tail

                // splice child list
                curr->next = childHead;
                childHead->prev = curr;
                curr->child = nullptr;

                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                last = childTail;
            } else {
                last = curr;
            }
            curr = nextNode;
        }
        return last; // return the tail
    }
};

