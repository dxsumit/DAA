#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

// constructor
class max_min {
   public:
      int maximum, minimum;

      max_min(int arr[], int n) {
         maximum = arr[0], minimum = arr[0];

         for(int i=1; i < n; i++) {
            if(arr[i] > maximum) {
               maximum = arr[i];
            } 

            if(arr[i] < minimum) {
               minimum = arr[i];
            }   
         }
      }
};


int main() {
   
   int n;
   cout<<"How many Element in Array :  ";
   cin>>n;

   int array[n];
   for(int i=0; i<n; i++){
      cout<<"Enter a Element :  ";
      cin>>array[i];
   } 

   // not possible for length less than 2...
   if(n <= 2) {
      cout << "Not possible for an array length less than 3";
      return 0;
   }

   max_min obj(array, n);
   srand(time(0));
   int i = rand()%n;

   // creating random if no. is either max or min..
   while(array[i] == obj.maximum || array[i] == obj.minimum) {
         i = rand()%n;
   }

   cout << array[i] << " is our output which in neither MAXIMUM nor MINIMUM.";

   return 0;
}
