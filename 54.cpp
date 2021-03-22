#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>v1,int start,int end,int key)
{
    int mid;
    mid=(start+end)/2;
    if(end<=start)
    {
        if(key<v1[start])
        {
            return start;
        }
        return start+1;
    }
    if(v1[mid]>key)
    {
        return binarySearch(v1,start,mid-1,key);
    }
    if (key>v1[mid])
    {
        return binarySearch(v1,mid+1,end,key);
    }
    return mid+1;
}

void insertionSort(vector<int>&v1)
{
    int j,key,posToInsert;
    for (int i = 1; i < v1.size(); i++)
    {
        key=v1[i];
        j=i-1;
        posToInsert=binarySearch(v1,0,j,key);
        while(j>=posToInsert)
        {
            v1[j + 1] = v1[j];
            j--;
        }
        v1[j + 1] = key;
    }
    return;
}

int main()
{
    vector<int>v1;
    int input;
    while(cin>>input)
    {
        v1.push_back(input);
    }
    cout<<"Input Array : ";
    for (auto i = v1.begin(); i !=v1.end(); i++)
    {
        cout<<*i<<" ";
    }
    
    insertionSort(v1);

    cout<<"Sorted Array : ";
    for (auto i = v1.begin(); i !=v1.end(); i++)
    {
        cout<<*i<<" ";
    }
    return 0;
}