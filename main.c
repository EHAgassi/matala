#include <stdio.h>
#include <math.h>
#include "NumClass.h"


int main(){
int num_a,num_b;
scanf("%d%d", &num_a, &num_b);



printf("The Armstrong numbers are:");
    for(int i=num_a;i<=num_b; i++ )
    {
        if (isArmstrong(i))
        {
            printf(" %d",i);
        }
    } 
printf("\nThe Palindromes are:");
        for(int i = num_a; i<=num_b; i++ )
    {   
        if (isPalindrome(i)==1)
        {
           printf(" %d",i);
        }
    }
        
        
printf("\nThe Prime numbers are:");
        for(int i = num_a; i<=num_b; i++ )
    {   
       
        if (isPrime(i)==1)
        {
           printf(" %d" ,i);
        }
        
        
    }
printf("\nThe Strong numbers are:");
    for(int i = num_a; i<=num_b; i++ )
        {  
            if (isStrong(i)==1)
            {
            printf(" %d",i);
            }
        }
    
    return 0;

}
