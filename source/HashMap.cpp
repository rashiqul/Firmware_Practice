#include <unordered_map>
#include <iostream>
#include <vector>

void countElements(const std::vector<int>& data)
{
    std::unordered_map<int, int> frequencyMap;

    /* Populate the frequency map */
    for(int num: data)
    {
        frequencyMap[num]++;
    }

    /* Print the frequency map */
    for(const auto& pair: frequencyMap)
    {
        std::cout << "Element " << pair.first << " : " << pair.second << " times" << std::endl;
    }
}


void HashMapMain(void)
{
    /* Sample Data */
    std::vector<int> data = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    countElements(data);
}