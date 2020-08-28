#include <iostream>
#include <string>

using namespace std;

char keys[9] = {'F', 'S', 'w', 'a', 'A', 'v', 'z', 'Y', 'n'};

int findChar(char charLook)
{
    for(int i = 0; i < 9; ++i)
    {
        if(charLook == keys[i])
        {
            return i;
        }
    }
    return 9;
}

long long decryptKey(string encryptedkey)
{
    long long decryptedkey = 0;
    int place, sum = 0;

    for(int i = 0; i < encryptedkey.size(); ++i)
    {
        if(encryptedkey[i] == '-')
        {
            continue;
        }

        place = findChar(encryptedkey[i]);

        decryptedkey *= 10;
        decryptedkey += place + 1;
    }

    return decryptedkey;
}

bool keyGood(long long key)
{
    int nums[12], sum = 0;

    for(int i = 0; i < 12; ++i)
    {
        nums[i] = key % 10;
        key /= 10;
    }

    for(int i = 0; i < 11; ++i)
    {
        sum += nums[i];
    }

    if(sum % nums[11] == 0)
        return true;

    return false;
}
int main()
{
    string key;
    cout << "Enter key: ";
    cin >> key;

    long long temp = decryptKey(key);
    bool keyValid = keyGood(temp);

    (keyValid == true) ? cout << "Key is valid" << endl : cout << "Key is invalid" << endl;

    return 0;
}
