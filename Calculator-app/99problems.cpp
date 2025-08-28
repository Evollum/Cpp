#include <iostream> // For input and output

int main() {
	int N;
	// Ask the user to enter a number
	std::cout << "Enter a number: ";
	std::cin >> N;


	int result;
	if (N < 99) {
		// Special case: if N is less than 99, go up to 199
		result = 199;
	} else if (N == 10000) {
		// Special case: if N is 10000, result is 9999
		result = 9999;
	} else {
		// General case: use the logic (N / 100) * 100 + 99
		result = (N / 100) * 100 + 99;
	}

	std::cout << "For N = " << N << ", the result is: " << result << std::endl;

	return 0;
}