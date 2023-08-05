//BRUTE FORCE APPROACH
// TIME COMPLEXITY - O(N^2)
// SPACE COMPLEXITY - O(1)
vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int>a;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
               if(nums[i]+nums[j]==target)
               {
                    a.push_back(i);
                    a.push_back(j);
                    return a;
               } 
            }
        }
        return a;
    }

//OPTIMAL APPROACH -- USING UNORDERED MAPS
// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int>a;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(target-nums[i])!=map.end())
            {
                a.push_back(i);
                a.push_back(map[target-nums[i]]);
                return a;
            }
            map[nums[i]]=i;
        }
        return a;
    }
};
// In this optimal approach we will use unordered maps
// Representation -- "unordered_map < type,type> object;"
// here we are storing < key : element of array >,<value : its index>
// find method --- this method iterates and stops if key presents
//                 otherwise it moves to end of the map.
// in each iteration we will check if "(target - element value)" in the map
// if it is present we return those respective indices
// else  we will add that "particular element and its index value" into the map and continue for loop