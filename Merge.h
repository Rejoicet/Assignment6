#include <iostream>
using namespace std;

class Merge {
public:
  Merge();
  ~Merge();

  void mergeSort(double array[], int lo, int hi);
  void merge(double array[], int lo, int hi);

private:
  int m;
};
