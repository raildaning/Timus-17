#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>


using namespace std;

vector <string> words, wordsD;
map <char, char> mp;

void initMap () {
    mp [ 'i' ] = '1';
    mp [ 'j' ] = '1';
    mp [ 'a' ] = '2';
    mp [ 'b' ] = '2';
    mp [ 'c' ] = '2';
    mp [ 'd' ] = '3';
    mp [ 'e' ] = '3';
    mp [ 'f' ] = '3';
    mp [ 'g' ] = '4';
    mp [ 'h' ] = '4';
    mp [ 'k' ] = '5';
    mp [ 'l' ] = '5';
    mp [ 'm' ] = '6';
    mp [ 'n' ] = '6';
    mp [ 'p' ] = '7';
    mp [ 'r' ] = '7';
    mp [ 's' ] = '7';
    mp [ 't' ] = '8';
    mp [ 'u' ] = '8';
    mp [ 'v' ] = '8';
    mp [ 'w' ] = '9';
    mp [ 'x' ] = '9';
    mp [ 'y' ] = '9';
    mp [ 'o' ] = '0';
    mp [ 'q' ] = '0';
    mp [ 'z' ] = '0';
}

void transform ( string &s ){
    int i, l = s.size();
    for ( i = 0; i < l; ++ i )
        s [ i ] = mp [ s [ i ] ];
}

unsigned best [ 128 ];
string bestString [128];

int main(){

    int n, i, j;
    string number, wd;
    char buf [ 200 ];
    initMap();
    for ( scanf ( "%s", buf), number = string (buf); number != "-1"; scanf ( "%s", buf), number = string (buf) ) {
        words.clear();
        wordsD.clear();
        scanf ( "%d", &n);
        for ( i = 0; i < n; ++ i ){
            scanf ( "%s", buf);
            wd = string (buf);
            words.push_back(wd);
            transform (wd);
            wordsD.push_back(wd);
        }
        memset ( best, -1, sizeof ( best ) );
        best[number.size()]=0;
        for ( i = number.size()-1; i >= 0; -- i )
            for ( j = 0; j < n; ++ j )
                if ( wordsD [ j ] == number.substr ( i, wordsD [ j ].size() ) ) {
                    if ( best [ i + wordsD[j].size()]!= - 1 && 1 + best [ i + wordsD[j].size()] < best [ i ] ) {
                        best [ i ] = 1 + best [ i + wordsD[j].size()];
                        bestString [ i ] = words[j];
                    }
                }
        if ( best [ 0 ] == -1 ) {
            printf ("No solution.\n");
        }
        else{
            for ( i = 0; i < number.size(); i += bestString[i].size() )
                cout << bestString [ i ] << " ";
            cout << endl;
        }
    }
    return 0;
}
