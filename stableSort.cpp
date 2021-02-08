

// stable sort 


#include <iostream>
#include <vector>

using namespace std;

class stableSort
{
private:
    void merge(int arr[], int left, int mid, int right)
    {
        //dividing into 2
        int size1 = mid - left + 1;
        int size2 = right - mid;

        //init 2 subarrays
        int arr1[size1];
        int arr2[size2];

        // copying ele to subarrays
        for (int i = 0; i < size1; i++)
        {
            arr1[i] = arr[left + i];
        }

        for (int i = 0; i < size2; i++)
        {
            arr2[i] = arr[mid + i + 1];
        }

        int i = 0;
        int j = 0;
        int k = left;

        //actual merging process
        while (i < size1 && j < size2)
        {
            if (arr1[i] >= arr2[j])
            {
                arr[k] = arr2[j];
                j++;
                k++;
            }
            else
            {
                arr[k] = arr1[i];
                i++;
                k++;
            }
        }

        while (i != size1)
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }

        while (j != size2)
        {
            arr[k] = arr2[j];
            j++;
            k++;
        }
    }

public:
    //count sort(O(n))
    void countSort(int arr[], int size, int pos[])
    {
        int count[3] = {0, 0, 0};
        int num;
        for (int i = 0; i < size; i++)
        {
            num = arr[i];
            count[num]++;
        }
        // int sum=0;
        for (int i = 0; i < size; i++)
        {
            pos[i] = i;
        }

        for (int i = 1; i < 3; i++)
        {
            // sum+=count[i]; 2 2 2
            // count[i]=sum; 2 4 6
            count[i] += count[i - 1];
        }
        int final[size];
        for (int i = size - 1; i >= 0; i--)
        {
            final[count[arr[i]] - 1] = arr[i];
            pos[count[arr[i]] - 1] = i;
            count[arr[i]] -= 1;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i] = final[i];
        }
    }
    //merge sort O(nlog(n))
    // void mergeSort(int arr[],int left,int right,int pos[])
    // {
    //     if (left>=right)
    //     {
    //         return ;
    //     }
    //     int mid=(left+right)/2;

    //     mergeSort(arr,left,mid);
    //     mergeSort(arr,mid+1,right);

    //     merge(arr,left,mid,right);
    // }

    //Insertion Sort O(n^2)
    // void insertionSort(int arr[],int size,int pos[])
    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         pos[i]=i;
    //     }
    //     for (int i = 1; i < size; i++)
    //     {
    //         int key=arr[i];
    //         int j=i-1;
    //         while (j>=0 && arr[j]>key)
    //         {
    //             arr[j+1]=arr[j];
    //             j--;
    //         }
    //         arr[j+1]=key;
    //         pos[i]=j+1;
    //     }

    // }
    void insertionSort(vector<pair<int, int>> v1)
    {
        // for (int i = 0; i < size; i++)
        // {
        //     pos[i]=i;
        // }
        for (int i = 1; i < v1.size(); i++)
        {
            int key = v1[i].first;
            int j = i - 1;
            while (j >= 0 && v1[j].first > key)
            {
                v1[j + 1].first = v1[j].first;
                v1[j + 1].second = v1[j].second;
                // pos[j]=j+1;
                j--;
            }
            v1[j + 1].first = key;
            v1[j + 1].second = i;
            // pos[j+1]=i;
        }
        cout << "Insertion Sort:";

        displayvec(v1);
    }
    void display(int arr[], int size, int pos[])
    {
        for (int i = 0; i < size; i++)
        {
            cout << "{" << arr[i] << "," << pos[i] << "} ";
        }
        cout << endl;
        // cout<<"Position:";
        // for (int i = 0; i < size; i++)
        // {
        //     cout<<pos[i]<<" ";
        // }
    }
    void displayvec(vector<pair<int, int>> v1)
    {
        int size = v1.size();
        for (int i = 0; i < size; i++)
        {
            cout << "{" << v1[i].first << "," << v1[i].second << "} ";
        }
        cout << endl;
    }

    void bubbleSort(vector<pair<int, int>> array, int size)
    {
        for (int i = 0; i < size; i++)
        {
            int k = 0;
            int swaps = 0;
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j].first > array[j + 1].first)
                {
                    // swapping..
                    // positions..
                    k = array[j + 1].second;
                    array[j + 1].second = array[j].second;
                    array[j].second = k;

                    // value
                    k = array[j + 1].first;
                    array[j + 1].first = array[j].first;
                    array[j].first = k;

                    swaps = 1;
                }
            }
            if (!swaps)
                break;
        }

        cout << endl;
        cout << "Bubble Sort:";

        for (int i = 0; i < array.size(); i++)
        {
            cout << "{" << array[i].first << "," << array[i].second << "} ";
        }
        cout<<endl;
    }
};

int main()
{
    int size;
    cout << "What is the size of the array?";
    cin >> size;
    int arr1[size];
    // int arr2[size];
    vector<pair<int, int>> v1, v2;
    int arr3[size];
    int pos1[size];
    int pos2[size];
    int pos3[size];
    int num;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element #" << i + 1 << ":";
        cin >> num;
        if (num > 2 || num < 0)
        {
            i--;
        }
        else
        {
            arr1[i] = num;
            // arr2[i]=num;
            v1.push_back(make_pair(num, i));
            // arr3[i]=num;
            v2.push_back(make_pair(num, i));
        }
    }
    stableSort s1;
    s1.bubbleSort(v2, v2.size());
    // s1.displayvec(arr1,size,pos1);
    cout << endl;
    s1.insertionSort(v1);
    // cout<<"Insertion Sort:";
    // s1.displayvec(v1);
    cout << endl;
    s1.countSort(arr1, size, pos3);
    cout << "Count Sort:";
    s1.display(arr1, size, pos3);
    // cout<<"Display:   ";
    // s1.display(pos3,siz

    return 0;
}