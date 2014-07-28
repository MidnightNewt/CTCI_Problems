//Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

//Stack or in place swaps
//Stack: n extra space, O(2n)
//Swaps: one char of extra space, O(1.5n)

//Constants
const int STR_SIZE = 6;
const char ORIG_STR[STR_SIZE] = "abcde";
const char REVERSE_STR[STR_SIZE] = "edcba";

//Function Headers
void reverse(char*);

#include <iostream>
using namespace std;
#include <stack>
#include <assert.h>

int main()
{
   char str[STR_SIZE];
   strcpy(str, ORIG_STR);

    assert(strcmp(str, ORIG_STR) == 0);
    cout << "Original string: " << str << endl;
    reverse(str);
    assert(strcmp(str, REVERSE_STR) == 0);
    cout << "Reversed string: " << str << endl;

    return 0;
}

void reverse(char* str)
{
    if (str == NULL)
    {
        cout << "Give me something to work with here!" << endl;
        return;
    }

    stack<char>  myStack;
    int index = 0;

    while (str[index] != '\0')
    {
        myStack.push(str[index]);
        index++;
    }
    assert(index == STR_SIZE - 1);

    index = 0;
    while (!myStack.empty())
    {
        str[index] = myStack.top();
        myStack.pop();
        index++;
    }
    assert(index == STR_SIZE - 1);

}

