// Author: Lochan Basyal

// LCS using memoization
#include <iostream>
#include <fstream>
#include<string>
using namespace std;
 
const int maximum = 1000;
 
// Returns length of LCS for X[0..m-1], Y[0..n-1] 

int lcs(string X, string Y, int m, int n, int dp[][maximum])
{
    // base case
    if (m == 0 || n == 0)
        return 0;
 
    // if the same state has already been
    // computed
    if (dp[m - 1][n - 1] != -1)
        return dp[m - 1][n - 1];
 
    // if equal, then we store the value of the
    // function call
    if (X[m - 1] == Y[n - 1]) {
 
        // store it in arr to avoid further repetitive
        // work in future function calls
        dp[m - 1][n - 1] = 1 + lcs(X, Y, m - 1, n - 1, dp);
 
        return dp[m - 1][n - 1];
    }
    else {
 
        // store it in arr to avoid further repetitive
        // work in future function calls
        dp[m - 1][n - 1] = max(lcs(X, Y, m, n - 1, dp),
                               lcs(X, Y, m - 1, n, dp));
 
        return dp[m - 1][n - 1];
    }
}


// This is my main function under which I connected with two different .txt
// files a.txt and b.txt. Also, I tested with adding and rearranging letters in these two
// files to demonstrate the operation of LCS using memoization.
int main()
{ 
    string X, Y;
    int n,m;

// Reading the file a.txt 
 fstream myFile;
    myFile.open("a.txt", ios::in); //read
    if(myFile.is_open()) {
       // string X;
      while (getline(myFile, X)){
      m = X.length();
     }
    }
// Reading the file b.txt
    fstream myfile;
    myfile.open("b.txt", ios::in); //read
    if(myfile.is_open()) {
   // string Y;
    while(getline(myfile, Y)){
         n = Y.length();
    }
    }
/*
// I used this portion of the code for the alternate testing of the operation
// of Longest Common Subsequence.
    string X = "AGGTAB";
    string Y = "GXTXAYB";
   int m = X.length();
   int n = Y.length();
 */
    int dp[m][maximum];
 
    // assign -1 to all positions
    memset(dp, -1, sizeof(dp));
 
    cout << "Length of LCS: " << lcs(X, Y, m, n, dp);
 
    return 0;
}
