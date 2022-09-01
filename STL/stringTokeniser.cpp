#include <iostream>
#include <cstring>
using namespace std;

// convert string into tokens

// char *strtok(char *s,char *delimeters)
// similar to python split
// returns a token on each subsequent call
//  on the first call function shoudl be passed withs tring arguement 's'
//  on subsequent calls we should pass the string argument as null

int main()
{
    char s[100] = "Today is a rainy day";
    char *ptr = strtok(s, " ");
    // ptr pointes to the first token in the given string
    cout << ptr << endl;
    // get next token

    while (ptr != NULL)
    {
        cout << ptr << endl;
        ptr = strtok(NULL, " ");
    }

    return 0;
}