#include <math.h>
#include <stdio.h>
#include "NumClass.h"
int numDigit(int);
int isArm(int, int);

int isArmstrong(int num)
{
    double ndigit = numDigit(num);
    if(num==isArm(num, ndigit))
    {
        return 1;

    }
    return 0;
}

int isArm(int num, int p)
{
    if(num==0)
    {
        return 0;
    }
    return (isArm(num/10 , p) + pow(num%10 , p));
}
int numDigit(int num)
{
    int n= num;
    int count =0;
    while(n!=0)
    {
        count++;
        n=n/10;
    }
    return count;
}

int isPalindrome(int num)
{
    int nDigit = numDigit(num); 
    if(nDigit==1 || nDigit==0){
        return 1;
    }
    double firstCh = (num / pow(10 ,nDigit-1));
    if(num%10!= (int)firstCh)
    {
        return 0;
    }
    num -= ((int)firstCh)*pow(10.0, nDigit-1.0);
    num-= num%10;
    num/=10;
    return isPalindrome(num);
}

// int main()
// {int a,b=4564;
// //   for(int i = 0; i<1000;i++){
// //     if (isPalindrom(i))
// //     {
// //       /* code */
// //     }    
// //   }

// a = isPalindrome(b);
//     printf("%d\n", a);
//     return 0;
// }