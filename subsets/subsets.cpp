class Solution {
public:
    void find(vector<int> &nums,vector<int>&a,vector<vector<int>>&d,int index)
    {
        if(index==nums.size())
        {
            d.push_back(a);
            return;
        }
        a.push_back(nums[index]);
        find(nums,a,d,index+1);
        a.pop_back();
        find(nums,a,d,index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> a;
        vector<vector<int>> d;
        find(nums,a,d,0);
        return d;
    }
};