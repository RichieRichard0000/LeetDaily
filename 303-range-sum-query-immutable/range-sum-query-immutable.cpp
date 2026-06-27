class NumArray {
public:
    vector<int> data;
    vector<int> prefix_Sum;
    int n;

    NumArray(vector<int>& nums) {
        data = nums;
        n = data.size();

        prefix_Sum.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix_Sum[i] = prefix_Sum[i - 1] + data[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return prefix_Sum[right + 1] - prefix_Sum[left];
    }
};