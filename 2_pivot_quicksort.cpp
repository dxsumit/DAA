
// two pivot quicksort algorithm...

#include<iostream>

using namespace std;

class parent {
    public:

        void getInput(int arr[], int n) {
            cout << "\n Enter the elements of this array : ";
            for(int i=0; i<n; i++) {
                cin >> arr[i];
            }
        }

        void display(int arr[], int n) {
            for(int i=0; i<n; i++) {
                cout << arr[i] << " ";
            }
        }
};

class threeWayQuicksort:public parent {
   private:

      int partition(int arr[], int left, int right, int* leftPivot) {

            if (arr[left] > arr[right]) {
               swap(arr[left], arr[right]);
            }

            // p is the left pivot, and q is the right pivot.
            int p = arr[left];
            int q = arr[right];
            int i = left + 1;
            int j = right - 1;
            int k = left + 1;     // itrator

            while (k <= j) { 
               // if elements are less than the left pivot..
               if (arr[k] < p) { 
                  swap(arr[k], arr[i]); 
                  i++; 
               } 

               // if elements are greater than or equal to the right pivot..
               else if (arr[k] >= q) {
                  while(arr[j] > q && k < j) {
                     j--;
                  }
                  //  swapping the current number in larger window
                  swap(arr[k], arr[j]); 
                  j--; 

               // if that swaped element which is at k is smaller..
                  if(arr[k] < p) { 
                     swap(arr[k], arr[i]); 
                     i++; 
                  } 
               } 
               k++; 
            } 
            //  i and j is start and end index of mid window.
            i--; 
            j++; 

            // bringing pivots to their appropriate positions.. 
            swap(arr[left], arr[i]); 
            swap(arr[right], arr[j]); 

            *leftPivot = i; 
            return j; 
        }

   public:

      void quicksort(int arr[], int left, int right) {
         if (left < right) { 
            int leftPivot, rightPivot; 
            rightPivot = partition(arr, left, right, &leftPivot); 

            quicksort(arr, left, leftPivot - 1); 
            quicksort(arr, leftPivot + 1, rightPivot - 1); 
            quicksort(arr, rightPivot + 1, right); 
         }
      }


};


int main() {

   threeWayQuicksort obj;
   int n;
   cout << "\n Enter the size of array : ";
   cin >> n;
   int arr[n];
   obj.getInput(arr, n);

   cout << "\n Array = ";
   obj.display(arr, n);

   obj.quicksort(arr, 0, n-1);

   cout << "\n Sorted array : ";
   obj.display(arr, n);

   return 0;
}

