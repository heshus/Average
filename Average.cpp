#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

// Функция для вычисления среднего значения
double calculateAverage(const vector<double>& numbers) 
{
    double sum = 0.0;
    for (double num : numbers)
    {
        sum += num;
    }
    return sum / numbers.size();
}

// Функция для вычисления медианы
double calculateMedian(vector<double>& numbers) 
{
    sort(numbers.begin(), numbers.end());
    int n = numbers.size();
    if (n % 2 == 0) 
    {
        return (numbers[n / 2 - 1] + numbers[n / 2]) / 2.0;
    } else 
    {
        return numbers[n / 2];
    }
}

// Функция для вычисления моды емае

vector<double> calculateMode(const vector<double>& numbers) 
{
    map<double, int> frequency;
    for (double num : numbers) 
    {
        frequency[num]++;
    }

    int maxCount = 0;
    for (const auto& pair : frequency) 
    {
        if (pair.second > maxCount) 
        {
            maxCount = pair.second;
        }
    }

    vector<double> modes;
    for (const auto& pair : frequency) 
    {
        if (pair.second == maxCount) 
        {
            modes.push_back(pair.first);
        }
    }

    return modes;
}

// Функция для вычисления размаха
double calculateRange(const vector<double>& numbers) 
{
    auto minMax = minmax_element(numbers.begin(), numbers.end());
    return *minMax.second - *minMax.first;
}

int main() 
{
    int n;
    cout << "enter lens: ";
    cin >> n;

    vector<double> numbers(n);

    cout << "input " << n << " number:\n";
    for (int i = 0; i < n; ++i) 
    {
        cin >> numbers[i];
    }

    double average = calculateAverage(numbers);
    cout << "Average: " << average << endl;

    double median = calculateMedian(numbers);
    cout << "Median: " << median << endl;

    vector<double> modes = calculateMode(numbers);
    cout << "Mode: ";
    for (double mode : modes) 
    {
        cout << mode << " ";
    }
    cout << endl;

    double range = calculateRange(numbers);
    cout << "Range: " << range << endl;

    return 0;
}
