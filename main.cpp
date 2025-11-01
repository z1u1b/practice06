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
  size_t created = 0;
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
int main()
{
  s_t r = 0, c = 0, init = 0;
  int** matrix = nullptr;
  std::cin >> r >> c;

  if (!std::cin) {
    destroy(matrix, r);
    std::cerr << "bad input\n";
    return 2;
  }


  try {
    matrix = create(5, 5);
  } catch (const std::bad_alloc& e) {
    std::cerr << e.what() << "\n";
    return 1;
  }

  construct(matrix, init, r, c);
  std::cout << "created!\n";
  output(matrix, r, c);
  destroy(matrix, r);
}
