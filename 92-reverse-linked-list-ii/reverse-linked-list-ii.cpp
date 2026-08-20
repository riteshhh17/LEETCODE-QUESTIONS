class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        vector<int> vec;

        int count = 1;

        while(count <= right) {
            vec.push_back(temp->val);
            temp = temp->next;
            count++;
        }

        // Reverse only the left to right portion
        reverse(vec.begin() + left - 1, vec.end());

        temp = head;
        count = 1;

        while(count < left) {
            temp = temp->next;
            count++;
        }

        int i = left - 1;

        while(i < right) {
            temp->val = vec[i];
            temp = temp->next;
            i++;
        }

        return head;
    }
};