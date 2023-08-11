bool comp(pair<char,int>&a,pair<char,int>&b)
    {
        return a.second>b.second;
    }
class Solution {
public:
    
    string frequencySort(string s) {
       unordered_map<char,int> a;
       for(int i=0;i<s.length();i++)
       {
           if(a.find(s[i])!=a.end())
           {
               a[s[i]]+=1;
           }
           else
           {
               a[s[i]]=1;
           }
       } 
       vector<pair<char,int>> b;
       for (auto& it : a) {
        b.push_back(it);
       }
       sort(b.begin(),b.end(),comp);
       string st;
       for(int i=0;i<b.size();i++)
       {
           for(int j=0;j<b[i].second;j++)
           {
               st.push_back(b[i].first);
           }
       }
       return st;
    }
};