#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

std::string prepare(const std::string& s)
{
    std::string result = s;

	for (int i(0); i < result.size(); i++)    //or isalumn
    {
		if (result[i] == ' ')
		{
			result.erase(i--, 1);
		}
    }

    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) {return std::tolower(c);});

    return result;
}

int main()
{
	int N = 11;

	std::vector<std::string> vec;
	vec.push_back("Aa A");
	vec.push_back("cC C");
	vec.push_back("bbb");
	vec.push_back("cc c");
	vec.push_back("a Aa");
	vec.push_back("eee");
	vec.push_back("eee eee eee");
	vec.push_back("eee ee  eeee");
	vec.push_back("cCC");
	vec.push_back("f f f");
	vec.push_back("AAA  ");

	for (int i(0); i < N; i++)
	{
		std::cout << vec[i] << endl;
		vec[i] = prepare(vec[i]);
	}

	std::cout << endl;

	std::sort(vec.begin(), vec.end(), [&](auto a, auto b)
		{
			return a < b;
		});

	std::vector<string>::iterator it;
	it = std::unique(vec.begin(), vec.end(), [=](auto a, auto b)
		{
			return a == b;
		});

	vec.resize(std::distance(vec.begin(), it));

	std::cout << "N: " << vec.size() << endl;

	for (std::vector<std::string>::size_type i = 0; i != vec.size(); i++)
	{
		cout << vec[i] << endl;
	}

	return 0;
}