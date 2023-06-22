#include <bits/stdc++.h>

using namespace std;

void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  // Print the characters at the first row
  cout << "    ";
  for (int j = 0; j < m; j++) {
    cout << s2[j] << " ";
  }
  cout << endl;

  // Print the LCS matrix
  for (int i = 0; i <= n; i++) {
    if (i > 0) {
      cout << s1[i - 1] << " ";
    } else {
      cout << "  ";
    }
    for (int j = 0; j <= m; j++) {
      if (j > 0) {
        cout << dp[i][j] << " ";
      } else {
        cout << "0 ";
      }
    }
    cout << endl;
  }

  // Retrieve the LCS string
  int len = dp[n][m];
  string lcsStr(len, ' ');
  int i = n, j = m, index = len - 1;

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      lcsStr[index] = s1[i - 1];
      i--;
      j--;
      index--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }

  // Print the LCS and its length
  cout << "The Longest Common Subsequence is: " << lcsStr << endl;
  cout << "Length of LCS: " << len << endl;
}

int main() {

  string s1 = "abcde";
  string s2 = "bdgek";

  cout << "The Longest Common Matrix is " << endl;
  lcs(s1, s2);

  return 0;
}

