//First homework

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

struct Statistics
{
    int count;
    std::string word;
};

std::string prepare(const std::string& s)
{
    std::string result = s;

    while (!isalpha(result.back()))     //or isalumn
    {
        result.pop_back();
    }

    std::transform(result.begin(), result.end(), result.begin(),
        [](unsigned char c) {return std::tolower(c);  });

    return result;
}

bool comp(const Statistics s1, const Statistics s2)
{
    return s1.count > s2.count;
}

int main()
{
    std::ifstream file ("proba.txt");
    std::map <std::string, int> mp;
    std::map <std::string, int> ::iterator it;

    if (file.is_open())
    {
        std::string word;
        while (!file.eof())
        {
            file >> word;
            word = prepare(word);

            it = mp.find(word);
            if (it == mp.end())
            {
                mp.insert(make_pair(word, 1));
            }
            else
            {
                mp[word]++;
            }

        }
        file.close();
    }
    else
    {
        std::cout << "File not found" << "\n";
    }

    struct Statistics st;
    std::vector<Statistics> vec;

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        st.word  = it->first;
        st.count = it->second;
        vec.push_back(st);
    }

    std::sort(vec.begin(), vec.end(), comp);

    int N = 0;
    std::cin >> N;

    for (int i = 0; i < N; ++i)
    {
        std::cout << vec[i].word << " " << vec[i].count << "\n";
    }

    return 0;
}