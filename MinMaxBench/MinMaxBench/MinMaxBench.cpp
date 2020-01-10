#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#include <chrono>
#include <algorithm>
#include <random>

class timer
{
public:
	timer() = default;
	void start(const std::string& text_)
	{
		text = text_;
		begin = std::chrono::high_resolution_clock::now();
	}
	void stop(uint64_t result)
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		std::cout << std::setw(19) << text << ":" << std::setw(5) << ms << "ms" << ", result:" << result << std::endl;
	}
	void stop(uint64_t min, uint64_t max)
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto dur = end - begin;
		auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();
		std::cout << std::setw(19) << text << ":" << std::setw(5) << ms << "ms" << ", result:" << min << "," << max << std::endl;
	}

private:
	std::string text;
	std::chrono::high_resolution_clock::time_point begin;
};

int main(int argc, char *argv[])
{
	const size_t MAX_LOOP = (argc == 2) ? atoi(argv[1]) : 1000;

	using int_type = uint64_t;
	std::vector<int_type> vec(1000000);
	std::iota(vec.begin(), vec.end(), 1);
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(vec.begin(), vec.end(), g);
	timer stopwatch;

	stopwatch.start("manual min");
	int_type min = vec[0];
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		min = vec[0];
		for (auto n : vec)
		{
			if (n < min)
				min = n;
		}
	}
	stopwatch.stop(min);

	stopwatch.start("std min");
	min = vec[0];
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		min = vec[0];
		for (auto n : vec)
			min = std::min(n, min);
	}
	stopwatch.stop(min);

	stopwatch.start("std min_element");
	min = vec[0];
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		min = vec[0];
		min = * std::min_element(vec.cbegin(), vec.cend());
	}
	stopwatch.stop(min);

	std::cout << std::endl;

	stopwatch.start("manual max");
	int_type max = vec[0];
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		max = vec[0];
		for (auto n : vec)
		{
			if (n > max)
				max = n;
		}
	}
	stopwatch.stop(max);

	stopwatch.start("std max");
	max = vec[0];
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		max = vec[0];
		for (auto n : vec)
			max = std::max(n, max);
	}
	stopwatch.stop(max);

	stopwatch.start("std max_element");
	max = vec[0];
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		max = vec[0];
		max = *std::max_element(vec.cbegin(), vec.cend());
	}
	stopwatch.stop(max);

	std::cout << std::endl;

	stopwatch.start("manual min max");
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		min = vec[0];
		max = vec[0];
		for (auto n : vec)
		{
			if (n < min)
				min = n;
			if (n > max)
				max = n;
		}
	}
	stopwatch.stop(min, max);

	stopwatch.start("std min & max");
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		min = vec[0];
		max = vec[0];
		for (auto n : vec)
		{
			min = std::min(n, min);
			max = std::max(n, max);
		}
	}
	stopwatch.stop(min, max);

	stopwatch.start("std minmax_element");
	std::pair<std::vector<int_type>::const_iterator, std::vector<int_type>::const_iterator> minmax;
	for (size_t k = 0; k < MAX_LOOP; ++k)
	{
		minmax = std::minmax_element(vec.cbegin(), vec.cend());
	}
	stopwatch.stop(*minmax.first, *minmax.second);


	return 0;
}

