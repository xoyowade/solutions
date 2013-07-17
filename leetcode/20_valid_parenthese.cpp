enum Type {
    kParenthese,
    kSquare,
    kCurly,
};
typedef struct bracket_s {
    Type type;
    bool open;
} Bracket;
class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Type> opening;
        map<char, Bracket> brackets;
        brackets['('] = {kParenthese, true};
        brackets['['] = {kSquare, true};
        brackets['{'] = {kCurly, true};
        brackets[')'] = {kParenthese, false};
        brackets[']'] = {kSquare, false};
        brackets['}'] = {kCurly, false};
        
        for(int i = 0; i < s.length(); i++) {
            Bracket bracket = brackets[s[i]];
            if (bracket.open) {
                opening.push_back(bracket.type);
            } else {
                if (opening.size() < 1) {
                    return false;
                }
                Type type = opening.back();
                if (type != bracket.type) {
                    return false;
                }
                opening.pop_back();
            }
        }
        return opening.size() == 0;
    }
};
