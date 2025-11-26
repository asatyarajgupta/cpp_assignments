#include <iostream>
#include <stack>

// Reverse string using push pop



int main(){
    char name[]="DataStructures";
    int top =-1;
    int max = 100;

    std::cout << "Original String : ";
    for (int i = 0; i < sizeof(name)/sizeof(name[0]); i++)
    {
        std::cout << name[i];
    }

    for(int i =0 ; i < sizeof(name)/sizeof(name[0]); i++)
    {
        top++;
        name[top] = name[i];
    }

    std::cout << "\nReversed String : ";
    for(int i = top; i >= 0; i--)
    {
        std::cout << name[i];
    }

    return 0;
}