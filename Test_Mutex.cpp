#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex

std::mutex mtx; // mutex for critical section

void print_block(int n, char c)
{
	// critical section (exclusive access to std::cout signaled by locking mtx):
	//mtx.lock();
	//std::lock_guard<std::mutex> locker(mtx);
	//std::unique_lock<std::mutex> lockerr(mtx);

	for (int i = 0; i < n; ++i) { std::cout << c; }
	std::cout << '\n';
	//mtx.unlock();
}

constexpr int fib(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

template <size_t N>
constexpr std::array<int, N> fib_array() {
	std::array<int, N> arr{};
	arr[0] = 0;
	arr[1] = 1;
	for (size_t i = 2; i < N; ++i) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr;
}

class Console
{
public:
	static void WriteLine(const std::string& s)
	{
		std::cout << s << std::endl;
	}
};

//int main(void)
//{
//	/*std::thread th1(print_block, 50, '*');
//	std::thread th2(print_block, 50, '$');
//
//	th1.join();
//	th2.join();
//	std::cout << "complete" << std::endl;*/
//
//	const clock_t start{ clock() };
//
//	constexpr int n = 25;
//	constexpr int result = fib(n);
//
//	const clock_t end{ clock() };
//
//	std::cout << "result: " << result << std::endl;
//
//	std::cout << "time: " << (end - start) / static_cast<double>(CLOCKS_PER_SEC) << std::endl;
//
//	//Console::WriteLine("Hello World");
//
//	return 0;
//}
