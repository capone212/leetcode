

class Solution
{
public:

    bool isMatch(const string& s, const string& p)
    {
        // init match table
        // if table[i,j] == true, it means that pattern suffix [j:end] 
        // matches input string suffix [i:end].
        using vectorBool_t = std::vector<bool>;
        std::vector<vectorBool_t> table;
        {
            std::vector<bool> dummy(p.length() + 1, false);
            table.resize(s.length() + 1, dummy);
        }
        table[s.length()][p.length()] = true;
        
        for (int i = s.length(); i >= 0; --i)
        {
            for (int j = p.length()-1; j >= 0; --j)
            {
                // here we check that previus character was handled in path.
                // Logic is simple: if we are at [i,j] and went in reverse direction,
                // then previus step was [i+1, j+1].
                if (!table[i+1][j+1])
                {
                    // skip if privius character in current sequence does not math
                    continue;
                }
                
                // handle star character
                if (p[j] == '*')
                {
                    // Here we open two check path
                    
                    // case 1. character matched at least once:
                    // string = 'xxxc' pattern='xxx*c'
                    table[i+1][j] = true;

                    // case 2. character does not match at all:
                    // string = 'xxxd' pattern='xxx*c'
                    table[i+1][j-1] = true;
                    continue;
                }

                // current character match check
                bool match = p[j] == '.' || s[i] == p[j];
                bool isWildCharacter = (j < p.length()-1) && (p[j+1] == '*');
                
                if (!match)
                {
                    continue;
                }
                
                // continue ordinary check path
                table[i][j] = match;

                // continue wildcard check match
                // this enables multiple character match by wildcard
                // str='cccc' pattern='*c'
                if (isWildCharacter)
                {
                    table[i][j+1] = true;
                }
            }
        }
        return table[1][1];
    }

    int getCounter()
    {
        return m_counter;
    }

private:
    
  
private:
  int m_counter = 0;
};

