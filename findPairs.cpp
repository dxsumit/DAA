
// Input:   Integer Array A and an integer p
// Question: Does there exist q and r in A such that p=q+r


#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;


bool search(int arr[], int n, int key){
   int start = 0;
   int end = n;
   while(start<=end){
      int mid=(start+end)/2;

      if (arr[mid]==key){
         return true;
      }
      else if(arr[mid]>key){
         end=mid-1;
      }
      else{
         start=mid+1;
      }
   }
   return false;
}


// comparing pairs..
bool logic1(int arr[], int n, int p) {
   
   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         if(arr[i] + arr[j] == p) 
            return true;
      }
   }
   return false;
}


bool logic2(int arr[], int n, int p) {
   sort(arr, arr+n);
   int front = 0, end = n-1;

   while(front < end) {
      if(arr[front]+arr[end] == p)
         return true;

      (arr[front]+arr[end] < p) ? front++ : end--; 
   }
   return false;
}

  
bool logic3(int arr[], int n, int p) {
   sort(arr, arr+n);
   for(int i=n-1; i>=0; i--) {
      int toFind = 0;
      toFind = p-arr[i];
      if(toFind > arr[i] || toFind < arr[0]) {
         continue;
      }

      if(search(arr, i-1, toFind)) {
         return true;
      } 
   }
   return false;
}


int main() {

   int size, p;
   cout << " What is size of array :  ";
   cin >> size;

   if(size < 1){
      cout << " This size is not possible...";
      return 0;
   }

   int arr[size];
   for(int i=0; i<size; i++){
      cout << "Enter the element :";
      cin >> arr[i];
   }
   cout << "Enter P : ";
   cin >> p;

   auto start_time = chrono::steady_clock::now();
   logic1(arr, size, p) ? cout<<"Yes, It is there \n" : cout<<"No, not present \n";
   auto end_time = chrono::steady_clock::now();
   double time_taken = double(chrono::duration_cast <chrono::microseconds> (end_time - start_time).count());
   cout <<" Time Taken in this method is " <<time_taken << " microseconds \n\n";

   start_time = chrono::steady_clock::now();
   logic2(arr, size, p) ? cout<<"Yes, It is there \n" : cout<<"No, not present \n";
   end_time = chrono::steady_clock::now();
   time_taken = double(chrono::duration_cast <chrono::microseconds> (end_time - start_time).count());
   cout <<" Time Taken in this method is " <<time_taken << " microseconds \n\n";

   start_time = chrono::steady_clock::now();
   logic3(arr, size, p) ? cout<<"Yes, It is there \n" : cout<<"No, not present \n";
   end_time = chrono::steady_clock::now();
   time_taken = double(chrono::duration_cast <chrono::microseconds> (end_time - start_time).count());
   cout <<" Time Taken in this method is " <<time_taken << " microseconds \n\n";

   return 0;
}
