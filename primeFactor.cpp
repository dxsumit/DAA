// finding prime factors of a given number...

#include <iostream>
#include <cmath>
using namespace std;

class findFactors{
    public:
        void factorize(int num)
        {
            int limit=sqrt(num);
            cout<<"Factors of "<<num<<": ";
            while (num%2==0)
            {
                cout<<"2 ";
                num=num/2;
            }
            for (int i = 3; i <= limit; i=i+2)
            {
                while(num%i==0)
                {
                    cout<<i<<" ";
                    num=num/i;
                }
            }
            if(num>2)
            {
                cout<<num<<endl;
            }
        }
};

int main()
{
    int num;
    cout<<"Enter number to factorize:";
    cin>>num;
    findFactors f1;
    f1.factorize(num);

    return 0;
}
