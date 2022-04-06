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
        [](unsigned char c) {return std::tolower(c);  });

    return result;
}

int main()
{
	int N = 11;

	std::vector<std::string> vec;
	std::vector<std::string> :: iterator it;
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
		vec[i] = prepare(vec[i]);
		std::cout << vec[i] << endl;
	}

	std::cout << endl;

	int count;
	int flag = 0;
	std::vector<std::string> equivalent;

	for (int i = 0; i < N - 1; i++)
	{
		count = 1;

		for (int j = i + 1; j < N; j++)
		{
			if (vec[i] == vec[j])
			{
				it = find(equivalent.begin(), equivalent.end(), vec[i]);

				if (it == equivalent.end())
				{
					flag++;
					count++;
					equivalent.push_back(vec[i]);
				}
				else
				{
					if (count != 1)
					{
						count++;
					}

					continue;
				}
			}
		}

		if (count != 1)
		{
			std::cout << count << " " << vec[i] << endl;
		}
	}

	if (flag == 0)
	{
		std::cout << "Equivalent strings not found" << endl;
	}

	return 0;
}