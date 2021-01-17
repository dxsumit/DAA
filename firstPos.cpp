#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;
int linearSearch(vector <int> arr)
{
    int size=arr.size();
    int res;
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==-1)
        {
            res=i;
            break;
        }
    }
    return res;
}

int binarySearch(vector <int> arr)
{
    int l=0;
    int size=arr.size();
    int r=size-1;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (mid==0||(arr[mid]==-1 && arr[mid-1]!=-1))
        {
            return mid;
        }
        else if (arr[mid]==-1 && arr[mid-1]==-1)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}

int ternarySearch(vector<int> arr)
{
    int l=0;
    int size=arr.size();
    int r=size-1;
    while (l<=r)
    {
        int mid1=l+((r-l)/3);
        int mid2=r-((r-l)/3);
        if (mid1==0||(arr[mid1]==-1 && arr[mid1-1]!=-1))
        {
            return mid1;
        }
        if(mid2==0||(arr[mid2]==-1 && arr[mid2-1]!=-1))
        {
            return mid2;
        }
        if (arr[mid1]==-1 && arr[mid1-1]==-1)
        {
            r=mid1-1;
        }
        else if (arr[mid2]==-1 && arr[mid2-1]==-1)
        {
            l=mid1+1;
            r=mid2-1;
        }
        else
        {
            l=mid2+1;
        }
    }
    return -1;
}
int main()
{
    vector <int> arr1;
    int flag1=1;
    int flag2=1;
    int num;
    while (flag1==1||flag2==1)
    {
        cout<<"Enter number: ";
        cin>>num;
        arr1.push_back(num);
        if (num==-1 && flag1==1)
        {
            flag1=0;
        }
        if (num!=-1 && flag1==0)
        {
            flag2=0;
            arr1.pop_back();
        }
    }
    for (auto i = 0; i <arr1.size(); i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    time_point <high_resolution_clock> start,end1,end2,end3;
    start=high_resolution_clock::now();
    cout<<"The first -1 has been found at index "<<linearSearch(arr1)<<" using linear search."<<endl;
    end1=high_resolution_clock::now();
    duration<double>elapsed=end1-start;
    cout<<"Process took:"<<elapsed.count()<<" s"<<endl;
    cout<<"The first -1 has been found at index "<<binarySearch(arr1)<<" using binary search."<<endl;
    end2=high_resolution_clock::now();
    elapsed=end2-end1;
    cout<<"Process took:"<<elapsed.count()<<" s"<<endl;
    cout<<"The first -1 has been found at index "<<ternarySearch(arr1)<<" using ternary search."<<endl;
    end3=high_resolution_clock::now();
    elapsed=end3-end2;
    cout<<"Process took:"<<elapsed.count()<<" s"<<endl;

    return 0;
}