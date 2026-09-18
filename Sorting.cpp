#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iomanip>

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

    auto start = chrono::high_resolution_clock::now();

    sort(numbers.begin(), numbers.end());

    auto end = chrono::high_resolution_clock::now();

    auto stdSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << scientific << setprecision(2);

    cout << "Time for std::sort of " << size << " random ints:" << endl;
    cout << (double)stdSortTime << " ns" << endl;
    cout << endl;

    start = chrono::high_resolution_clock::now();

    naiveSort(copy);

    end = chrono::high_resolution_clock::now();

    auto naiveSortTime = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    cout << "Time for naiveSort of " << size << " random ints:" << endl;
    cout << (double)naiveSortTime << " ns" << endl;

    return 0;
}