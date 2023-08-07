//BRUTE FORCE SOLUTION
//time complexity O(N^2)  -- by some other sorting algorithms it may be O(NlogN)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};

//BETTER SOLUTION
//By counting the no of elements of different colours
//Time complexity O(2N)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0;
        int white=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
             red++;
            else if(nums[i]==1)
             white++;
        }
        int j,k;
        for(j=0;j<red;j++)
        {
            nums[j]=0;
        }
        for(k=j;k<j+white;k++)
        {
            nums[k]=1;
        }
        while(k<nums.size())
        {
            nums[k]=2;
            k++;
        }
    }
};


// OPTIMAL SOLUTION
// DUTCH NATIONAL FLAG ALGORITHM
// Time complexity - O(N)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 0;
        int low=0;
        int high = nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                int temp = nums[mid];
                nums[mid]=nums[low];
                nums[low]=temp;
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                int temp = nums[mid];
                nums[mid]=nums[high];
                nums[high]=temp;
                high--;
            }
        }
    }
};