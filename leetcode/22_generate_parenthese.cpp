class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        set<string> result;
        if (n == 0) {
            return vector<string>(result.begin(), result.end());
        } else if (n == 1) {
            result.insert("()");
            return vector<string>(result.begin(), result.end());
        }
        
        vector<string> subresult = generateParenthesis(n - 1);
        for (int i = 0; i < subresult.size(); i++) {
            string &str = subresult[i];
            result.insert("()" + str);
            for (int i = 1; i < str.length(); i++) {
                if (str[i] == ')' && str[i-1] != ')') {
                    string comb("(");
                    comb.append(str.substr(0, i+1));
                    comb.append(")");
                    comb.append(str.substr(i+1));
                    result.insert(comb);
                }
            }
        }
        
        
        return vector<string>(result.begin(), result.end());
    }
};
