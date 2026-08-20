#include <bits/stdc++.h>
using namespace std;

bool solve( vector<vector<char>> &board , string word , int i , int j , int idx )
{
    if( idx == word.size() ) return true;

    if( i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx] )
        return false;

    char ch = board[i][j];
    board[i][j] = '#';

    bool p = solve( board , word , i+1 , j , idx+1 ) ||
             solve( board , word , i-1 , j , idx+1 ) ||
             solve( board , word , i , j+1 , idx+1 ) ||
             solve( board , word , i , j-1 , idx+1 );

    board[i][j] = ch;

    return p;
}

int main()
{
    int m , n;
    cin >> m >> n;

    vector<vector<char>> board(m , vector<char>(n));

    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    bool ans = false;

    for( int i = 0 ; i < m ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            if( board[i][j] == word[0] )
            {
                if( solve( board , word , i , j , 0 ) )
                {
                    ans = true;
                    break;
                }
            }
        }
        if( ans ) break;
    }

    cout << ( ans ? "true" : "false" );
}