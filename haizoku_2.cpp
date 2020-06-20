#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
    入力
    n:学生の人数
    m:研究室の数
    snamelist[n]:学生の名前リスト
    lnamelist[m]:研究室の名前リスト
    W[n][m]:志望順位
        n:n番目の学生, m:m番目の志望研究室
    G[m][n]:成績順位
        m:m番目の研究室, n:成績n位の学生
    maxnum[m]:m番目の研究室の定員
    */
/*
入力例1:
5 3
きじ さば みけ さび とら
アメショ ロシアン ベンガル
0 1 2
2 0 1
0 2 1
0 1 2
2 1 0
0 1 2 3 4
3 2 4 1 0
4 1 2 3 0
1 2 3
*/
/*
入力例2:
8 4
ミッキー ミニー チップ デール ドナルド デイジー グーフィー スティッチ
A B C D
0 1 2 3
1 2 3 0
1 3 2 0
1 0 2 3
2 3 1 0
0 1 3 2
2 3 1 0
0 3 1 2
0 1 2 3 4 5 6 7
2 6 7 4 5 0 1 3
4 2 1 6 7 3 5 0
3 2 0 5 7 6 1 4
3 2 2 1
*/
    int n, m;
    cin >> n >> m;
    string snamelist[n] = {};
    for(int i = 0; i < n; i++){
        cin >> snamelist[i];
    }
    string lnamelist[m] = {};
    for(int j = 0; j < m; j++){
        cin >> lnamelist[j];
    }
    int W[n][m] = {};
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
        cin >> W[i][j];
        }
    }
    int G[m][n] = {};
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
        cin >> G[j][i];
        }
    }
    int maxnum[m] = {};
    for(int j = 0; j < m; j++){
        cin >> maxnum[j];
    }
    //-1:未配属
    //0〜m-1:仮配属
    int haizoku[n] = {};
    for(int i = 0; i < n; i++){
        haizoku[i] = -1;
    }
    //次に希望する順位のインデックス
    int next[n] = {};
    //志望人数
    int ninzu[m] = {};
    //全員が配属済みか
    //1以上:まだ
    //0:終了
    int tf = 1;
    //stepカウンt
    int step = 0;
    while (tf){
        //途中結果
        cout << endl << "step:" << step << endl;
        for(int i = 0; i < n; i++){
            if(haizoku[i] == -1){
                cout << snamelist[i] << " は 未所属" <<endl;
            }else{
                cout << snamelist[i] << " は " << lnamelist[haizoku[i]] << "研に仮所属" <<endl;
            }
        }  
        //仮配属処理
        for(int i = 0; i < n; i++){
            if(haizoku[i] == -1){
                haizoku[i] = W[i][next[i]];
                ninzu[W[i][next[i]]]++;
            }
        }
        //落選処理
        for(int j = 0; j < m; j++){
            //仮配属人数が定員を超えているか？
            if(ninzu[j] > maxnum[j]){
                //落選判定用の変数
                int tmp = 0;
                //成績順位が上の人から見ていく
                for(int i = 0; i < n; i++){
                    //その人が研究室を希望しているか？
                    if(haizoku[G[j][i]] == j){
                        tmp++;
                        //定員を超えたら残りの人は未配属にして, 次の志望研究室へ
                        if(tmp > maxnum[j]){
                            haizoku[G[j][i]] = -1;
                            ninzu[j]--;
                            next[G[j][i]]++;
                        }
                    }
                }
            }
        }
        //全員が配属済みかチェック
        tf = 0;
        for (int i = 0; i < n; i++){
            if(haizoku[i] == -1) tf++;
        }
        step++;
    }
    cout << endl << "結果:" << endl;
    for(int i = 0; i < n; i++){
        cout << snamelist[i] << " は " << lnamelist[haizoku[i]] << "研" <<endl;
    }    
}