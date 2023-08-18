//O(N^2) solution

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
         return false;
        int count=0;
        int v=0;
        unordered_map<char,int> m;
        for(int i=0;i<s1.length();i++)
        {
             if(m.find(s1[i])!=m.end())
                m[s1[i]]++;
             else
               m[s1[i]]=1;
             count++; 
        }
       
        for(int i=0;i<s2.length();i++)
        {  
          unordered_map<char,int> l = m; 
           int k=count;
          if(l.find(s2[i])!=l.end())
          { 
            if(l[s2[i]]!=0)
            {
              k--;
              l[s2[i]]--;
            }
          }
           for(int j=i+1;j<s2.size();j++)
           { 
             if(l.find(s2[j])!=l.end())
             { 
               if(l[s2[j]]!=0)
               {
                k--;
                l[s2[j]]--;
               }
               else
                break;
             }
             else
             {
               break;
             }
           }
           if(k==0)
            v=1;
          }
          if(v==1)
            return true;
        
        return false;
}
};