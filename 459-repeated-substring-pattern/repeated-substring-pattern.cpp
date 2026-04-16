class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string doubled = s + s;
        string temp = doubled.substr(1, doubled.size() - 2);

        return temp.find(s) != string::npos;
    }
};