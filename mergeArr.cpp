
//  merge two sorted array..

#include <iostream>
#include <map>

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


class merge:public parent {        
    public:
        void hashMethod(int arr1[], int n, int arr2[], int m) {
            map<int, bool> hash_map;

            // inserting first array
            for(int i = 0; i < n; i++) {
                hash_map[arr1[i]] = true;       
            }
            
            // inserting second array
            for(int i=0; i<m; i++) {
                hash_map[arr2[i]] = true;
            }

            map<int, bool>::iterator itr;
            for(itr = hash_map.begin(); itr != hash_map.end(); itr++) {
                cout << " " << itr->first;
            }
        }


        // O(n+m)
        void method2(int arr1[], int n, int arr2[], int m) {
            int i=0, j=0;
            while(i<n && j<m) {
                if(arr1[i] < arr2[j]) {
                    cout << arr1[i] << " ";
                    i++;
                
                } else {
                    cout << arr2[j] << " ";
                    j++;
                }
            }
            //  printing remaining element of arr1;
            while(i<n) {
                cout << arr1[i] << " ";
                i++;
            }

            // printing remaining element of arr2;
            while(j<m) {
                cout << arr2[j] << " ";
                j++;
            }
        }

        // O(n*m)
        void insertionMethod(int arr1[], int n, int arr2[], int m, int arr3[]) {
            // insert arr1 in arr3
            for(int i=0; i<n; i++) {
                arr3[i] = arr1[i];
            }

            //  inserting arr2 in arr3 using insertion method
            for(int i=0; i<m; i++) {
                int key = arr2[i];
                arr3[n+i] = key;
                int j = n+i-1;

                while(key < arr3[j] && j >= 0) {
                    arr3[j + 1] = arr3[j];
                    j--;
                }
                arr3[j+1] = key;
            }

            display(arr3, n+m);
        }
};


int main() {

    merge obj;

    int n,m;
    cout << "\n Enter the size of array 1: ";
    cin >> n;
    int arr1[n];
    obj.getInput(arr1, n);

    cout << "\n Enter the size of array 2: ";
    cin >> m;
    int arr2[m];
    obj.getInput(arr2, m);

    int arr3[m+n];

    cout << "\n Array 1 = ";
    for(int i=0; i<n; i++){
        cout << " " << arr1[i];
    }

    cout << "\n Array 2 = ";
    for(int i=0; i<m; i++){
        cout << " " << arr2[i];
    }

    cout << "\n\n Hash Map Method : ";
    obj.hashMethod(arr1, n, arr2, m);

    cout << "\n Using Method 2 : ";
    obj.method2(arr1, n, arr2, m);

    cout << "\n Using Insertion Method : ";
    obj.insertionMethod(arr1, n, arr2, m, arr3);
    cout << endl;

    return 0;

}

