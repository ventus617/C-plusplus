//#include<iostream>
//#include<ctime>
//#include<cmath>
//using namespace std;
//int paritition(int arr[], int l, int r)
//{
//   srand(unsigned(time(nullptr))); 
//   int p = rand() % (r - l + 1) + l;
//   swap(arr[r], arr[p]);
//   arr[0] = arr[r]; //开辟连续空间 用来存储key值
//    while (l < r)
//    {
//        while (l < r && arr[l] <= arr[0])
//        {
//            ++l;
//        }arr[r] = arr[l];
//        while (l < r && arr[r] >= arr[0])
//        {
//            --r;
//        }arr[l] = arr[r];
//    }arr[l] = arr[0];
//    return l;
//}
//void quick_sort(int arr[], int l, int r)
//{
//    if (l < r)
//    {
//        int block = paritition(arr, l, r);
//        quick_sort(arr, l, block - 1);
//        quick_sort(arr, block + 1, r);
//    }
//}
//
//int main()
//{
//    int n=0;
//    while (cin >> n)
//    {
//        int arr[105];
//        for (int i = 1; i < n; i++)
//        {
//            scanf_s("%d", arr + i);
//        }
//        quick_sort(arr, 1, n-1);
//        for (int i =1; i < n; i++)printf("%d ", arr[i]); puts("");
//    }
//
//    return 0;
//}