//   3 different logic to determine GCD and LCM of 2 integers...

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class GCD
{
private:
    vector <int> factorize(int num)
    {
        vector <int> v1;
        int limit=sqrt(num);
        cout<<" Factors of "<<num<<": ";
        while (num%2==0)
        {
            cout<<"2 ";
            v1.push_back(2);
            num=num/2;
        }
        for (int i = 3; i <= limit; i=i+2)
        {
            while(num%i==0)
            {
                cout<<i<<" ";
                v1.push_back(i);
                num=num/i;
            }
        }
        if(num>2)
        {
            cout<<num;
            v1.push_back(num);
        }
        cout<<endl;
        return v1;
    }

    vector <int> Intersection(vector <int>v1,vector <int>v2)
    {
        int i=0;
        int j=0;
        vector<int> v3;
        while (i<v1.size() && j<v2.size())
        {
            if (v1[i]>v2[j])
            {
                j++;
            }
            else if(v1[i]<v2[j])
            {
                i++;
            }
            else
            {
                v3.push_back(v1[i]);
                i++;
                j++;
            }
        }
        return v3;
    }

public:
    int method1(int a, int b)
    {
        while (a != b)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
        return a;
    }

    //  euclid method
    int method2(int a, int b)
    {
        int num1, num2, temp = 0;
        num1 = (a > b) ? a : b;
        num2 = (a < b) ? a : b;
        temp = num2;

        while (num1 % num2 != 0)
        {
            temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        return temp;
    }

    //naive method
    int method3(int a,int b)
    {
        auto temp1=factorize(a);
        auto temp2=factorize(b);
        auto temp3=Intersection(temp1,temp2);
        int resInt=1;
        for (auto i= temp3.begin(); i!=temp3.end(); i++)
        {
            // cout<<*i<<" ";
            resInt*=(*i);
        }
        return resInt;
    }
};

class LCM
{
private:
    vector <int> factorize(int num)
    {
        vector <int> v1;
        int limit=sqrt(num);
        cout<<" Factors of "<<num<<": ";
        while (num%2==0)
        {
            cout<<"2 ";
            v1.push_back(2);
            num=num/2;
        }
        for (int i = 3; i <= limit; i=i+2)
        {
            while(num%i==0)
            {
                cout<<i<<" ";
                v1.push_back(i);
                num=num/i;
            }
        }
        if(num>2)
        {
            cout<<num;
            v1.push_back(num);
        }
        cout<<endl;
        return v1;
    }

    vector <int> Union(vector <int>v1,vector <int>v2)
    {
        int i=0;
        int j=0;
        vector<int> v3;
        while (i<v1.size() && j<v2.size())
        {
            if (v1[i]>v2[j])
            {
                v3.push_back(v2[j]);
                j++;
            }
            else if(v1[i]<v2[j])
            {
                v3.push_back(v1[i]);
                i++;
            }
            else
            {
                v3.push_back(v1[i]);
                i++;
                j++;
            }
        }
        while (i<v1.size())
        {
            v3.push_back(v1[i]);
            i++;
        }
        while (j<v2.size())
        {
            v3.push_back(v2[j]);
            j++;
        }

        return v3;
    }

public:
    //  incremental method...
    int method1(int a, int b)
    {
        int lcm = (a > b) ? a : b; //  assigning max to lcm
        while (1)
        {
            if (lcm % a == 0 && lcm % b == 0)
            {
                break;
            }
            lcm++;
        }
        return lcm;
    }

    // LCM = (a*b)/GCD
    int method2(int a, int b, int gcd)
    {
        int lcm;
        lcm = (a * b) / gcd; //  LCM = (a*b)/GCD

        return lcm;
    }

    int method3(int a,int b)
    {
        auto temp1=factorize(a);
        auto temp2=factorize(b);
        auto temp3=Union(temp1,temp2);
        int resUni=1;
        for (auto i= temp3.begin(); i!=temp3.end(); i++)
        {
            // cout<<*i<<" ";
            resUni*=(*i);
        }
        return resUni;
    }
};

int main()
{
    int a, b;
    int gcd, lcm;

    cout << "Enter Two number :  ";
    cin >> a >> b;

    cout << "\n GCD  \n";
    GCD gcd_obj;
    gcd = gcd_obj.method1(a, b);
    cout << " Method 1 => GCD of " << a << " and " << b << " is : " << gcd << "\n";
    gcd = gcd_obj.method2(a, b);
    cout << " Method 2 => GCD of " << a << " and " << b << " is : " << gcd << "\n";
    gcd=gcd_obj.method3(a,b);
    cout << " Method 3 => GCD of " << a << " and " << b << " is : " << gcd << "\n";

    cout << "\n LCM  \n";
    LCM lcm_obj;
    lcm = lcm_obj.method1(a, b);
    cout << " Method 1 => LCM of " << a << " and " << b << " is : " << lcm << "\n";
    lcm = lcm_obj.method2(a, b, gcd);
    cout << " Method 2 => LCM of " << a << " and " << b << " is : " << lcm << "\n";
    lcm = lcm_obj.method3(a, b);
    cout << " Method 3 => LCM of " << a << " and " << b << " is : " << lcm << "\n";

    return 0;
}