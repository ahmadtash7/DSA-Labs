#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void moveMin(vector<int> &in, vector<int> &out)
{

    int a = in.size();

    for (int i = 0; i < a - 1; i++)
    {

        if (in[i] > in[i + 1])
        {
            swap(in[i], in[i + 1]);
            i = -1;
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

