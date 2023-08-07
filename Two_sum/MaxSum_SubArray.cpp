//BRUTE FORCE APPROACH
//TIME-COMPLEXITY-O(N^3)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum=INT_MIN;
       for(int i=0;i<nums.size();i++)
       {
           int sum=0;
           for(int j=i;j<nums.size();j++)
           {
               int sum=0;
               for(int k=i;k<=j;k++)
               {
                   sum+=nums[k];
               }
               if(sum>maxSum)
                maxSum=sum;
           }
       }
       return maxSum;
    }
}

//OPTIMAL SOLUTION
//TIME-COMPLEXITY-O(N^2)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int maxSum=INT_MIN;
       for(int i=0;i<nums.size();i++)
       {
           int sum=0;
           for(int j=i;j<nums.size();j++)
           {   
               sum+=nums[j];
               if(sum>maxSum)
                maxSum=sum;
           }
       }
       return maxSum;
    }
}

//BEST SOLUTION
// KADANE'S ALGORITHM

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int max = INT_MIN;
       int sum=0;
       for(int i=0;i<nums.size();i++)
       {
            sum+=nums[i];
            if(sum>max)
              max=sum;
            if(sum<0)
              sum=0;
       }
       return max;
    }
};

//In this kadane's algorithm we will initialize two values max,sum
//we will keep on adding nums element to the sum.......if sum goes less than 0 then we start sub array again
//by making sum 0
//if sum is greater than max value we will make max value = sum
//finally we will return max
