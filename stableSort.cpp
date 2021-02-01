#include <iostream>
#include <vector>

using namespace std;


class stableSort
{
private:
    void merge(int arr[],int left,int mid,int right)
    {
        //dividing into 2
        int size1=mid-left+1;
        int size2=right-mid;

        //init 2 subarrays
        int arr1[size1];
        int arr2[size2];

        // copying ele to subarrays
        for (int i = 0; i < size1; i++)
        {
            arr1[i]=arr[left+i];
        }

        for (int i = 0; i < size2; i++)
        {
            arr2[i]=arr[mid+i+1];
        }
        
        int i=0;
        int j=0;
        int k=left;

        //actual merging process
        while (i<size1 && j<size2)
        {
            if (arr1[i]>=arr2[j])
            {
                arr[k]=arr2[j];
                j++;
                k++;
            }
            else
            {
                arr[k]=arr1[i];
                i++;
                k++;
            }
        }

        while (i!=size1)
        {
            arr[k]=arr1[i];
            i++;
            k++;
        }
        
        while (j!=size2)
        {
            arr[k]=arr2[j];
            j++;
            k++;
        }
        
    }
public:
    //count sort(O(n))
    void countSort(int arr[],int size)
    {
        int count[3]={0,0,0};
        int num;
        for (int i = 0; i < size; i++)
        {
            num=arr[i];
            count[num]++;
        }
        // int sum=0;
        // for (int i = 0; i < 3; i++)
        // {
        //     cout<<count[i]<<" ";
        // }
        
        for (int i = 1; i < 3; i++)
        {
            // sum+=count[i];
            // count[i]=sum;
            count[i]+=count[i-1];
        }
        int final[size];
        for (int i = size-1; i >= 0; i--)
        {
            final[count[arr[i]]-1]=arr[i];
            count[arr[i]]-=1;
        }
        for (int i = 0; i < size; i++)
        {
            arr[i]=final[i];
        }
        
        
    }
//merge sort O(nlog(n))
    void mergeSort(int arr[],int left,int right)
    {
        if (left>=right)
        {
            return ;
        }
        int mid=(left+right)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
    }

    //Insertion Sort O(n^2)
    void insertionSort(int arr[],int size)
    {
        for (int i = 1; i < size; i++)
        {
            int key=arr[i];
            int j=i-1;
            while (j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }
        
    }
    void display(int arr[],int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<" ";
        }
        
    }
};


int main()
{
    int size;
    cout<<"What is the size of the array?";
    cin>>size;
    int arr1[size];
    int arr2[size];
    int arr3[size];
    int num;
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter element #"<<i+1<<":";
        cin>>num;
        if (num>2 || num<0)
        {
            i--;
        }
        else
        {
            arr1[i]=num;
            arr2[i]=num;
            arr3[i]=num;
        }
    }
    stableSort s1;
    s1.mergeSort(arr1,0,size-1);
    cout<<"Merge Sort:";
    s1.display(arr1,size);
    cout<<endl;
    s1.insertionSort(arr2,size);
    cout<<"Insertion Sort:";
    s1.display(arr2,size);
    cout<<endl;
    s1.countSort(arr3,size);
    cout<<"Count Sort:";
    s1.display(arr3,size);


    return 0;
}
