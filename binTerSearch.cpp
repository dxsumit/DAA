#include <bits/stdc++.h>
using namespace std;

class Compare
{
    public:
        int compare(int ele1,int ele2,int c=__INT32_MAX__)
        {
            if (c==0)
            {
                int res=0;
                if (ele1<0)
                {
                    res++;
                }
                if (ele2<0)
                {
                    res++;
                }
                return res;
            }
            else if (c!=__INT32_MAX__)
            {
                if (ele1==c || ele2==c)
                {
                    return 1;
                }
                return 0;
            }
            else
            {
                return max(ele1,ele2);
            }
        }
};

class findmax:public Compare
{
    private:
    
    public:
        int oneway(vector<int> v1,int currentpos)
        {
            static int currentmax=v1[0];
            currentmax=compare(currentmax,v1[currentpos]);
            if (v1.size()-1!=currentpos)
            {
                currentpos++;
                oneway(v1,currentpos);
            }
            return currentmax;
        }

        int twoway(vector<int> v1,int startpos,int endpos)
        {
            if (startpos==endpos)
            {
                return v1[startpos];
            }
            int mid;
            mid=(startpos+endpos)/2;
            return max(twoway(v1,startpos,mid),twoway(v1,mid+1,endpos));
        }
        
        int kway(vector<int>v1,int k,int startpos,int endpos)
        {
            static int globalmax=v1[0];
            if (startpos==endpos)
            {
                return v1[startpos];
            }
            // int div=ceil((double(startpos)+double(endpos))/k);
            int div=(startpos+endpos)/k;
            for (int i = 0; i < k; i++)
            {
                startpos=i*div;
                endpos=(i+1)*div;
                int tempmax=kway(v1,k,startpos,endpos);
                if (tempmax>globalmax)
                {
                    globalmax=tempmax;
                }
            }
            return globalmax;            
            
        }
};

int main()
{
    vector<int> v1;
    int input;
    while (cin>>input)
    {
        v1.push_back(input);
    }
    for (auto i = v1.begin(); i!=v1.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    findmax fm1;
    cout<<fm1.oneway(v1,0);
    cout<<endl;
    cout<<fm1.twoway(v1,0,v1.size()-1);
    cout<<endl;
    cout<<fm1.kway(v1,3,0,v1.size()-1);
    

    return 0;
}

