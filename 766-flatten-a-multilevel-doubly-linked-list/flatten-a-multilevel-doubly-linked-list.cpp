class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* dummy = new Node(0, nullptr, head, nullptr);
        Node* prev = dummy;
        stack<Node*> st;
        st.push(head);

        while (!st.empty()) {
            Node* curr = st.top(); st.pop();

            prev->next = curr;
            curr->prev = prev;

            if (curr->next) st.push(curr->next);
            if (curr->child) {
                st.push(curr->child);
                curr->child = nullptr;
            }

            prev = curr;
        }

        // detach dummy
        dummy->next->prev = nullptr;
        return dummy->next;
    }
};
