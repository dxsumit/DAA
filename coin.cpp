// minimum number of coins required for given change..

#include <iostream>
#include <vector>
using namespace std;


class coinExchange {
    private:
        void merge(int arr[], int left, int mid, int right) {
            //dividing into 2
            int size1 = mid - left + 1;
            int size2 = right - mid;

            //init 2 subarrays
            int arr1[size1];
            int arr2[size2];

            // copying ele to subarrays
            for (int i = 0; i < size1; i++) {
                arr1[i] = arr[left + i];
            }

            for (int i = 0; i < size2; i++) {
                arr2[i] = arr[mid + i + 1];
            }

            int i = 0, j = 0;
            int k = left;

            //actual merging process
            while (i < size1 && j < size2) {
                if (arr1[i] >= arr2[j]) {
                    arr[k] = arr2[j];
                    j++;
                    k++;
                } else {
                    arr[k] = arr1[i];
                    i++;
                    k++;
                }
            }
            // inserting remaining elements of arr1
            while (i != size1) {
                arr[k] = arr1[i];
                i++;
                k++;
            }
            // inserting remaining elements of arr2                                                                                                    
            while (j != size2) {
                arr[k] = arr2[j];
                j++;
                k++;
            }
        }


        void mergeSort(int arr[], int left, int right) {
            if (left < right) {
                // mid is the point where the array is divided into two subarrays
                int mid = (left + right) / 2;

                mergeSort(arr, left, mid);
                mergeSort(arr, mid + 1, right);

                // Merge the sorted subarrays
                merge(arr, left, mid, right);
            }
        }

    public:
        void getInput(int arr[], int n) {
            cout << "\n Enter the elements of this array : ";
            for(int i=0; i<n; i++) {
                cin >> arr[i];
            }
        }

        void change(int arr[], int n, int total) {
            mergeSort(arr, 0, n-1);     // sorting array

            int remaining = total;
            int i = n-1, count = 0;
            vector<pair <int, int>> res;
            while(remaining != 0 && i >= 0) {
                if(remaining >= arr[i]){
                    count = remaining/arr[i];
                    remaining = remaining % arr[i];
                    res.push_back(make_pair(arr[i], count));
                }
                i--;
            }

            if(remaining != 0){
                cout << "\n => Exact Exchange is NOT possible for such total.. \n";
            } else {
                for(int i=0; i<res.size(); i++) {
                    cout<< "(" <<res[i].first<< ", "<<res[i].second << ") "; 
                }
            }
            
        } 
};


int main() {

    coinExchange obj;
    int n;
    cout << "\n Enter Size of Array : ";
    cin >> n;
    int arr[n];
    obj.getInput(arr, n);

    cout << " Enter total : ";
    int total;
    cin >> total;

    obj.change(arr, n, total);

    return 0;
}



