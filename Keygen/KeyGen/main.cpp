#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <ctime>

using namespace std;

string encryptKey(long long key)
{
    char keys[9] = {'F', 'S', 'w', 'a', 'A', 'v', 'z', 'Y', 'n'};
    string encrypted;
    int nums[12];

    for(int i = 11; i >= 0; --i)
    {
        nums[i] = key % 10;
        key /= 10;
    }

    for(int i = 0; i < 12; ++i)
    {
        if(i == 4 || i == 8)
        {
            encrypted.push_back('-');
        }
        for(int j = 0; j < 9; ++j)
        {
            if(nums[i] == (j + 1))
            {
                encrypted.push_back(keys[j]);
                break;
            }
        }
    }

    return encrypted;
}

long long generateKey()
{
    srand(time(0));

    int numbers[12];
    long long key = 0;

    while(true)
    {
        int tempSum = 0;

        for(int i = 0; i < 12; ++i)
        {
            numbers[i] = rand() % 9 + 1;
        }

        for(int i = 0; i < 11; ++i)
        {
            tempSum += numbers[i];
        }

        if(tempSum % numbers[11] == 0 && numbers[11] != 1)
        {
            break;
        }
    }

    for(int i = 0; i < 12; ++i)
    {
        key += numbers[i];
        key *= 10;
    }
    key /= 10;

    return key;
}

int main()
{
    long long key = generateKey();
    string encryptedKey = encryptKey(key);

    cout << encryptedKey;
    return 0;
}
