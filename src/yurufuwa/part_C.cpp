#include <iostream>
#include <cmath>

int main() {
  int N = 1350000; // Nの値を設定する
  for (int num = 1; num <= N; num++) {
    int tmp = 0;
    int n = num;
    while (n > 0) {
      int digit = n % 10;
      tmp += pow(digit, 3);
      n /= 10;
    }
    if (tmp == num) {
      std::cout << num << std::endl;
    }
  }
  return 0;
}
