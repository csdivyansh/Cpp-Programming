#include <iostream>
using namespace std;

int sqrtx(int n){
    int s = 1;
    int e = n;
    
    int ans = 0;
    while (s <= e){
        int mid = s + (e-s)/2;
        int sq = mid * mid;
        if (sq == n){
            return mid;
        } else if (sq < n){
            ans = mid;
            s = mid + 1;
        }else {
            e = mid -1;
        }
    }
    return ans;
}

double morePrecision(int n, int precision, int tempsol){
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++){
        factor /= 10;
        for(double j = ans; j*j < n; j += factor){
        	cout << j <<endl;
        	cout << ans << endl;
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    int tempsol = sqrtx(n);
    cout << morePrecision(n, 3, tempsol);
}