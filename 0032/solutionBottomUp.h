

class Solution {
public:
    
    int longestValidParentheses(const string& s)
    {
        init(s);
        int maxSequence = 0;
        for (int i = s.length(); i >0; --i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                maxSequence = std::max(maxSequence, getMax(s, j, i));
            }
        }
        return maxSequence;
    }

    int getCounter()
    {
        return m_counter;
    }

    void init(const string& s)
    {
        m_counter = 0;
        buffer_t dummy(s.length() + 1, -1);
        m_table.resize(s.length() + 1, dummy);
    }

private:
    int getMax(const string& s, int beginIndex, int endIndex)
    { 
        if (endIndex < 0 || beginIndex < 0)
        {
            return 0;
        }

        int& maxValue = m_table.at(beginIndex).at(endIndex);
        if (maxValue >= 0)
        {
            return maxValue;
        }
        maxValue = getMaxImpl(s, beginIndex, endIndex);
        return maxValue;
    }

    int getMaxImpl(const string& s, int beginIndex, int endIndex)
    {
        if (checkValid(s, beginIndex, endIndex))
            return endIndex - beginIndex;
        return 0;
    }

    bool checkValid(const string& s, int beginIndex, int endIndex)
    {
        ++m_counter;
        int scopeCounter = 0;
        for (int i = beginIndex; i < endIndex; ++i)
        {
            if (s[i] == '(')
            {
                // open new scope
                ++scopeCounter;
            } 
            else if (scopeCounter >0)
            {
                // close scope
                --scopeCounter;
            }
            else
            {
                // open close imbalance
                return false;
            }
        }
        return scopeCounter == 0;
    }
    
private:
  int m_counter = 0;
  using buffer_t = std::vector<int>;
  std::vector<buffer_t> m_table;
};

