// #include <iostream>
// using namespace std;

// int main(){
//     int arr[] = {4, 5, 2, 25};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " " ;
//     }
//     cout << endl;
//     int nge[n];
//     for(int i = 0; i < n; i++){
//          nge[i] = -1;
//         for(int j = i + 1; j < n; j++){
//             if(arr[i] < arr[j]){
//                 nge[i] = arr[j];
//                 break;
//             }
//         }
//     }
//      for(int i = 0; i < n; i++){
//         cout << nge[i] << " " ;
//     }
//     cout << endl;
// }
#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int nge[n];
    for (int i = 0; i < n; i++) {
        nge[i] = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                nge[i] = arr[j];
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;
    return 0;
}