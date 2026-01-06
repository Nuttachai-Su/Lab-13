#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool p[][M]){
    for (int j = 0; j <= M+1; ++j) cout << "-";
    cout << "\n";
    for (int i = 0; i < N; ++i) {
        cout << "|";
        for (int j = 0; j < M; ++j) {
            if (p[i][j] == 0) cout << (" ");
            else if (p[i][j] == 1) cout << ("*"); 
        }
        cout << "|" << "\n";
    }
    for (int j = 0; j <= M+1; ++j) cout << "-";
    cout << "\n";
}

void updateImage(bool p[N][M],int s, int x, int y){
    if (s <= 0) return;
    int r = s - 1;
    int r2 = r * r;
    int i_min = max(0,     x - r);
    int i_max = min(N - 1, x + r);
    int j_min = max(0,     y - r);
    int j_max = min(M - 1, y + r);
    
for (int i = i_min; i <= i_max; ++i) {
        for (int j = j_min; j <= j_max; ++j) {
            int di = i - x;
            int dj = j - y;
            if (di*di + dj*dj <= r2) {
                p[i][j] = true;
            }
        }
    }
}