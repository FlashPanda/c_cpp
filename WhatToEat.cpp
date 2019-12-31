#include <iostream>
#include <vector>
#include <string>
#include <time.h>

class Menu
{
public:
    Menu () {
        Initialize();
    }

    void Initialize()
    {
        m_FoodNames.push_back(std::string("大食堂"));
        m_FoodNames.push_back(std::string("快餐"));
        m_FoodNames.push_back(std::string("牛肉泡馍"));
        m_FoodNames.push_back(std::string("天天快餐"));
    }

    std::string WhatToEatToday()
    {
        srand(time(0));
        
        int32_t index = rand() % m_FoodNames.size();
        return m_FoodNames[index];
    }

private:
    std::vector<std::string> m_FoodNames;
};

int main()
{
    Menu menu;
    
    std::cout << "今天吃什么？" << std::endl;
    std::cout << menu.WhatToEatToday() << std::endl;
}