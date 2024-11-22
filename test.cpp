#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of ways to distribute toy cars
int countWays(int S, int k)
{
    // Create a 2D array to store the number of ways
    // dp[i][s] represents the number of ways to distribute
    // s cars among i children, with each child having at most k cars.
    vector<vector<int>> dp(4, vector<int>(S + 1, 0));

    // Initialize base case
    dp[0][0] = 1;

    // Fill the dp table using bottom-up approach
    for (int i = 1; i <= 3; i++)
    {
        for (int s = 0; s <= S; s++)
        {
            // Initialize the current cell
            dp[i][s] = 0;

            // Try distributing 0 to s cars to the current child
            for (int x = 0; x <= s && x <= k; x++)
            {
                dp[i][s] += dp[i - 1][s - x];
            }
        }
    }

    return dp[3][S];
}

int main()
{
    int S, k;
    cout << "Enter the total number of cars (S): ";
    cin >> S;
    cout << "Enter the maximum number of cars each child can have (k): ";
    cin >> k;

    int ways = countWays(S, k);
    cout << "Number of ways to distribute the cars: " << ways << endl;

    return 0;
}
