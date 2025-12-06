//Spiral Printing -LC54
#include<iostream>
using namespace std;

int main(){
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;
    int arr[n][m];

    cout << "Enter elements:" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int minr = 0, minc = 0;
    int maxr = n - 1, maxc = m - 1;

    cout << "Spiral Order: ";
    while(minr <= maxr && minc <= maxc){
        // Move right
        for(int i = minc; i <= maxc; i++){
            cout << arr[minr][i] << " ";
        }minr++;
        if(minc>maxc || minr>maxr) break;
        // Move down
        for(int i = minr; i <= maxr; i++){
            cout << arr[i][maxc] << " ";
        }maxc--;
        if(minc>maxc || minr>maxr) break;
        // Move left
        for(int i = maxc; i >= minc; i--){
            cout << arr[maxr][i] << " ";
        }maxr--;
        if(minc>maxc || minr>maxr) break;
        // Move up
        for(int i = maxr; i >= minr; i--){
            cout << arr[i][minc] << " ";
        }minc++;
    }

    return 0;
}