#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
class parent
{
public:
    void insertionSort(vector<int> &v1,int left,int right)
    {
        int j, key;
        // int size=right-left;
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
        for (int i = left; i < right; i++)
        {
            for (int j = left; j < right-(right-left); j++)
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
    void merge(vector<int>&v1,int left,int mid,int right)
    {
        // cout<<"Before merge"<<endl;
        // for (int i = left; i < right+1; i++)
        // {
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        //dividing into 2
        int size1 = mid - left + 1;
        int size2 = right - mid;

        //init 2 subarrays
        int arr1[size1];
        int arr2[size2];

        // copying ele to subarrays
        for (int i = 0; i < size1; i++)
        {
            arr1[i] = v1[left + i];
        }

        for (int i = 0; i < size2; i++)
        {
            arr2[i] = v1[mid + i + 1];
        }

        int i = 0;
        int j = 0;
        int k = left;

        //actual merging process
        while (i < size1 && j < size2)
        {
            if (arr1[i] >= arr2[j])
            {
                v1[k] = arr2[j];
                j++;
                k++;
            }
            else
            {
                v1[k] = arr1[i];
                i++;
                k++;
            }
        }

        while (i != size1)
        {
            v1[k] = arr1[i];
            i++;
            k++;
        }

        while (j != size2)
        {
            v1[k] = arr2[j];
            j++;
            k++;
        }
        // cout<<"After merge"<<endl;
        // for (int i = left; i < right+1; i++)
        // {
        //     cout<<v1[i]<<" ";
        // }
        // cout<<endl;
        // cout<<endl;

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
            int mid=(left+right)/2;

            mergeSortInsertion(v1,left,mid);
            mergeSortInsertion(v1,mid+1,right);

            merge(v1,left,mid,right);
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
            int mid=(left+right)/2;

            mergeSortSelection(v1,left,mid);
            mergeSortSelection(v1,mid+1,right);

            merge(v1,left,mid,right);
        }
    }

    void mergeSortBubble(vector<int> &v1,int left,int right)
    {
        if (right-left<=20)
        {
            // bubbleSort(v1,left,right);
            return selectionSort(v1,left,right);
        }
        else
        {
            int mid=(left+right)/2;

            mergeSortBubble(v1,left,mid);
            mergeSortBubble(v1,mid+1,right);

            merge(v1,left,mid,right);
        }
    }
};

int main()
{
    vector<int> v1, v2, v3;
    srand(time(0));
    int num;
    for (int i = 0; i < 1000; i++)
    {
        num = (rand() % 1000) + 1;
        v1.push_back(num);
        v2.push_back(num);
        v3.push_back(num);
    }
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << v1[i] << " ";
    // }
    // cout << endl;
    // parent p1;
    // p1.insertionSort(v1,0,v1.size());

    // for (int i = 0; i < 100; i++)
    // {
    //     cout << v1[i] << " ";
    // }
    // cout << endl;

    // cout << "Done Insertion Sort!" << endl;

    // p1.selectionSort(v2);

    // for (int i = 0; i < 100; i++)
    // {
    //     cout << v2[i] << " ";
    // }
    // cout << endl;

    // cout << "Done selection Sort!" << endl;

    // p1.bubbleSort(v3,0,v3.size()-1);

    // for (int i = 0; i < v3.size(); i++)
    // {
    //     cout << v3[i] << " ";
    // }
    // cout << endl;

    // cout << "Done Bubble Sort!" << endl;

    child c1;
    time_point<steady_clock> start1,start2,start3,end1,end2,end3;
    start1 = steady_clock::now();
    c1.mergeSortInsertion(v1,0,v1.size()-1);
    end1 = steady_clock::now();
    duration<double> elapsed = end1 - start1;
    cout << "Done Merge+Insertion Sort!" << endl;
    cout << "Process took:" << elapsed.count() << " s" << endl;
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << v1[i] << " ";
    // }
    // cout << endl;

    start1 = steady_clock::now();
    c1.mergeSortSelection(v2,0,v2.size()-1);
    end1 = steady_clock::now();
    elapsed = end1 - start1;
    cout << "Done Merge+Selection Sort!" << endl;
    cout << "Process took:" << elapsed.count() << " s" << endl;

    // for (int i = 0; i < 100; i++)
    // {
    //     cout << v2[i] << " ";
    // }
    // cout << endl;

    start1=steady_clock::now();
    c1.mergeSortBubble(v3,0,v3.size()-1);
    end1=steady_clock::now();
    elapsed=end1-start1;
    cout << "Done Merge+Bubble Sort!" << endl;
    cout << "Process took:" << elapsed.count() << " s" << endl;
    // cout << endl;
    // for (int i = 0; i < 100; i++)
    // {
    //     cout << v3[i] << " ";
    // }
    // cout << endl;

    return 0;
}