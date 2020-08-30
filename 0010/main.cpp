#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#include "solution_norecurse.h"

struct TestCase
{
    TestCase(const std::string& str_, const std::string& ptrn, bool res) :
        str(str_),
        pattern(ptrn),
        result(res)
    {

    }

    std::string str;
    std::string pattern;
    bool result = false;
};

std::ostream& operator<<(std::ostream& stream, const TestCase& t)
{
    stream << "str:" << t.str << " pattern:" << t.pattern << " result:" << t.result;
    return stream;
}

int main()
{
    // TODO: write bottom up approach
    
    std::vector<TestCase> testCases = {
        TestCase{"aa", "a", false},
        TestCase{"aa", "a*", true},
        TestCase{"ab", ".*", true},
        TestCase{"aab", "c*a*b*", true},
        TestCase{"mississippi", "mis*is*p*.", false},
        TestCase{"", ".*", true},
        TestCase{"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaac",
         "a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a*a", false}
    };

    for (const auto& t : testCases)
    {
        Solution s;
        if (s.isMatch(t.str, t.pattern) != t.result)
        {
            std::cout << "Test case failed: " << t << std::endl;
            return 1;
        }
        std::cout << "Counter:" << s.getCounter() << std::endl;
    }
    std::cout << "Ok" << std::endl;
    return 0;
}