#include <iostream>
#include <string>
using namespace std;

char DetermineDigit(int Digit) 
{
    string Buffer;
    for (int i = 1; i < Digit + 1; i++)
    {
        Buffer += to_string((i*i));
    }
    return Buffer[Digit - 1];
} 

int main() 
{
    int Digit;
    cin >> Digit;
    if (Digit > 0 && Digit < 3200000)
    {        
        cout << "Position - \t" <<  DetermineDigit(Digit) << endl;
    }
    else 
    {
        return -1;
    }
}