#include <bits/stdc++.h>
using namespace std;

int quicksort(int* c, int start, int end, int n){
    int t, i, j, tmp;
    if(start < end){
        t = c[start];
        for(int s = start+1; s <= end; s++){
            if(c[s] > c[start]){
                t = c[s];
                break;
            }else if(c[s] < c[start]){
                break;
            }
            if(s == end && c[s] == c[start]){
                return 0;
            }
        }
        cout << endl << "軸:" << t << endl;
        i = start;
        j = end;
        cout << "ソート前:  ";
        for(int i = 0; i < n; i++){
            if(i == start){
                cout << "|";
            }
            cout << c[i];
            if(i == end){
                cout << "| ";
            }else{
                cout << " ";
            }
        }
        while(i < j){
            if(c[i] >= t && c[j] < t){
                tmp = c[i];
                c[i] = c[j];
                c[j] = tmp;
                i++;
                j--;
            }else if(c[i] >= t){
                j--;
            }else if(c[j] < t){
                i++;
            }else{
                i++;
                j--;
            }
        }
        cout << endl << "ソート後:  ";
        for(int i = 0; i < n; i++){
            if(i == start){
                cout << "|";
            }
            cout << c[i];
            if(i == end){
                cout << "| ";
            }else{
                cout << " ";
            }
        }
        cout << endl;
        if(i > j){
            quicksort(c, start, j, n);
            quicksort(c, i, end, n);
        }else if(c[i] < t){
            quicksort(c, start, i, n);
            quicksort(c, i+1, end, n);
        }else{
            quicksort(c, start, i-1, n);
            quicksort(c, i, end, n);
        }
    }
    return 0;
}

int main() {
    /*入力:
    n: 配列の長さ
    c[n]: ソート対象の配列

    入力例:
10
3 2 0 5 8 3 4 1 3 2
    */
   int n;
   cin >> n;
   int c[n] = {};
   for(int i = 0; i < n; i++){
       cin >> c[i];
   }
   quicksort(c, 0, n-1, n);
   //出力
   cout << endl << "結果:" << endl;
   for(int i = 0; i < n; i++){
       cout << c[i] << " ";
   }
   cout << endl;
}