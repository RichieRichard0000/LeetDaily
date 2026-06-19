class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        int n = v.size();
        int sum = 0;

        for (int i = n - 1; i >= 0; i--) {
            sum += (1 << (n - 1 - i)) * v[i];
        }

        return sum;
    }
};