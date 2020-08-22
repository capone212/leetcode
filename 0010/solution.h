

class Solution {
public:
    
    bool isMatch(string s, string p) {
        return check(s.begin(), s.end(), p.begin(), p.end());
    }

    int getCounter()
    {
        return m_counter;
    }

private:
    
    template <typename TIter>
    inline bool matchSingle(TIter strBegin, TIter strEnd, char pattern)
    {
        ++m_counter;
        return strBegin != strEnd && (pattern == '.' || *strBegin == pattern);
    }
    
    //using index_t = std::pair<int,int>;

    template <typename TIter>
    bool check(TIter strBegin, TIter strEnd, 
               TIter ptnBegin, TIter ptnEnd)
    {
        if (ptnBegin == ptnEnd)
        {
            return strBegin == strEnd;
        }

        // {
        //     index_t callIndex {std::distance(strBegin, strEnd), std::distance(ptnBegin, ptnEnd)};
        //     if (!m_memoization.insert(callIndex).second)
        //     {
        //         // already checked
        //         return false;
        //     }
        // }

        {
            auto& valset = m_memoization[std::distance(strBegin, strEnd)];
            if (!valset.insert(std::distance(ptnBegin, ptnEnd)).second)
            {
                // already checked
                return false;
            }
        }

        // detect we are in ordinary case or complex
        //TIter matchBegin = strBegin;
        //TIter matchEnd = strBegin;
        bool isWildCard = false;
        char pattern = *ptnBegin;
        ++ptnBegin;
        if (ptnBegin != strEnd && *ptnBegin == '*')
        {
            isWildCard = true;
            ++ptnBegin;
        }

        if (isWildCard)
        {
            while(true)
            {
                if (check(strBegin, strEnd, ptnBegin, ptnEnd))
                    return true;

                if (!matchSingle(strBegin, strEnd, pattern))
                {
                    return false;
                }
                ++strBegin;
            }
        }

        if (!matchSingle(strBegin, strEnd, pattern))
        {
            return false;
        }
        ++strBegin;
        return check(strBegin, strEnd, ptnBegin, ptnEnd);
    }
    

private:
  int m_counter = 0;
  //std::set<index_t> m_memoization;
  std::unordered_map<int, std::unordered_set<int>> m_memoization;
};

