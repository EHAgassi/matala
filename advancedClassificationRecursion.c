#include <math.h>
#include <stdio.h>
#include "NumClass.h"
int numDigit(int);
int isArm(int, int);
 int reverse(int num);

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

    if(num == reverse(num))
    {
        return 1;
    }
    
    return 0;
}


   int reverse(int num)
{
    int digit = (int)log10(num);
    if(num == 0)
        return 0;

    return ((num%10 * pow(10, digit)) + reverse(num/10));
}