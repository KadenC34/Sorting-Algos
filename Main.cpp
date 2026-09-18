#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include "Timing.h"

using namespace std;

vector<int> createRandomVector(int size)
{
    vector<int> numbers(size);

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(1, 1000000);

    for (int i = 0; i < size; i++)
    {
        numbers[i] = distribution(generator);
    }

    return numbers;
}

void naiveSort(vector<int>& numbers)
{
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            if (numbers[j] < numbers[i])
            {
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main()
{
    int size = 10000;

    vector<int> numbers = createRandomVector(size);
    vector<int> copy = numbers;

    Timing timer;

    timer.start();
    sort(numbers.begin(), numbers.end());
    timer.stop();

    double stdSortTime = timer.getElapsedTime() * 1000000000.0;

    cout << scientific << setprecision(2);

    cout << "Time for std::sort of " << size << " random ints:" << endl;
    cout << stdSortTime << " ns" << endl;
    cout << endl;

    timer.start();
    naiveSort(copy);
    timer.stop();

    double naiveSortTime = timer.getElapsedTime() * 1000000000.0;

    cout << "Time for naiveSort of " << size << " random ints:" << endl;
    cout << naiveSortTime << " ns" << endl;

    return 0;
}