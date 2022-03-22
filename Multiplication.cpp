#include <iostream>
using namespace std;

const int MAX_LENGTH = 3200000 + 1;

int Strlen(char* Str) 
{
    int Count = 0;
    while (Str[Count] != '\0')
    {
        Count++;
    }
    return Count;
}

#pragma region OldMethod
void InsertDigit(char* Str, int Digit) 
{
        int Temp = Digit;
        int DigitsCount = 0;
            while (Digit != 0)
            {
                Digit /= 10;
                DigitsCount++;
            }
        int Iter = 0;
        char ReverseDigit[DigitsCount + 1]{};
            while (Temp != 0)
            {
                ReverseDigit[Iter++] = (Temp % 10) + '0';
                Temp /= 10;
            }
        for (int i = 0, Str_iter = Strlen(Str), Temp_iter = (Iter - 1); i < Iter; i++, Temp_iter--, Str_iter++)
        {
            Str[Str_iter] = ReverseDigit[Temp_iter];
            if ((i + 1) > Iter)
            {
                Str[Str_iter + 1] = '\0';
            }
        }
}
#pragma endregion

void StrConcat(char* Holder, const char* Source) 
{
    for (int i = Strlen(Holder), iter = 0; Source[iter] != '\0'; i++, iter++)
    {
        Holder[i] = Source[iter];
        if (Source[iter + 1] == '\0')
        {
            Holder[i + 1] = '\0';
        }     
    }
}

int DetermineDigit(int Val) 
{
    char str[MAX_LENGTH]{};
    for (int i = 1; ; i++)
    {
        if (Strlen(str) > Val)
        {          
            return (str[Val - 1] - '0');
        }      
        /* InsertDigit(str, (i*i)); */
        StrConcat(str, (to_string((i*i)).c_str()));
    }
}

int main() 
{
    try
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
    catch(const exception& ex)
    {
        cout << ex.what() << endl;
    }
}