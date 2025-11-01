#include <iostream>
#include <new>

void destroy(int **mtx, size_t created) {
  for (size_t i = 0; i < created; i++) {
    delete[] mtx[i];
  }
  delete[] mtx;
}

void constuction(int **mtx, int init, size_t rows, size_t columns) {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < columns; ++j) {
      mtx[i][j] = init;
    }
  }
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
void input(int **mtx, size_t rows, size_t columns) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < columns; j++) {
      std::cin >> mtx[i][j];
    }
  }
}
void output(int **mtx, size_t rows, size_t columns) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < columns; j++) {
      std::cout << ((j == 0) ? "" : "-") << mtx[i][j];
    }
    std::cout << "\n";
  }
}
int *flatten(int **matrix, size_t rows, size_t columns) {
  int *result = new int[rows * columns];
  for (size_t i = 0, cntr = 0; i < rows; i++) {
    for (size_t j = 0; j < columns; j++, cntr++) {
      result[cntr] = matrix[i][j];
    }
  }
  return result;
}
int main() {
  int **matrix = nullptr;
  size_t r = 0, c = 0;
  std::cin >> r >> c;
  try {
    matrix = create(r, c);
    input(matrix, r, c);
    if (!std::cin) {
      return 1;
    }
    output(matrix, r, c);
    int *list = flatten(matrix, r, c);
    // вывод flattend
    for (size_t i = 0; i < c * r; i++) {
      std::cout << list[i] << " ";
    }
    std::cout << "\n";
    destroy(matrix, r * c);
  } catch (const std::bad_alloc &e) {
    std::cout << e.what() << std::endl;
  }
}
