
//   1st and 2nd minimum in max heap.

#include <iostream>

using namespace std;

class parent {
    public:

        void heapify(int arr[], int i, int n) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int maximum = i;

            if(left < n && arr[left] > arr[maximum]){
                maximum = left;
            }
            if(right < n && arr[right] > arr[maximum]){
                maximum = right;
            }

            if(maximum != i){
                swap(arr[i], arr[maximum]);
                //  heapy the subtree
                heapify(arr, maximum, n);
            }
        }

        void max_heap(int arr[], int n) {
            int startPos = (n/2) - 1;
            for(int i=startPos; i>=0; i--){
                heapify(arr, i, n);
            }
        }

        void insertionSort(int arr[], int startPos, int size) {
            for (int i = startPos+1; i < size; i++) {
                int key = arr[i];
                int j = i - 1;

                while (key < arr[j] && j >= startPos) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = key;
            }
        }

        void display_heap(int arr[], int n) {
            cout << "\n Max Heap = ";
            for(int i=0; i<n; i++) {
                cout << arr[i] << " ";
            }
        }
};


class find_min:public parent {
    public:
        void method1(int arr[], int n) {
            int first_min = __INT32_MAX__;
            int second_min = __INT32_MAX__;
            int startPos = n/2;

            // firstMin
            for(int i=startPos; i<n; i++) {
                if(arr[i] < first_min) {
                    first_min = arr[i];
                }
            }

            // secondMin
            for(int i=startPos; i<n; i++) {
                if(arr[i] < second_min && arr[i] != first_min) {
                    second_min = arr[i];
                }
            }

            cout << "\n First Minimum = " << first_min << "\n Second Minimum = " << second_min << "\n";
        }

        void method2(int arr[], int n) {
            // sorting the leaf nodes and choosing min.
            insertionSort(arr, n/2, n);
            cout << "\n First Minimum = " << arr[n/2] << "\n Second Minimum = " << arr[(n/2)+1] << "\n";
        }
};


int main() {

    int n;
    cout << "\n Enter the size of Array : ";
    cin >> n;
    int arr[n];
    cout << "\n Enter the elements : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    find_min obj;
    obj.max_heap(arr, n);
    obj.display_heap(arr, n);

    cout << "\n\n Method 1:";
    obj.method1(arr, n);

    cout << "\n Method 2:";
    obj.method2(arr, n);

    return 0;

}