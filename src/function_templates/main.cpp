#include <iostream>
#include <string>
using namespace std;

// declaration of the template variable
// you can also create more generic variables
// e.g. template <typename T, typename U>
template <typename T>
// example using a sorting algorithm
// notice that we don't specify the data type
void inserction_sort(T arr[], int n){
    for (int i = 1; i < n; i++) 
    {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// example using int, char and strings to demonstrate
int main()
{
    int int_arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(int_arr) / sizeof(int_arr[0]);

    char char_arr[] = {'d', 'a', 'c', 'b', 'e'};
    string str_arr[] = {"banana", "apple", "grape", "orange", "kiwi"};

    inserction_sort(int_arr, n);
    cout << "Sorted integer array: ";
    for (int i = 0; i < n; i++)
    {
        cout << int_arr[i] << " ";
    }
    cout << endl;

    inserction_sort(char_arr, 5);
    cout << "Sorted character array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << char_arr[i] << " ";
    }
    cout << endl;

    inserction_sort(str_arr, 5);
    cout << "Sorted string array: ";
    for (int i = 0; i < 5; i++)
    {
        cout << str_arr[i] << " ";
    }
    cout << endl;
    return 0;
}
