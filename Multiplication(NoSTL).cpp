#include <iostream>
using namespace std;

const int MAX_LENGTH = 1024;

int Strlen(char* Str) 
{
    int Count = 0;
    while (Str[Count] != '\0')
    {
        Count++;
    }
    return Count;
}

void InsertDigit(char* Str, int Digit) 
{
    if (Strlen(Str) < MAX_LENGTH)
    {
        int Temp = Digit;
        int DigitsCount = 0;
        while (Digit != 0)
        {
            Digit /= 10;
            DigitsCount++;
        }
        int Iter = 0;
        char* ReverseDigit = new char[DigitsCount + 1];
        while (Temp != 0)
        {
            ReverseDigit[Iter++] = (Temp % 10) + '0';
            Temp /= 10;
        }
        for (size_t i = 0, Str_iter = Strlen(Str), Temp_iter = (Iter - 1); i < Iter; i++, Temp_iter--, Str_iter++)
        {
            Str[Str_iter] = ReverseDigit[Temp_iter];
            if ((i + 1) > Iter)
            {
                Str[Str_iter + 1] = '\0';
            }
        }
    }
    
}

int DetermineDigit(int Val) 
{
    char str[MAX_LENGTH]{};
    for (size_t i = 1; ; i++)
    {
        if (Strlen(str) > Val)
        {
            return (str[Val - 1] - '0');
        }       
        InsertDigit(str, (i*i));
    }
}

int main() 
{
    int Digit;
    cin >> Digit;
    if (Digit > 0 || Digit < 3200000)
    {        
        cout << "Position - \t" <<  DetermineDigit(Digit) << endl;
    }
    else 
    {
        return -1;
    }
}