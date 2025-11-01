#include <iostream>
#include <new>

void destroy(int **mtx, size_t created) {
  for (size_t i = 0; i < created; i++) {
    delete[] mtx[i];
  }
  delete[] mtx;
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

  } catch (const std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}
