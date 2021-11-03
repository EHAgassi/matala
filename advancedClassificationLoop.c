#include <stdio.h>
#include <math.h>
#include "NumClass.h"
int numDigit(int);

int isPalindrome(int num)
{
    int n= num;
    int reverseNum=0;
    while(n!=0)
    {
        reverseNum = reverseNum*10 +n%10;
        n=n/10;
    }
    if(num==reverseNum)
    {
        return 1;
    }
    return 0;
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

int isArmstrong(int num)
{

        int count = numDigit(num);
        int n=num;
        double sum =0;
        while(n > 0)
        {
            sum+= pow(n%10, (int)count);
            n=n/10;
        }
    if(((int)sum)==num)
    {
        return 1;
    }
    return 0;
}

// int main()
// {
//     int a = isArmstrong(11);
// printf("%d", a );
// }