

//   is subset with given sum problem....



#include <iostream>
#include <cmath>

using namespace std;

class subsetSum {
   public:
      void isSubsets(int arr[], int n, int sum) {
         int this_sum, flag = 0;

         for(int i=0; i<pow(2.0, n); i++){
            this_sum = 0;
            for(int j=0; j<n; j++) {
               if((i & (1<<j)) != 0) {  // getting current index status..
                  this_sum += arr[j];
               }
            }
            // print
            if(this_sum == sum){
               cout << "\n Found subset with given sum.. \n";
               flag = 1;
               break;
            }
         }
         if(flag == 0) {
            cout << "\n Could not found subset with given sum.. \n";
         }
      }
};

int main() {

   int n;
   cout << " Enter size of Array : ";
   cin >> n;
   int arr[n];
   for(int i=0; i<n; i++) {
      cout<< " Enter element of array : ";
      cin >> arr[i];
   }
   int sum;
   cout << "\n Now enter sum of subset : ";
   cin >> sum;

   subsetSum obj;
   obj.isSubsets(arr, n, sum);

   return 0;
}