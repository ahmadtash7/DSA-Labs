#include <iostream>
using namespace std;
int main()
{
    int num_rolls;
    cout << "Enter the number of rolls you want the dice to take" << endl;

    cin >> num_rolls;
    srand(time(NULL));

    for (int i = 0; i < num_rolls; i++)
    {
        cout << (rand() % 6 + 1) << endl;
    }

    return 0;
}