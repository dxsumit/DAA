
// 3way mergesort...

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
class parent
{
public:
    void insertionSort(vector<int> &v1,int left,int right)
    {
        int j, key;
        for (int i = left+1; i < right+1; i++)
        {
            key = v1[i];
            j = i - 1;
            while (j >= left && key < v1[j])
            {
                v1[j + 1] = v1[j];
                j--;
            }
            v1[j + 1] = key;
        }
        return;
    }
    void selectionSort(vector<int> &v2,int left,int right)
    {
        int indexMin, temp;
        for (int i = left; i < right; i++)
        {
            indexMin = i;
            for (int j = i + 1; j < right+1; j++)
            {
                if (v2[j] < v2[indexMin])
                {
                    indexMin = j;
                }
            }
            temp = v2[indexMin];
            v2[indexMin] = v2[i];
            v2[i] = temp;
        }
        return;
    }
    void bubbleSort(vector<int> &v3,int left,int right)
    {
        int temp;
        for (int i = left; i < right+1; i++)
        {
            for (int j = left; j < right; j++)
            {
                if (v3[j] > v3[j + 1])
                {
                    temp = v3[j];
                    v3[j] = v3[j + 1];
                    v3[j + 1] = temp;
                }
            }
        }
        return;
    }
};

class child :public parent
{
private:
    void merge(vector<int>&v1,int left,int mid1,int mid2,int right)
    {
        //dividing into 2
        int size1 = mid1 - left + 1;
        int size2 = mid2 - mid1;
        int size3 = right - mid2;

        //init 2 subarrays
        int arr1[size1];
        int arr2[size2];
        int arr3[size3];
        // cout<<size1<<" "<<size2<<" "<<size3<<endl;
        // copying ele to subarrays
        for (int i = 0; i < size1; i++)
        {
            arr1[i] = v1[left + i];
            
        }
        // cout<<endl;
        for (int i = 0; i < size2; i++)
        {
            arr2[i] = v1[mid1 + i + 1];
            // cout<<arr2[i]<<" ";
        }
        // cout<<endl;
        for (int i = 0; i < size3; i++)
        {
            arr3[i] = v1[mid2 + i + 1];
            // cout<<arr3[i]<<" ";
        }
        // cout<<endl;
        int i = 0;
        int j = 0;
        int k = 0;
        int l=left;

        //actual merging process
        while (i < size1 && j < size2 && k<size3)
        {
            if (arr1[i] >= arr2[j])
            {
                if(arr2[j]<=arr3[k])
                {
                    v1[l] = arr2[j];
                    j++;
                    l++;
                }
                else
                {
                    v1[l]=arr3[k];
                    l++;
                    k++;
                }
            }
            else
            {
                if(arr1[i]<=arr3[k])
                {
                    v1[l] = arr1[i];
                    i++;
                    l++;
                }
                else
                {   
                    v1[l]=arr3[k];
                    l++;
                    k++;
                }
            }
        }
        while (i<size1 && j<size2)
        {
            if(arr1[i]<=arr2[j])
            {
                v1[l]=arr1[i];
                i++;
                l++;
            }
            else{
                v1[l]=arr2[j];
                j++;
                l++;
            }
        }

        while (i<size1 && k<size3)
        {
            if(arr1[i]<=arr3[k])
            {
                v1[l]=arr1[i];
                i++;
                l++;
            }
            else{
                v1[l]=arr3[k];
                k++;
                l++;
            }
        }

        while (k<size3 && j<size2)
        {
            if(arr3[k]<=arr2[j])
            {
                v1[l]=arr3[k];
                k++;
                l++;
            }
            else{
                v1[l]=arr2[j];
                j++;
                l++;
            }
        }
        
        while (i != size1)
        {
            v1[l] = arr1[i];
            i++;
            l++;
        }

        while (j != size2)
        {
            v1[l] = arr2[j];
            j++;
            l++;
        }
        
        while (k != size3)
        {
            v1[l] = arr3[k];
            k++;
            l++;
        }
    }

public:
    void mergeSortInsertion(vector<int> &v1,int left,int right)
    {
        if (right-left<=20)
        {
            return insertionSort(v1,left,right);
        }
        else
        {
            int mid1=((2*left)+right)/3;
            int mid2=(left+(2*right))/3;

            mergeSortInsertion(v1,left,mid1);
            mergeSortInsertion(v1,mid1+1,mid2);
            mergeSortInsertion(v1,mid2+1,right);

            merge(v1,left,mid1,mid2,right);
        }
    }

    void mergeSortSelection(vector<int> &v1,int left,int right)
    {
        if (right-left<=20)
        {
            return selectionSort(v1,left,right);
        }
        else
        {
            int mid1=((2*left)+right)/3;
            int mid2=(left+(2*right))/3;

            mergeSortSelection(v1,left,mid1);
            mergeSortSelection(v1,mid1+1,mid2);
            mergeSortSelection(v1,mid2+1,right);

            merge(v1,left,mid1,mid2,right);
        }
    }

    void mergeSortBubble(vector<int> &v1,int left,int right)
    {
        if (right-left<=20)
        {
            return bubbleSort(v1,left,right);
        }
        else
        {
            int mid1=((2*left)+right)/3;
            int mid2=(left+(2*right))/3;

            mergeSortBubble(v1,left,mid1);
            mergeSortBubble(v1,mid1+1,mid2);
            mergeSortBubble(v1,mid2+1,right);

            merge(v1,left,mid1,mid2,right);
        }
    }
};

int main()
{
    vector<int> v1, v2, v3;
    srand(time(0));
    int num;
    for (int i = 0; i < 100; i++)
    {
        num = (rand() % 1000) + 1;
        v1.push_back(num);
        v2.push_back(num);
        v3.push_back(num);
    }
    for (int i = 0; i < 100; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;

    child c1;
    time_point<steady_clock> start1,start2,start3,end1,end2,end3;
    start1 = steady_clock::now();
    c1.mergeSortInsertion(v1,0,v1.size()-1);
    end1 = steady_clock::now();
    duration<double>elapsed = end1 - start1;
    cout << "Done Merge+Insertion Sort!" << endl;
    cout << "Process took:" << elapsed.count() << " s" << endl;

    start1 = steady_clock::now();
    c1.mergeSortSelection(v2,0,v2.size()-1);
    end1 = steady_clock::now();
    elapsed = end1 - start1;
    cout << "Done Merge+Selection Sort!" << endl;
    cout << "Process took:" << elapsed.count() << " s" << endl;


    start1 = steady_clock::now();
    c1.mergeSortBubble(v3,0,v3.size()-1);
    end1 = steady_clock::now();
    elapsed = end1 - start1;
    cout << "Done Merge+Bubble Sort!" << endl;
    cout << "Process took:" << elapsed.count() << " s" << endl;

    return 0;
}

