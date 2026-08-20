#include <bits/stdc++.h>
using namespace std;

bool is_ith_bitset(int num, int i)
{
    return ((1 << i) & num) != 0;
}

bool is_odd(int num)
{
    return num & 1 == 1;
}

bool is_in_power(int num)
{
    // int temp = 0;
    // while(num != 0){
    //     temp = temp + (num & 1);
    //     num = num >> 1;
    // }
    // if(temp == 1) return true;
    // return false;
    // 4 = 100 , 3 = 011 | 100 & 011 == 0;
    // 5 = 101 , 4 = 100 | 101 & 100 == 4;
    return num > 0 && (num & (num - 1)) == 0;
}

int no_of_set_bits(int n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int set_rightmost_unset_bit(int n)
{
    return n | (n + 1);
}

void swap_two_nums(int *num1, int *num2)
{

    *num1 = (*num1 ^ *num2);
    *num2 = (*num1 ^ *num2);
    *num1 = (*num1 ^ *num2);
}

int divide(int dividend, int divisor)
{
    if(divisor == 0) return 80085;
    int quotient = 0;
    bool sign = 1;
    if(dividend < 0){
        sign = 1^sign;
        dividend = -dividend;
    }
    if(divisor < 0){
        sign = 1^sign;
        divisor = -divisor;
    }

    while (dividend >= divisor)
    {
        int k = -1;
        while (dividend >= (divisor << (k + 1)))
        {
            k++;
        }
            dividend -= (divisor << k);
            quotient += (1 << k);
    }
    return sign ? quotient : (-quotient); 
}

int main()
{

    // cout<<is_ith_bitset( 5 , 2 );
    // cout<<is_odd(5)<<endl;
    // cout<<is_odd(6);
    // cout<<endl;
    // cout <<"\n"<< is_in_power(1024);
    // cout <<"\n"<< is_in_power(0);
    // cout<<set_rightmost_unset_bit(63);
    cout << divide(-3, 3);
    cout << endl;
    cout << divide(21, -2);
    cout << endl;
    cout << divide(0, 3);
    cout << endl;
    cout << divide(-56464, -3);
    return 0;
}