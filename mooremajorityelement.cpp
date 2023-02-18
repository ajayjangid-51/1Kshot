#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &v)
    {
        /*   map<int ,int> m;
          for(auto x:nums){
              m[x]++;
          }
          int n =nums.size();
          vector<int> ans;
          for(auto x:m){
              if(x.second > (n/3)) ans.push_back(x.first);
          }
          return ans; */
        // above approach is taking nlogn time and O(n) space.
        // so for O(n) time and O(1) space use/apply moore voting algorithm
        int c1 = 0, c2 = 0, e1 = 0, e2 = 1;
        int n = v.size();
        for (auto x : v)
        {
            if (x == e1)
            {
                c1++;
            }
            else if (x == e2)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                e1 = x;
                c1 = 1;
            }
            else if (c2 == 0)
            {
                e2 = x;
                c2 = 1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        //
        int e1c = 0, e2c = 0;
        for (auto x : v)
        {
            if (x == e1)
                e1c++;
            else if (x == e2)
                e2c++;
        }
        if (e1c > (n / 3))
            ans.push_back(e1);
        if (e2c > (n / 3))
            ans.push_back(e2);
        return ans;
    }
    // here thse e1 and e2 are candidate elements means they could be our answer but not sure.. so we recheck it by counting the frequency of candidate elements.
};