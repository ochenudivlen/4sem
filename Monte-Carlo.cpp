#include<iostream>
#include<vector>
#include<chrono>
#include<future>
#include<numeric>
#include<functional>
#include<ctime>
#include<cstdlib>

const int R    = 100;
const int N    = 10;
const int Size = 1000000;

# define M_PI 3.141592653589793238462643383279502884L /* pi */

using namespace std;

int main()
{
	srand(time(NULL));

	std::vector<int> vec1(N * Size);
	for (int& x : vec1) x = rand() % (2 * R) - R;

	std::vector<int> vec2(N * Size);
	for (int& x : vec2) x = rand() % (2 * R) - R;

	std::vector<int> vec3(N * Size);
	for (int& x : vec3) x = rand() % (2 * R) - R;

	std::cout << "ball:" << endl;

	std::chrono::high_resolution_clock::time_point start1 = std::chrono::high_resolution_clock::now();

	std::vector<std::future<int>> f;

	for (int i = 0; i < N; ++i)
	{
		f.push_back(std::async([&vec1, &vec2, &vec3, i]()
			{
				int sum = 0;

				for (int j = i * Size; j < (i + 1) * Size; ++j)
				{
					if (sqrt((vec1[j]) * (vec1[j]) + (vec2[j]) * (vec2[j]) + (vec3[j]) * (vec3[j])) < R * 1.0)
					{
						++sum;
					}
				}

				return sum;
			})
		);
	}

	std::cout << "Etalon: " << 4.0 / 3.0 * M_PI * R * R * R << endl;

	double sum = 0;
	for (auto& result : f) sum = sum + result.get();

	std::cout << "Sum:    " << sum << endl;
	std::cout << "Val:    " << (sum * 8 * R * R * R) / (N * Size * 1.0) << endl;
	std::cout << "Pi:     " << (3 * (sum * 8 * R * R * R) / (N * Size * 1.0)) / (4 * R * R * R * 1.0) << endl;

	std::chrono::duration<double> diff1 = std::chrono::high_resolution_clock::now() - start1;
	std::cout << "N = " << N << ":  " << diff1.count() << "s" << endl << endl;

	std::cout << "circle:" << endl;

	std::chrono::high_resolution_clock::time_point start2 = std::chrono::high_resolution_clock::now();

	std::vector<std::future<int>> l;

	for (int i = 0; i < N; ++i)
	{
		l.push_back(std::async([&vec1, &vec2, &vec3, i]()
			{
				int sum = 0;

				for (int j = i * Size; j < (i + 1) * Size; ++j)
				{
					if (sqrt((vec1[j]) * (vec1[j]) + (vec2[j]) * (vec2[j])) < R * 1.0)
					{
						++sum;
					}
				}

				return sum;
			})
		);
	}

	std::cout << "Etalon: " << M_PI * R * R << endl;

	sum = 0;
	for (auto& result : l) sum = sum + result.get();

	std::cout << "Sum:    " << sum << endl;
	std::cout << "Val:    " << (sum * 4 * R * R) / (N * Size * 1.0) << endl;
	std::cout << "Pi:     " << (sum * 4 * R * R) / (N * Size * 1.0) / (R * R * 1.0) << endl;

	std::chrono::duration<double> diff2 = std::chrono::high_resolution_clock::now() - start2;
	std::cout << "N = " << N << ":  " << diff2.count() << "s";

	return 0;
}