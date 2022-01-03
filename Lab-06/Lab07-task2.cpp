#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveMin(vector<int> &in, vector<int> &out)
{

    int a = in.size();

    for (int i = 0; i < a - 1; i++)
    {

        for (int j = 0; j < a - i - 1; j++)
        {

            if (in[j] > in[j + 1])
            {
                swap(in[j], in[j + 1]);
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        out.push_back(in[i]);
        //cout << in.at(i) << endl;
    }
}

void testMoveMin(vector<int> &in, int iter)
{
    vector<int> sort_vector;
    srand(time(NULL));
    for (int i = 0; i < iter; i++)
    {
        sort_vector.push_back((rand() % 100 + 1));
    }
    for (int i = 0; i < sort_vector.size(); i++)
    {
        in.push_back(sort_vector[i]);
    }
}
int main()
{
    vector<int> primary_vector;
    vector<int> test_vector, t1, t2;
    testMoveMin(primary_vector, 20);
    for (int i = 0; i < primary_vector.size(); i++)
    {
        test_vector.push_back(primary_vector[i]);
    }

    sort(primary_vector.begin(), primary_vector.end());
    moveMin(test_vector, t1);
    primary_vector.push_back(42);
    t1.push_back(42);

    sort(primary_vector.begin(), primary_vector.end());
    moveMin(t1, t2);
    cout << "USING 'SORT():' " << endl;
    for (int i = 0; i < primary_vector.size(); i++)
    {
        cout << primary_vector.at(i) << " ";
    }

    cout << endl
         << endl;
    cout << "USING 'MOVEMIN():' " << endl;
    for (int i = 0; i < t2.size(); i++)
    {
        cout << t2.at(i) << " ";
    }
}