#include<unordered_map>
#include<list>
#include<stack>
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int main() {

    
    return 0;
}

//281A - Word Capitalization
// string a, ans = "";
//     cin >> a;

//     ans.push_back(toupper(a[0]));
//     for(int i = 1; i < a.size() ; i++) {
//         ans.push_back(a[i]);
//     }
    
//     cout << ans;

//339A - Helpful Maths
    // vector<int> ans;
    // string a;
    // cin >> a;

    // if (a.size() == 1) {
    //     cout << a << endl;
    // } else {
    //     for(int i = 0; i < a.size(); i++) {
    //         if (a[i] != '+')
    //             ans.push_back(a[i] - '0');
    //     }

    //     sort(ans.begin(), ans.end());

    //     for(int i = 0; i < ans.size(); i++) {
            
    //         if (i == ans.size() - 1) {
    //             cout << ans[i];
    //         } else {
    //             cout << ans[i] << "+";
    //         }
    //     }
    // }    

//112A - Petya and Strings

// string a,b;
//     cin >> a >> b;
//     int cmp = 0;

//     for (int i = 0; i < a.size(); i++)  {
//         if (tolower(a[i]) < tolower(b[i])) {
//             cmp = -1;
//             break;
//         } else if (tolower(a[i]) > tolower(b[i])) {
//             cmp = 1;
//             break;
//         }

//     }

//     cout << cmp;

//     int n, k, x, count;
//     cin >> n >> k;

//     for(int i = 0; i < n; i++) {
//         cin >> x;
//         if (x >= k) {
//             count++;
//         }
//     }

//     cout << count;



//Three Brothers
//  int a, b;
// cin >> a >> b;
// cout << 6 - a - b;

//2010A - Alternating Sum of Numbers

//     int n;
//     cin >> n;

//     for(int i = 0; i < n; i++) {
//         int x;
//         cin >> x;

//         int sum = 0;
//         for (int i = 0; i < x; i++) {
//             int num;
//             cin >> num;

//             if (i % 2 == 0) {
//                 sum += num;
//             } else {
//                 sum -= num;
//             }

//         }

//         cout << sum << endl;
//     }

// 231A - Team

//     int n, p_count, x;
//     cin >> n;

//     for (int i = 0; i < n; i++) {
//         int count = 0;
//         for (int j = 0; j < 3; j++) {
//             cin >> x;
//             if (x == 1) {
//                 count++;
//             }
//         }
//         if (count >= 2) {
//             p_count++;
//         }
//     }
//     cout << p_count << endl;

// 71A - Way Too Long Words

    // int n;
    // cin >> n;
    // string word;
    // for (int i = 0; i < n; i++){
    //     cin >> word;
    //     if(word.size() > 10) {
    //         string ans = "";
    //         ans.push_back(word[0]);
    //         ans.append(to_string(word.size() - 2));
    //         ans.push_back(word[word.size() - 1]);
    //         cout << ans << endl;
    //     } else {
    //         cout << word << endl; 
    //     }
    // }

    //Bits++

    // int n;
    // cin >> n;
    // string s;

    // int x = 0;
    // for(int i = 0; i < n; i++) {
    //     cin >> s;
    //     if (s == "++X" || s == "X++") {
    //         x++;
    //     } else {
    //         x--;
    //     }
    // }

    // cout << x;