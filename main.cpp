#include <iostream>
using s_t = size_t;
void destroy(int** mtx, s_t created)
{
  for (s_t i = 0; i < created; i++) {
    delete[] mtx[i];
  }
  delete[] mtx;
}
int** create(s_t rows, s_t cols)
{
  s_t created = 0;
  int** mtx = new int*[rows];
  try {
    for (; created < rows; ++created) { //(s_t i=0; i<rows; ++i)
      mtx[created] = new int[cols];
    }
  } catch (const std::bad_alloc& e) {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}
void construct(int** mtx, int init, s_t rows, s_t cols)
{
  for (s_t i = 0; i < rows; ++i) {
    for (s_t j = 0; j < cols; ++j) {
      mtx[i][j] = init;
    }
  }
}
void input(int** mtx, s_t rows, s_t cols)
{
  for (s_t i = 0; i < rows; ++i) {
    for (s_t j = 0; j < cols; ++j) {
      std::cin >> mtx[i][j];
    }
  }
}
void output(int** mtx, s_t rows, s_t cols)
{
  for (s_t i = 0; i < rows; ++i) {
    for (s_t j = 0; j < cols; ++j) {
      std::cout << mtx[i][j] << ' ';
    }
    std::cout << "\n";
  }
}
// homework
int** convert(const int* t, size_t n, const size_t* lns, size_t rows)
{
  // creating and memory allocation
  s_t created = 0;
  int** mtx = new int*[rows];
  try {
    for (; created < rows; ++created) { //(s_t i=0; i<rows; ++i)
      mtx[created] = new int[lns[created]];
    }
  } catch (const std::bad_alloc& e) {
    destroy(mtx, created);
    throw;
  }

  // initialization
  s_t countForConvert = 0;
  for (s_t i = 0; i < rows; ++i) {
    for (s_t j = 0; j < lns[i]; ++j) {
      mtx[i][j] = t[countForConvert];
      countForConvert++;
    }
  }
  return mtx;
}

void outputForIndefiniteLength(int** arr, s_t* lns, int rows)
{
  for (s_t i = 0; i < rows; ++i) {
    for (s_t j = 0; j < lns[i]; ++j) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << "\n";
  }
}
// end homework
int main()
{
  // constants
  int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  size_t lns[] = {3, 3, 5, 1};
  size_t n = 12;
  size_t rows = 4;

  // initialization convert array
  int** convertMatrix = convert(t, n, lns, rows);
  outputForIndefiniteLength(convertMatrix, lns, rows);

  // clearing memory
  for (size_t i = 0; i < rows; ++i)
    delete[] convertMatrix[i];
  delete[] convertMatrix;

  ////classroom
  // s_t r = 0, c = 0, init = 0;
  //  std::cin >> r >> c;

  // if (!std::cin) {
  //   destroy(matrix, r);
  //   std::cerr << "bad input\n";
  //   return 2;
  // }

  // try {
  //   matrix = create(5, 5);
  // } catch (const std::bad_alloc& e) {
  //   std::cerr << e.what() << "\n";
  //   return 1;
  // }
  // construct(matrix, init, r, c);
  // std::cout << "created!\n";
  // output(matrix, r, c);
  // destroy(matrix, r);
  ////end classroom
}
