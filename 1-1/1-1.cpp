//Implement an algorithm to determine if a string has all unique characters.  What if you cannot use additional data structures?

#include <iostream>
using namespace std;
#include <string>
#include <cmath>

//Function headers
bool stringHasUniqueChars(string);
bool stringHasUniqueCharsOneDS(string);
bool stringHasUniqueCharsPrimeEncoding(string);
int findNthPrime(int);

const int CHARTYPES = 95; //for ascii printable characters
const int MINCHARVAL = 32; //for ascii printable characters (assuming continuos printables)
const int MAXCHARVAL = MINCHARVAL + CHARTYPES; //for ascii printable characters (assuming continuous)

int main()
{
    
    string testStr = "hyldahl";
    
    if (stringHasUniqueCharsPrimeEncoding(testStr))
    {
        cout << "String is unique." << endl;
    }
    
    else
    {
        cout << "String is NOT unique." << endl;
    }

    return 0;
}

//O(n)
bool stringHasUniqueChars(string str)
{
    if (str.size() > CHARTYPES)
        return false;
    
    bool isUnique = true;
    
    //32 to 126
    
    bool charArray[CHARTYPES];
    
    for(int i = 0; i < CHARTYPES; i++)
    {
        charArray[i] = false;
    }
    
    for (int i = 0; i < str.size(); i++)
    {
        if (charArray[str[i] - MINCHARVAL])
        {
            isUnique = false;
            break;
        }
        
        else
        {
            charArray[str[i] - MINCHARVAL] = true;
        }
    }
    
    return isUnique;
}

//O(.5n^2)
bool stringHasUniqueCharsOneDS(string str)
{
    if (str.size() > CHARTYPES)
        return false;
    
    for (int i = 1; i < str.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }  
    
    return true;
}

//O(n^1.5)
//Optimal over checking back except in two cases:
//-large-ish constant factors outweigh n^2 at first
//-possible long processing when product gets too big (when string is too long, or many character types used)
//Can optimize minimum prime zone for more frequently used character range (with some extra coding)

bool stringHasUniqueCharsPrimeEncoding(string str)
{
    if (str.size() > CHARTYPES)
        return false;
    
    unsigned long long product = 1;
    int currentPrime;
    
    for (int i = 0; i < str.size(); i++)
    {
        currentPrime = findNthPrime(MAXCHARVAL - str[i]);
        cout << "currentPrime: " << currentPrime << endl;
        
        if (product % currentPrime == 0)
            return false;
        
        product *= currentPrime;
        cout  << "product: " << product << endl;

    }

    return true;
}

int findNthPrime(int n)
{
    int prime = 0;
    int primeCount = 4;
    int primeCandidate;
    bool isPrime = true;
    
    if (n <= 0) return -1;
    if (n == 1) return 2;
    if (n == 2) return 3;
    if (n == 3) return 5;
    if (n == 4) return 7;
    
    
    primeCandidate = 11;
    while (primeCount < n)
    {
        for (int divisor = 3; divisor <= floor(sqrt(primeCandidate)); divisor += 2)
        {
            if (primeCandidate % divisor == 0)
            {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime)
        {
            primeCount++;
            prime = primeCandidate;
        }
        
        isPrime = true;
        primeCandidate += 2;
    }
 
    return prime;
}

//Bitwise version of hashtable using int (32 bits) for only upper or lower case alphabet
//Or use larger type for more space (max is double with 64 bits (8 bytes))
//Or use multiple ints or doubles for extra space (2 doubles for 95 bits)
//O(n) with no data structure other than primitive type (used as a data structure)


