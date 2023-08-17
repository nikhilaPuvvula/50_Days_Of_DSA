//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void findPermute(string s,vector<string> &a,vector<char> &d,int fre[])
	    {
	        if(d.size()==s.length())
	        {
	            string p;
	            for(int i=0;i<d.size();i++)
	            {
	               p+=d[i]; 
	            }
	            a.push_back(p);
	            return;
	        }
	        for(int i=0;i<s.length();i++)
	        {
	            if(!fre[i])
	            {
	                d.push_back(s[i]);
	                fre[i]=1;
	                findPermute(s,a,d,fre);
	                fre[i]=0;
	                d.pop_back();
	            }
	        }
	    }
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<string> a;
		    vector<char> d;
		    int fre[s.length()];
		    for(int i=0;i<s.length();i++)		
		    {
		        fre[i]=0;
		    }
		    findPermute(s,a,d,fre);
		    sort(a.begin(),a.end());
		    a.erase(unique(a.begin(),a.end()),a.end());
		    return a;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends