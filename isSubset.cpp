
// subset available or not

#include <iostream>
#include <unordered_map>

using namespace std;

bool isSubset(int arr[], int n, int sum) {
   if (sum == 0)
      return true;
   if (n == 0)
      return false;


   if (arr[n - 1] > sum)
      return isSubset(arr, n - 1, sum);

   return isSubset(arr, n - 1, sum) || isSubset(arr, n - 1, sum - arr[n - 1]);
}
 

int main()
{
    int arr[] = {1,2,98,-9,0,1,22,1}; 
    int sum = 199;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isSubset(arr, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");

    return 0;
}