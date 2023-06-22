#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n; 
    cout << "Enter the number of matrices: ";
    cin >> n;
    int p[n + 1]; 
    cout << "Enter dimensions of matrices (Ai x A(i+1)):\n";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    int m[n + 1][n + 1]; // array to store minimum number of scalar multiplications
    // initialize diagonal elements with 0
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }
    
    //outer loop -> chain length(no. of matrices)
    for (int l = 2; l <= n; l++) {
    	//inner loop -> iterates through each subproblem and calcu minimum
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            //for the split point in subproblem
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }
    cout << "Minimum number of scalar multiplications for each subproblem:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j >= i) {
                cout << m[i][j] << " ";
            } else {
                cout << "  ";
            }
        }
        cout << "\n";
    }
    return 0;
}

