#include<iostream>    
using namespace std;

class find_max {
   public:

      // simple linear search...
      void method1(int arr[], int n) {
         int maxValue, comparision=0;

         maxValue = arr[0];
         for(int i=1; i < n; i++) {
            if(arr[i] > maxValue){
               maxValue = arr[i];
            }
            comparision++;
         }
      cout<<"method 1 => max value : " <<maxValue << ", Comparision: "<< comparision << "\n" ;
      }

      //  traversing elements from both side in a single loop...
      void method2(int arr[], int n) {
         int maxValue, localMax, comparision=0;
         int front = 0;
         int end = n-1;

         maxValue = arr[0];   // default value..
         while(end >= front) {
            localMax = max(arr[front], arr[end]);
            maxValue = max(localMax, maxValue);
            front++;
            end--;
            comparision = comparision+2;
         }

      cout<<"method 2 => max value : " <<maxValue << ", Comparision: "<< comparision << "\n";
      }

      // 2 step count, and comparing them for maximum....
      void method3(int arr[], int n) {
         int maxValue, localMax, comparision=0;
         int i = 0;

         if(n%2 != 0){
            maxValue = arr[0];
             i = 1;

         } else {
            maxValue = max(arr[0], arr[1]);
            i = 2;
         }

         for(i; i<n; i=i+2){
            localMax = max(arr[i], arr[i+1]);
            maxValue = max(localMax, maxValue);
            comparision = comparision+2;
         }

      cout<<"method 3 => max value : " <<maxValue << ", Comparision: "<< comparision << "\n";
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
   
   find_max obj;
   obj.method1(array, n);
   obj.method2(array, n);
   obj.method3(array, n);
   
   return 0;
}
