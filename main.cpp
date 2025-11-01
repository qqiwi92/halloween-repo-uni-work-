#include <iostream>
#include <new>

void destroy(int **mtx, size_t created) {
  for (size_t i = 0; i < created; i++) {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** constuction( int ** mtx, int init, size_t rows, size_t columns) {
    for (size_t i =0;i < rows;++i){
        for (size_t j =0 ; j < columns; ++j) {
            mtx[i][j] = init;
        }
    }
    return mtx; 
}

int **create(size_t rows, size_t columns) {
  int **mtx = new int *[rows];
  size_t progress = 0;
  try {
    for (; progress < rows; progress++) {
      mtx[progress] = new int[columns];
    }
  } catch (const std::bad_alloc &e) {
    destroy(mtx, progress);
    throw;
  }
  return mtx;
}
int main() {
  int **matrix = nullptr;
  try {
    matrix = create(5, 6);
    matrix = constuction(matrix,1,5, 6);
  } catch (const std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}


