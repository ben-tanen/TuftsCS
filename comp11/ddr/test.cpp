#include <iostream>

using namespace std;

void cool(int yay[]);

int main()
{
    int array[4] = {3,2,1,0};
    cool(array);
    cout << array[0] << endl;
    cout << array[1] << endl;
    cout << array[2] << endl;
    cout << array[3] << endl;
}

void cool(int yay[])
{
    yay[3] = 3;
}
