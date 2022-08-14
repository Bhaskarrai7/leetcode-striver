#include <bits/stdc++.h>

    using namespace std;
    

    int ans =0;
     void merge(vector<int>& nums,int s,int m,int l)
    {
        vector<int> b; int i,j;int k=0;
        for(i =s,j=m+1; i<=m and j<=l;)
        {
            if(nums[i]<nums[j]){b.push_back(nums[i++]);}
            else
            {b.push_back(nums[j++]);ans+=(m-i+1);}
        }
         //if(j<=l)ans= ans + ((m-i+1)*(l-j+1));
        while(i<=m){b.push_back(nums[i++]);}
        while(j<=l){b.push_back(nums[j++]);}
        
        //return vector
        for(k=0,i=s;i<=l;i++,k++)
            nums[i]=b[k];
    
         
    }
    
    void mergesort(vector<int>& nums,int s,int l)
    {
        if(s>=l)return;
            int m = (l+s)/2;
            mergesort(nums,s,m);
            mergesort(nums,m+1,l);
            merge(nums,s,m,l);
        
    }
    int reversePairs(vector<int>& nums) {
         int s =0;
        int l = nums.size()-1;
     //   int m = (s+l)/2;
        mergesort(nums,s,l);
    //    mergesort(nums,m+1,l);
      //  for(auto x:nums)cout<<x<<" ";
        return ans;
    }

int main()
{

    vector<int>nums={5,4,3,2,1};
    cout<<reversePairs(nums);
}
    