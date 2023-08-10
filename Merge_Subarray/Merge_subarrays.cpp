//BRUTE FORCE 
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& arr) {
           sort(interval.begin(),interval.end());
            vector<vector<int>> a;
            
            for(int i=0;i<interval.size();i++)
            {   
                if(interval[i][0]!=-1)
                {
                for(int j=i+1;j<interval.size();j++)
                {   
                   if(interval[j][0]!=-1){
                    if(interval[i][1]>=interval[j][0])
                    {
                      interval[i][0]=min(interval[i][0],interval[j][0]);
                      interval[i][1]=max(interval[i][1],interval[j][1]);
                      interval[j][0]=-1;
                      interval[j][1]=-1;
                    }
                   } 
                }
                }
            }
            for(int i=0;i<interval.size();i++)
            {
                if(interval[i][0]!=-1)
                 a.push_back(interval[i]);
            }
            return a ;

        }
}

//OPTIMAL SOLUTION

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
    }
};A