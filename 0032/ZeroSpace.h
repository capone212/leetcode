

class Solution {
public:
    int longestValidParentheses(const string& s)
    {
        return std::max(traverseLeft(s), traverseRight(s));
    }

    int traverseLeft(const string& s)
    {
        int maxSteak = 0;
        int left = 0;
        int right = 0;
        int steakStarted = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '(')
                ++left;
            else 
                ++right;
            
            if (left == right)
            {
                maxSteak = std::max(maxSteak, i + 1 - steakStarted);
            } 
            else if (right > left)
            {
                steakStarted = i + 1;
                left = 0;
                right = 0;
            }
            
        }
        return maxSteak;
    }

    int traverseRight(const string& s)
    {
        int maxSteak = 0;
        int left = 0;
        int right = 0;
        int steakStarted = s.length();
        for (int i = s.length() - 1; i >= 0; --i)
        {
            if (s[i] == '(')
                ++left;
            else 
                ++right;
            
            if (left == right)
            {
                maxSteak = std::max(maxSteak, steakStarted - i);
            } 
            else if (right < left)
            {
                steakStarted = i;
                left = 0;
                right = 0;
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

