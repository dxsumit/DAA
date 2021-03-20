
// count negative numbers..

#include <bits/stdc++.h>
using namespace std;

class Compare
{
public:
    int compareEachOther(int ele1, int ele2,int mode=0)
    {
        if (mode==0)
        {
            return max(ele1,ele2);
        }
        if (mode==1)
        {
            return ele1<ele2? 1: 0;
        }   
    }

};


class findmax : public Compare
{
    private:
    public:
        int oneway(vector<int> v1, int currentpos)
        {
            static int currentmax = v1[0];
            currentmax = compareEachOther(currentmax, v1[currentpos]);
            if (v1.size() - 1 != currentpos)
            {
                currentpos++;
                oneway(v1, currentpos);
            }
            return currentmax;
        }

        int twoway(vector<int> v1, int startpos, int endpos)
        {
            if (startpos == endpos)
            {
                return v1[startpos];
            }
            int mid;
            mid = (startpos + endpos) / 2;
            return compareEachOther(twoway(v1, startpos, mid), twoway(v1, mid + 1, endpos));
        }

        int threeway(vector<int> v1, int startpos, int endpos)
        {
            if (startpos == endpos)
            {
                return v1[startpos];
            }
            int mid1,mid2;
            mid1=((2*startpos)+endpos)/3;
            mid2=(startpos+(2*endpos))/3;               //4 5 6 -1 -2 -3    0,5 1,3
            if (endpos-startpos<2)
            {
                return compareEachOther(threeway(v1,startpos,mid1),threeway(v1,mid1+1,endpos));
            }
            else
            {                
                return compareEachOther(compareEachOther(threeway(v1,startpos,mid1),threeway(v1,mid1+1,mid2)),threeway(v1,mid2+1,endpos));           
            }
        }

        // int kway(vector<int> v1, int k, int startpos, int endpos)
        // {
        //     static int globalmax = v1[0];
        //     if (startpos == endpos)
        //     {
        //         return v1[startpos];
        //     }
        //     // int div=ceil((double(startpos)+double(endpos))/k);
        //     for (int i = 0; i < k; i++)
        //     {
        //         startpos = ((k-i)*startpos + (i*endpos)) / k;
        //         // startpos = i * div;
        //         endpos = ((k-i+1)*startpos + ((i-1)*endpos)) / k;
        //         int tempmax = kway(v1, k, startpos, endpos);
        //         if (tempmax > globalmax)
        //         {
        //             globalmax = tempmax;
        //         }
        //     }
        //     return globalmax;
        // }

        int kway(vector<int>v1, int k, int startPos, int endPos) {
            static int maximum = -(__INT32_MAX__);

            // if size == 1 return that element..
            if(startPos==endPos){
                return v1[startPos];
            }
            // if size is less than k we will use threeWay to find max among them...
            if(endPos-startPos+1 < k) {
                return threeway(v1, startPos, endPos);
            }

            // dividing array into sub-arrays...  
            int curSize = 0; 
            for(int i=k; i>0; i--) {
                curSize = (endPos-startPos)/i;
                maximum = compareEachOther(maximum, kway(v1, k, startPos, (curSize+startPos)));
                startPos = startPos + curSize + 1;
            }
        
            return maximum;
        }
};

class countNeg :public Compare
{
    public:
        int twoway(vector<int>v1,int startpos,int endpos)
        {
            static int ctr=0;
            if (startpos==endpos)
            {
                if (compareEachOther(v1[startpos],0,1)==1)
                {
                    cout<<v1[startpos]<<" ";
                    return ctr++;
                }
                return ctr;
            }
            int mid;
            mid=(startpos+endpos)/2;
            twoway(v1,startpos,mid);
            twoway(v1,mid+1,endpos);
            
            return ctr;   
        }
        int threeway(vector<int>v1,int startpos,int endpos)
        {
            static int ctr=0;
            // cout<<startpos<<" "<<endpos<<endl;
            if (startpos==endpos)
            {
                if (compareEachOther(v1[startpos],0,1)==1)
                {
                    cout<<v1[startpos]<<" ";
                    return ctr++;
                }
                return ctr;
            }
            if(startpos>endpos)
            {
                return ctr;
            }
            int mid1,mid2;
            mid1=((2*startpos)+endpos)/3;
            mid2=(startpos+(2*endpos))/3;               //4 5 6 -1 -2 -3    0,5 1,3
            if (endpos-startpos<2)
            {
                threeway(v1,startpos,mid1);
                threeway(v1,mid1+1,endpos);
            }
            else
            {
                threeway(v1,startpos,mid1);
                threeway(v1,mid1+1,mid2);
                threeway(v1,mid2+1,endpos);
            
            }
            return ctr; 
        }
};

int main()
{
    vector<int> v1;
    int input;
    while (cin >> input)
    {
        v1.push_back(input);
    }
    cout<<"Input array: ";
    for (auto i = v1.begin(); i != v1.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    findmax fm1;
    cout << "Max using one-way method: "<<fm1.oneway(v1, 0);
    cout << endl;
    cout << "Max using two-way method: "<<fm1.twoway(v1, 0, v1.size() - 1);
    cout << endl;
    cout << "Max using three-way method: "<<fm1.threeway(v1, 0, v1.size() - 1);
    cout << endl;
    cout << "Max using k-way method: "<<fm1.kway(v1, 4, 0, v1.size() - 1);
    cout<<endl;

    countNeg cn1;
    int resCountNeg2way=cn1.twoway(v1,0,v1.size()-1);
    cout<<endl;
    cout<<"Number of negative integers using two-way method: "<<resCountNeg2way<<endl;

    int resCountNeg3way=cn1.threeway(v1,0,v1.size()-1);
    cout<<endl;
    cout<<"Number of negative integers using three-way method: "<<resCountNeg3way<<endl;

    return 0;
}