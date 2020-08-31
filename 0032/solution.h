

class Solution {
public:

    struct Record
    {
        int start = 0;
        int steak = 0;
    };

    int longestValidParentheses(const string& s)
    {
        std::vector<Record> stack;
        int maxSteak = 0;
        int currentSteak = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
            {
                // open new scope
                stack.push_back(Record{i, currentSteak});
                currentSteak = 0;
            } 
            else if (!stack.empty())
            {
                auto r = stack.back();
                stack.pop_back();
                currentSteak = i + 1 - r.start + r.steak;
                maxSteak = std::max(maxSteak, currentSteak);
            }
            else
            {
                // open close imbalance
                currentSteak = 0;
                stack.clear();
            }
        }
        return maxSteak;
    }

    int getCounter()
    {
        return m_counter;
    }

private:
  int m_counter = 0;
};

