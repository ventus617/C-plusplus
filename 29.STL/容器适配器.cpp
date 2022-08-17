//#include<stack>
//#include<iostream>
//#include<queue>
//using namespace std;
//
//int main()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//	st.push(4);//入栈
//	cout << "size=" << st.size();//栈元素数量
//	cout << endl;
//	while (!st.empty())//st.size() != 0)//判断是否为空
//	{
//		cout << st.top() << " ";//查看栈顶元素
//		st.pop();//出栈
//	}
//	
//	cout << endl;
//	cout << "size=" << st.size()<<endl;
//
//	//----------------------------------------
//	queue<int> que;
//	que.push(1);
//	que.push(2);
//	que.push(3);
//	que.push(4); //尾添加 入队
//
//	cout<<que.front()<<endl;//输出队头
//	cout << que.back() << endl;//输出队尾
//
//	cout << que.size() << endl;//输出队中元素个数
//
//
//	while (!que.empty())//判断是否为空
//	{
//		cout << que.front() << " ";//查看队头元素
//		que.pop();//出队
//	}
//	cout << endl;
//
//	return 0;
//}