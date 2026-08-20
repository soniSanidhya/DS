#include<string.h>
class Solution {
public:
    int nums(char s){
        switch(s){
            case '0':
            return 0;
            case '1':
            return 1;
            case '2':
            return 2;
            case '3':
            return 3;
            case '4':
            return 4;
            case '5':
            return 5;
            case '6':
            return 6;
            case '7':
            return 7;
            case '8':
            return 8;
            case '9':
            return 9;
            case '-':
            return -1;
        }
    }
    int myAtoi(string s) {
        if(s == "") return 0;
        int temp = myAtoi(s.pop_back());
        return temp*10 + nums(s[0]);
    }
};
