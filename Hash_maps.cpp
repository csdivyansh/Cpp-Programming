#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

    map <string, int> m;

    //1
    pair <string, int> p = make_pair("Hello", 1);
    m.insert(p);

    //2
    pair<string, int> pair2("Hi", 2);
    m.insert(pair2);

    //3
    m["Bye"] = 3;
    m["Bye"] = 4;

    cout << m["Bye"] <<endl;
    cout << m.at("Hello") <<endl;

    //cout << m.at("unknown") <<endl;
    cout << m["unknown"] <<endl;
    cout << m.count("bro") <<endl;

    //erase 
    m.erase("Hi");

    cout << m.size() <<endl;

    for(auto i : m) {
        cout << i.first << " " << i.second <<endl;
    }

    map<string, int> :: iterator it = m.begin();

    while(it++ != m.end()) {
        cout << it->first << " " << it->second << endl;
    }




    return 0;
}
