class Solution {
public:
    bool isPalindrome(string s) {
        int x = 0, y = s.size()-1;
        while(x<=y){
            while(x<=y && !isalnum(s[x]))x++;
            while(x<=y && !isalnum(s[y]))y--;
            if(x>y)break;
            if(tolower(s[x])!= tolower(s[y]))return false;
            x++; y--;
        } 
        return true;
    }
};
