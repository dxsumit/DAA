//   3 different logic to determine GCD and LCM of 2 integers...

#include <iostream>
using namespace std;


class GCD {
   public:

      int method1(int a, int b) {
         while(a != b) {
            if(a > b) {
               a = a-b;
            
            } else {
               b = b-a;
            } 
         }
         return a;
      }

      //  euclid method
      int method2(int a, int b) {
         int num1, num2, temp = 0;
         num1 = (a > b) ? a : b;
         num2 = (a < b) ? a : b;
         temp = num2;

         while (num1 % num2 != 0) {
            temp = num1 % num2;
            num1 = num2;
            num2 = temp;
         }
         return temp;
      }
};

class LCM {
   public:

      //  incremental method...
      int method1(int a, int b) {
         int lcm = (a > b)? a : b;    //  assigning max to lcm
         while(1) {
            if(lcm % a == 0 && lcm % b == 0){
               break;
            }
            lcm++;
         }
         return lcm;
      }

      // LCM = (a*b)/GCD
      int method2(int a, int b, int gcd) {
         int lcm;
         lcm = (a*b)/gcd;   //  LCM = (a*b)/GCD

         return lcm;
      }
};


int main() {
   int a, b;
   int gcd, lcm;

   cout<< "Enter Two number :  ";
   cin>> a >> b; 

   cout<<"\n GCD  \n";
   GCD gcd_obj;
   gcd = gcd_obj.method1(a,b);
   cout<< " Method 1 => GCD of " << a << " and " << b << " is : " << gcd << "\n";
   gcd = gcd_obj.method2(a,b);
   cout<< " Method 2 => GCD of " << a << " and " << b << " is : " << gcd << "\n";

   cout<<"\n LCM  \n";
   LCM lcm_obj;
   lcm = lcm_obj.method1(a,b);
   cout<< " Method 1 => LCM of " << a << " and " << b << " is : " << lcm << "\n";
   lcm = lcm_obj.method2(a,b, gcd);
   cout<< " Method 2 => LCM of " << a << " and " << b << " is : " << lcm << "\n";

   return 0;
}