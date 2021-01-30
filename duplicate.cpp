
// duplicate exist in array or not 

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class duplicate {
   private:
      bool search(vector<int> arr,  int key){
         int start = 0;
         int end = arr.size();
         while(start < end){
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


   public:

      void method1(int arr[], int n) {
         vector <int> dup_arr;
         sort(arr, arr+n);

         for(int i=0; i<n-1; i++) {
            if(arr[i] == arr[i+1] && !search(dup_arr, arr[i]) ) {
               dup_arr.push_back(arr[i]);
               i++;
            }
         }

         // printing...
         if(dup_arr.size() > 0){
            for(int i=0; i<dup_arr.size(); i++) {
            cout<<dup_arr[i] <<" ";
            }
         } else {
            cout<<" NO DUPLICATE EXISTS.... \n";
         }  
      }


      // frequency method using unorder_map....
      void method2(int arr[], int n) {
         unordered_map<int, int> frequency;
         for(int i=0; i<n; i++){
            frequency[arr[i]]++;
         }

         bool is_duplicate = false;
         unordered_map<int, int>:: iterator i;

         for(i=frequency.begin(); i != frequency.end(); i++) {
            if(i->second > 1) {
               cout << i->first << " ";
               is_duplicate = true;
            }
         }
         if( !is_duplicate ) {
            cout<<" NO DUPLICATE EXISTS.... \n";
         }
      }
};


int main() {
   int n;
   cout<<" Enter size of array :  ";
   cin >> n;
   int arr[n];
   
   for(int i=0; i<n; i++) {
      cout << " Enter a[" << i << "] : ";
      cin >> arr[i];
   }

   duplicate obj;
   cout <<"\n Algorithm 1 >> ";
   obj.method1(arr, n);

   cout <<"\n Algorithm 2 >> ";
   obj.method2(arr, n);

   return 0;
}