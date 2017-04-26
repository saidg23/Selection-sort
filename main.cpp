#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

const int arrayLength = 28;

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void getArray(int array[arrayLength])
{
    for(int count = 0; count <= arrayLength-1;)
    {
        int placeholder = getRandomNumber(1, arrayLength);
        bool passFail = true;
        int check = 0;
        for(; check <= arrayLength-1; ++check)
        {
            if(placeholder == array[check])
            {
                passFail = false;
                break;
            }
        }
        if(passFail)
        {
            array[count] = placeholder;
            ++count;
        }

    }
}

int main()
{
    srand(time(0));

    int array[arrayLength] {0};
    getArray(array);

    for(int pos = 0; pos <= arrayLength-2; ++pos)
    {
        int smallestPos = pos;

        for(int comparePos = pos + 1; comparePos <= arrayLength-1; ++comparePos)
            {
                if(array[comparePos] < array[smallestPos])
                    smallestPos = comparePos;
            }

        swap(array[smallestPos], array[pos]);

        for(int pos = 0; pos <= arrayLength-1; ++pos)
        {
            if(array[pos] < 10)
                cout << array[pos] << "  ";
            else
                cout << array[pos] << " ";

            for(int count = array[pos]; count >= 1; --count)
            {
                cout << "#";
            }

        cout << '\n';
        }

        Sleep(150);

        if(pos < arrayLength-2)
            system("cls");
    }

    return 0;
}
