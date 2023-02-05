class Solution
{
public:
    void dfs(int i, set<vector<int>> &s, vector<int> &v, vector<int> &nums)
    {
        if (i == nums.size())
        {
            s.insert(v);
            return;
        }
        dfs(i + 1, s, v, nums);
        v.push_back(nums[i]);
        dfs(i + 1, s, v, nums);
        if (v.size() > 0)
            v.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        set<vector<int>> s;
        vector<int> v;
        dfs(0, s, v, nums);
        vector<vector<int>> ans;
        for (auto x : s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};