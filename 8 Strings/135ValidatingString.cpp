#include<iostream>

using namespace std;

bool isValid(const char* password)
{
    int i;
    for (i = 0; password[i] != '\0'; i++)
    {
        if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 97 && password[i] <=122) && 
        !(password[i] >= 48 && password[i] <= 57))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    const char* password1 = "ANK!123";
    if (isValid(password1))
    {
        cout << "Valid Password!";
    }
    else
    {
        cout << "Invalid Password!";
    }
    return 0;
}