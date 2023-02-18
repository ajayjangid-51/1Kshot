#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    // Write your code here.
    // int i = 0 , j = 1;
    /*while(j< n and i<n){
        if((knows(i,j) and knows(j,i)) or (!knows(i,j)and !knows(j,i))){
            i+=2;
            j+=2;
        }else if(knows(i,j) and !knows(j,i)){
           // i is for sure in not celebirty and j could be celebrity
           i = j;
           j = j+1;
        }else{
            // j is for sure is not celebrity
            j= j+1;
        }

    }*/
    stack<int> S;
    for (int i = 0; i < n; i++)
        S.push(i);
    while (S.size() > 1)
    {
        int a = S.top();
        S.pop();
        int b = S.top();
        S.pop();
        if (knows(a, b) and !knows(b, a))
        {
            S.push(b);
        }
        else
        {
            S.push(a);
        }
    }
    // if(i>=n and j>=n) return -1;
    int i = S.top();
    for (int k = 0; k < n; k++)
    {
        if (k == i)
            continue;
        if (knows(i, k))
            return -1;
        if (!knows(k, i))
            return -1;
    }
    return i;
}