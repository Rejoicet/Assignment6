#include "Insertion.h"
#include "Bubble.h"
#include "Quick.h"
#include "Merge.h"
#include "Time.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <math.h>
using namespace std;

unsigned int option;
int number;
double *insertionArray, *bubbleArray, *quickArray, *mergeArray;
double values;
ifstream sortingFile;
string filename, s;


int main () {
  cout << "Welcome to the sorting algorithms!" << endl;

  number = 0;

  Insertion insertion;
  Bubble bubble;
  Quick quick;
  Merge mergeobj;
  Time time;

  cout << "Choose one of the below options - " << endl;
  cout << "1 - Generate random numbers to sort" << endl;
  cout << "2 - Enter a text file that contains list of values" << endl;
  cin >> option;
  cin.get();

  if (option == 1) {
    cout << "Please enter how many random numbers you want to generate and sort" << endl;
    cin >> number;

    insertionArray = new double [number];
    bubbleArray = new double [number];
    quickArray = new double [number];
    mergeArray = new double [number];

    for (int i = 0; i < number; i++) {
      insertionArray[i] = rand();
      bubbleArray[i] = rand();
      quickArray[i] = rand();
      mergeArray[i] = rand();
    }

    if (number == 0) {
      cout << "There are no values present in the file to sort!" << endl;
    }
    else if (number == 1) {
      cout << "There is only one value. Nothing to sort!" << endl;
    }
    else {
      cout << "Insertion Sort - " << endl << "Start: " << time.timeNow();
      insertion.insertSort(insertionArray, number);
      cout << "End: " << time.timeNow() << endl;
      cout << "Bubble Sort - " << endl << "Start: " << time.timeNow();
      bubble.bubbleSort(bubbleArray, number);
      cout << "End: " << time.timeNow() << endl;
      cout << "Quick Sort - " << endl << "Start: " << time.timeNow();
      quick.quickSort(quickArray, 0, number-1);
      cout << "End: " << time.timeNow() << endl;
      cout << "Merge Sort - " << endl << "Start: " << time.timeNow();
      mergeobj.mergeSort(mergeArray, 0, number-1);
      cout << "End: " << time.timeNow() << endl;
    }
  }
  else if (option == 2) {
    cout << "Please enter the name of the file along with the extension" << endl;
    cin >> filename;

    sortingFile.open (filename);

    getline (sortingFile,s);
    istringstream firstrow (s);
    firstrow >> number;

    insertionArray = new double [number];
    bubbleArray = new double [number];
    quickArray = new double [number];
    mergeArray = new double [number];

    int a = 0;

    while (sortingFile >> values) {
      insertionArray[a] = values;
      bubbleArray[a] = values;
      quickArray[a] = values;
      mergeArray[a] = values;
      ++a;
    }

    if (number == 0) {
      cout << "There are no values present in the file to sort!" << endl;
    }
    else if (number == 1) {
      cout << "There is only one value. Nothing to sort!" << endl;
    }
    else {
      cout << "Insertion Sort - " << endl << "Start: " << time.timeNow();
      insertion.insertSort(insertionArray, number);
      cout << "End: " << time.timeNow() << endl;
      cout << "Bubble Sort - " << endl << "Start: " << time.timeNow();
      bubble.bubbleSort(bubbleArray, number);
      cout << "End: " << time.timeNow() << endl;
      cout << "Quick Sort - " << endl << "Start: " << time.timeNow();
      quick.quickSort(quickArray, 0, number-1);
      cout << "End: " << time.timeNow() << endl;
      cout << "Merge Sort - " << endl << "Start: " << time.timeNow();
      mergeobj.mergeSort(mergeArray, 0, number-1);
      cout << "End: " << time.timeNow() << endl;
    }
  }
}
