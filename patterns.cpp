#include <iostream>

using namespace std;

void p1(int num)
{
    int a=num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 1 ;j <= a; j++)
        {
            cout<<j<<" ";
        }
        a--;
        cout<<endl;
    }
    return;
}

void p2(int num)
{
    int a=1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <=num; j++)
        {
            if (j<a)
            {
                cout<<"  ";
            }
            else
            {
            cout<<j<<" ";
            }
        }
        a++;
        cout<<endl;
    }
    
}

void p3(int num)
{
    int a=1;
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <=num; j++)
        {
            if (j<=a)
            {
                cout<<j<<" ";
            }
        }
        a++;
        cout<<endl;
    }
}

void p4(int num)
{
    int a=num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <=num; j++)
        {
            if (j<a)
            {
                cout<<"  ";
            }
            else
            {
                cout<<j<<" ";
            }
        }
        a--;
        cout<<endl;
    }
    
}

void p5(int num)
{
    int a=1;
    int b=num;
    for (int i = 0; i < num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            if (b>=a)
            {
                if (j>=a && j<=b)
                {
                    cout<<j<<" ";
                }
                else
                {
                    cout<<"  ";
                }
            }
            else
            {
                if (j<=a && j>=b)
                {
                    cout<<j<<" ";
                }
                else
                {
                    cout<<"  ";
                }
            }
            
        }
        a++;
        b--;
        cout<<endl;
    }
    
}
int main()
{
    // cout<<"Hello";
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    // p1(num);
    // p2(num);
    // p3(num);
    // p4(num);
    p5(num);

    return 0;
}