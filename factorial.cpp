import  <iostream>;

template <unsigned long long N>
struct Factorial {
  enum { kValue = N * Factorial<N - 1>::kValue };
};

template <>
struct Factorial<0> {
  enum { kValue = 1 };
};

//int main() {
//  std::cout << Factorial<5>::kValue << std::endl; // 结果： 120
//  std::cout << Factorial<10>::kValue << std::endl; // 结果： 3628800
//  std::cout << Factorial<15>::kValue << std::endl; // 结果： 1307674368000
//  std::cout << Factorial<16>::kValue << std::endl; // 结果： 20922789888000
//
//  return 0;
//}