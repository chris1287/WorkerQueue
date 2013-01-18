#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <queue>

#include "factorial.h"

int main()
{
    std::queue< std::future< std::pair<unsigned int, unsigned int> > >works;
    for(auto i = 0; i < 10; i++)
    {
        auto promise = std::async(std::launch::async, [=](){
            return std::pair<unsigned int, unsigned int>(i, factorial( i ));
        });
        works.push( std::move(promise) );
    }

    while(!works.empty())
    {
        auto res = works.front().get();
        std::cout << res.first << "! = " << res.second << std::endl;
        works.pop();
    }

    return 0;
}
