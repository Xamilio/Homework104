#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int TEST = 10;   
    const int SIZE = 1000;
    const int MAX = 10000;
    setlocale(LC_ALL, "ru");
    srand(time(0));
    long long bubble = 0;
    long long selection = 0;

    for (int test = 0; test < TEST; ++test) 
    {
        int array[SIZE];
        for (int i = 0; i < SIZE; ++i) 
        {
            array[i] = rand() % MAX + 1; 
        }
        int bubbleArray[SIZE], selectionArray[SIZE];
        for (int i = 0; i < SIZE; ++i)
        {
            bubbleArray[i] = array[i];
            selectionArray[i] = array[i];
        }
        int bubbleSwaps = 0;
        for (int i = 0; i < SIZE - 1; ++i)
        {
            bool sw = false;
            for (int j = 0; j < SIZE - i - 1; ++j) 
            {
                if (bubbleArray[j] > bubbleArray[j + 1])
                {
                    int temp = bubbleArray[j];
                    bubbleArray[j] = bubbleArray[j + 1];
                    bubbleArray[j + 1] = temp;
                    bubbleSwaps++;
                    sw = true;
                }
            }
            if (!sw) break;
        }
        bubble += bubbleSwaps;
        int selectionSwaps = 0;
        for (int i = 0; i < SIZE - 1; ++i)
        {
            int minInd = i;
            for (int j = i + 1; j < SIZE; ++j)
            {
                if (selectionArray[j] < selectionArray[minInd]) 
                {
                    minInd = j;
                }
            }
            if (minInd != i) 
            {
                int temp = selectionArray[i];
                selectionArray[i] = selectionArray[minInd];
                selectionArray[minInd] = temp;
                selectionSwaps++;
            }
        }
        selection += selectionSwaps;
    }

    double avgBSwap = static_cast<double>(bubble) / TEST;
    double avgSSwap = static_cast<double>(selection) / TEST;
    cout << "Середня кількість перестановок:" << endl;
    cout << "Bubble Sort: " << avgBSwap << endl;
    cout << "Selection Sort: " << avgSSwap << endl;

}
