#include "ScopeThread.hpp"

void DoSomething()
{

}

int main()
{
    ScopedThread t{thread(DoSomething)};

    return 0;
}