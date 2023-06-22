#include <iostream>
using namespace std;
int sum(int arr[], int start, int end)
{
 if (start == end) {
 return arr[start];
 }
 int mid = (start + end) / 2;
 int left = sum(arr, start, mid);
 int right = sum(arr, mid + 1, end);
 int total = left + right;
 return total;
}
int main()
{
 int arr[] = {5, 8, 2, 3,
2,97,4,1,98,23,45,21,19,4,260,3692,456,987,647,90,8};
 int n = sizeof(arr) / sizeof(arr[0]);
 int total = sum(arr, 0, n - 1);
 cout << "The sum of elements of array is = " << total << endl;
 return 0;
}
