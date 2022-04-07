#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

std::string prepare(const std::string& s)
{
    std::string result = s;

	auto newEnd = std::remove_if(result.begin(), result.end(), 
		[](char c) {return c == ' ';});

	result.erase(newEnd, result.end());

    std::transform(result.begin(), result.end(), result.begin(),
        [](char c) {return std::tolower(c);});

    return result;
}

int main()
{
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

	std::transform(vec.begin(), vec.end(), vec.begin(),
		[](const string& s) {return prepare(s); });

	std::sort(vec.begin(), vec.end());

	auto it = std::unique(vec.begin(), vec.end());

	vec.resize(std::distance(vec.begin(), it));

	std::cout << "N: " << vec.size() << endl;

	for (const auto& s : vec)
	{
		cout << s << endl;
	}

	return 0;
}