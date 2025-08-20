#include <stdio.h> 

int main()
{
    //POINTER BASIC
    // int a = 10;
    // int *p;
    // p = &a; //p holds the address of a 
    // printf("%d\n", a);  //print the value of 10
    // printf("%d\n", *p); //prints the value at the address p ie value of a ie 10
    // printf("_____________________________________________________________________________\n");
    // printf("%p\n", p); //value of p ie prints the memory address stored in p (the address of a )
    // printf("%p\n", &a); //address of a
    // printf("_____________________________________________________________________________\n");
    // printf("%p\n", &p); //address of p pointer print
    // // * is called dereferencing operator and & is called referencing operator
    // // %p ,%x ,%u are used to print address


    //ARRAY AND POINTER
    int x[5] = {11,22,33,44,55};
    int *p ;
    p=&x;   //p=x;  //p=&x[0];    //same //x =&x  //*(x+0) = x[0]
    printf("%d\n", *p);   // 11
    //printf("%d\n", *p++); //11
    //printf("%d\n", *++p);  //22 
    //printf("%d\n", ++*p);  //12
   // printf("%d\n", *(p+4));  //55
    //printf("%p\n",p);  // base address of array in p as value
    //printf("%p\n", p++); // base address  of array in  p as value
    //printf("%p\n", ++p); //address of array in p as value  + 1
   // printf("%p\n", x);   //base address of array x
   // printf("%p\n", x+1); //base address + 1
    printf("%d\n", *p + 2); //13
    
    printf("%p\n",&p); //addresss of p
    printf("%p\n",p +1); //address(base address) of array in p as value  + 1
    printf("%p\n",p+2); //address of array in p as value  + 2
    
    p=&x[2];
    printf("%d", *(p-1)); //22
    
    
    

    

    




}
