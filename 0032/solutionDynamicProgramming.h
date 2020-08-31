

class Solution {
public:
    
    int longestValidParentheses(const string& s)
    {
        init(s);
        return getMax(s, 0, s.length());
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
        int& maxValue = m_table[beginIndex][endIndex];
        if (maxValue >= 0)
        {
            return maxValue;
        }
        maxValue = getMaxImpl(s, beginIndex, endIndex);
        return maxValue;
    }

    int getMaxImpl(const string& s, int beginIndex, int endIndex)
    {
        if (endIndex - beginIndex < 2)
        {
            return 0;
        }

        if (checkValid(s, beginIndex, endIndex))
            return endIndex - beginIndex;

        return std::max(
            getMax(s, beginIndex, endIndex -1),
            getMax(s, beginIndex+1, endIndex)
        );
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

