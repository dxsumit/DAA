
// max using 1-way 2-way 3-way, k-way....  


#include <bits/stdc++.h>

using namespace std;

class Compare {
    public:
        int compare(int ele1,int ele2,int c=__INT32_MAX__) {
            if (c==0) {
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
                return max(ele1, ele2);
            }
        }

        int maxOfThree(int a, int b=0, int c= -(__INT32_MAX__)) {
            // cout << "\n return max of " << a << " " << b << " " << c << " = " << max(max(a,b), c) << "\n";
            return max(max(a,b), c);
        }

};


class findmax:public Compare {
    public:
        int oneway(vector<int> v1,int currentpos)
        {
            static int currentmax=v1[0];
            currentmax = compare(currentmax,v1[currentpos]);
            if (v1.size()-1!=currentpos)
            {
                currentpos++;
                oneway(v1,currentpos);
            }
            return currentmax;
        }

        int twoway(vector<int> v1,int startpos,int endpos)
        {
            if (startpos == endpos)
            {
                return v1[startpos];
            }
            int mid;
            mid=(startpos+endpos)/2;
            return max(twoway(v1,startpos,mid),twoway(v1,mid+1,endpos));
        }

        int Three_way(vector<int> v1, int startPos, int endPos) {
            
            if(startPos == endPos) {
                // cout << "\n return " << v1[startPos];
                return v1[startPos];
            }
            int mid1 = startPos + (endPos - startPos)/3;
            int mid2 = endPos - (endPos - startPos)/3;
            
            if(endPos-startPos < 2){
                return maxOfThree(Three_way(v1, startPos, mid1), Three_way(v1, mid2, endPos));
            
            } else{
                return maxOfThree(Three_way(v1, startPos, mid1), Three_way(v1, mid1+1, mid2-1) , Three_way(v1, mid2, endPos));
            }
            
        }

        int kway(vector<int>v1, int k, int startPos, int endPos) {
            static int maximum = -(__INT32_MAX__);

            // if size == 1 return that element..
            if(startPos==endPos){
                return v1[startPos];
            }
            // if size is less than k we will use threeWay to find max among them...
            if(endPos-startPos+1 < k) {
                return Three_way(v1, startPos, endPos);
            }

            // dividing array into sub-arrays...  
            int curSize = 0; 
            for(int i=k; i>0; i--) {
                curSize = (endPos-startPos)/i;
                maximum = max(maximum, kway(v1, k, startPos, (curSize+startPos)));
                startPos = startPos + curSize + 1;
            }
        
            return maximum;
        }
};


int main()
{
    vector<int> v1;
    int input;
    int n;
    cout << " Enter Size of Array :  ";
    cin >> n;
    for(int j=0; j<n; j++) {
        cin >> input;
        v1.push_back(input);
    }
    cout << "\n Our Array ::  ";

    for (auto i = v1.begin(); i!=v1.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

    findmax fm1;

    cout << "\n  Maximum in Array using 1-way search : " << fm1.oneway(v1,1);
    cout<<endl;
    cout << "\n  Maximum in Array using 2-way search : " << fm1.twoway(v1,0,v1.size()-1);
    cout<<endl;
    cout << "\n  Maximum in Array using 3-way search : " << fm1.Three_way(v1, 0, v1.size()-1);
    cout<<endl;
    
    int k;
    cout << "\n\n   Enter value of K for k-way search : " ;
    cin >> k;
    cout << "\n  Maximum in Array using k-way search : " << fm1.kway(v1,4,0,v1.size()-1);
   
    return 0;
}