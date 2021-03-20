
// recursive and iterative way of binary and ternary search..


#include <iostream>
#include <algorithm>

using namespace std;

class sorting {
    private:
        void swapping(int &a, int &b) {      
            int temp;
            temp = a;
            a = b;
            b = temp;
        }

    public:
        void bubbleSort(int array[], int size) {
            for(int i = 0; i<size; i++) {
                int swaps = 0;         
                for(int j = 0; j<size-i-1; j++) {
                    if(array[j] > array[j+1]) {      
                        swapping(array[j], array[j+1]);
                        swaps = 1;    
                    }
                }
                if(!swaps)
                    break;       
            }
        }
};


class searching : public sorting {
    public:
        void binarySearch(int arr[], int n, int key) {
            int mid, start, end;
            start = 0;
            end = n;
            
            while(end >= start) {
                mid = (start+end)/2;
                if(arr[mid] == key) {
                    cout << "  Iterative Way :: Element " << key << " is found in the given Array " << endl;
                    return;
                
                } if(arr[mid] < key) {
                    start = mid+1;
                
                } else {
                    end = mid-1;
                }
            }
            cout << "  Iterative Way :: Element " << key << " is NOT found in the given Array " << endl;
        }


        void recursion_binary(int arr[], int start, int end, int key) {
            if(end >= start) {
                int mid = (end + start)/2;
                if(arr[mid] == key) {
                    cout << "  Recursive Way :: Element " << key << " is found in the given Array " << endl;
                    return;
                
                } if(arr[mid] < key) {
                    return recursion_binary(arr, mid+1, end, key);
                
                } else {
                    return recursion_binary(arr, start, mid-1,key);
                }
            } 
            cout << "  Recursive Way :: Element " << key << " is NOT found in the given Array " << endl;
        }


        void ternarySearch(int arr[], int n, int key) {
            int start, end, mid1, mid2;
            start = 0;
            end = n;

            while(end >= start) {
                mid1 = start + (end-start)/3;
                mid2 = mid1 + (end-start)/3;

                if(arr[mid1] == key) {
                    cout << "  Iterative Way :: Element " << key << " is found in the given Array " << endl;
                    return;
                }
                if(arr[mid2] == key) {
                    cout << "  Iterative Way :: Element " << key << " is found in the given Array " << endl;
                    return;
                
                } else if(arr[mid1] > key) {
                    end = mid1-1;
                
                } else if(arr[mid2] < key) {
                    start = mid2+1;
                
                } else {
                    start = mid1+1;
                    end = mid2-1;
                }
            }
            cout << "  Iterative Way :: Element " << key << " is NOT found in the given Array " << endl;
        }


        void recursion_ternary(int arr[], int start, int end, int key) {
            if(end >= start) {
                int mid1 = start + (end-start)/3;
                int mid2 = mid1 + (end-start)/3;

                if(arr[mid1] == key) {
                    cout << "  Recursive Way :: Element " << key << " is found in the given Array " << endl;
                    return;
                }
                if(arr[mid2] == key) {
                    cout << "  Recursive Way :: Element " << key << " is found in the given Array " << endl;
                    return;
                
                } else if(arr[mid1] > key) {
                    return recursion_ternary(arr, start, mid1-1, key);
                
                } else if(arr[mid2] < key) {
                    return recursion_ternary(arr, mid2+1, end, key);
                
                } else {
                    return recursion_ternary(arr, mid2+1, mid2-1, key);
                }
            }
            cout << "  Recursive Way :: Element " << key << " is NOT found in the given Array " << endl;
        }

};


int main() {
   int n;
   cout << " Enter size of an Array : ";
   cin >> n;
   int arr[n];
   for(int i=0; i<n; i++) {
      cout << " Enter the element : ";
      cin >> arr[i];
   }
   int key;
   cout << "\n  Enter the key to find : ";
   cin >> key;

   searching obj;              // class object..
   obj.bubbleSort(arr, n);

   cout << "\n Binary Search \n";
   obj.binarySearch(arr, n-1, key);
   obj.recursion_binary(arr, 0, n-1, key);
   
   cout << "\n Ternary Search \n";
   obj.ternarySearch(arr, n-1, key);
   obj.recursion_ternary(arr, 0, n-1, key);

   return 0;
}