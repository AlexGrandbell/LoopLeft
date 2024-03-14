#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//反转数组中的元素，从 start 到 end（包括 end）
void reverse(vector<char>& arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

//将字符数组循环左移 k 个位置
void rotateLeft(vector<char>& arr, int k) {
    int n = arr.size();
    k = k % n; // 处理 k 大于数组长度的情况

    //三步翻转法：先翻转前 k 个元素，然后翻转剩余元素，最后整体翻转
    reverse(arr, 0, k - 1);
    reverse(arr, k, n - 1);
    reverse(arr, 0, n - 1);
}

int main() {
    int n, k;
    cin >> n; //数组长度
    cin >> k; //循环左移数
    vector<char> arr(n); //字符数组
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    //调用函数进行循环左移
    rotateLeft(arr, k);

    //输出结果
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
