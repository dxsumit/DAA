

// subset sum problem.....


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class subsetSum {
   public:
      void getSubsets(int arr[], int n, int sum) {
         int this_sum;
         for(int i=0; i<pow(2.0, n); i++){
            this_sum = 0;
            vector<int> current_subset;

            for(int j=0; j<n; j++) {
               if((i & (1<<j)) != 0) {  // getting current index status..
                  current_subset.push_back(arr[j]);
                  this_sum += arr[j];
               }
            }
            // print
            if(this_sum == sum){
               for(int i=0; i<current_subset.size(); i++) {
                  cout<<current_subset[i] << " ";
               }
               cout << "\n";
            }
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
   obj.getSubsets(arr, n, sum);

   return 0;
}