#include <iostream>
using s_t = size_t;
void destroy(int** mtx, s_t created)
{
  for (s_t i = 0; i < created; i++) {
    delete [] mtx[i];
  }
  delete[] mtx;
}
int** create(s_t rows, s_t cols)
{
  size_t created = 0;
  int** mtx = new int*[rows];
  // for (s_t i=0;i<rows;++i) {
  //     for (s_t j=0;j<cols;++j) {
  //         std::cin>>mtx[i][j];
  //     }
  // }
  try {
    for (; created < rows; ++created) { //(s_t i=0; i<rows; ++i)
      mtx[created] = new int[cols];
    }
  } catch (const std::bad_alloc& e) {
    destroy(mtx,created);
    throw;

  }
  return mtx;
}
int main()
{
  // int* r = new int[5];

  int** matrix = nullptr;
  try {
    matrix=create(5,5);
  } catch (const std::bad_alloc &e) {
    std::cerr<<e.what()<<"\n";
  }
  destroy(matrix,5);
}
