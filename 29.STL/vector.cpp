//
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	//vector<int> vec(3);//0 0 0 长度 不给值则默认为0
//	vector<int> vec(3, 4);//vector 相当于一个动态数组 指定初始化向量的大小（容量和使用量）,且指定初始化向量的值
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//
//
//	vec.push_back(1);//增加了之后 扩容 申请一片更大的区间 把原先的拷贝过去 再释放掉以前的
//	vec.push_back(2);
//	vec.push_back(4);
//	vec.push_back(5);
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	vec.pop_back();//容量只会在需要扩容的时候才会变化 删除或者出栈不影响
//	vec.pop_back();
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	//向量容器 考虑到效率问题 由于是动态数组 在数组的头位添加或者删除 需要重新遍历赋值 效率极低 因此没有提供front的操作
//	//vec.push_front();
//	//vec.pop_front();
//
//	//提供了插入操作 上面主要是为了避免多次通过头位操作 导致的效率极低
//	vec.insert(vec.begin(), 10);
//
//	vector<int>::iterator ite = vec.begin();
//	while (ite!= vec.end())
//	{
//		cout << *ite << " ";
//		ite++;
//	}
//	cout << endl;
//
//	ite = vec.begin();
//	//::advance(ite, 4);
//	ite += 4;//vectoe支持 链表不支持 在begin的位置往后数的第4个
//	ite=vec.erase(ite);//ite会失效,一般返回值接一下，返回删除的下一个
//	for (int v : vec)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//	cout << *ite << endl;
//
//	//---------------------------------------------
//	cout << vec.front() << endl;//获取首元素值
//	cout << vec.back() << endl;//获取尾元素值
//
//	//vec.clear();//清空（使用量）
//	if (vec.empty())
//	{
//		cout << "vector 为空" << endl;
//	}
//	else
//	{
//		cout << vec.size() << endl;
//	}
//
//	//----------------------------------------------
//	vec.resize(3);//重新设定使用量 从开头开始算 如果是减少使用量 容量不会改变
//	for (int i=0;i<vec.size();i++)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//
//	vec.resize(6);
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//
//	vec.resize(10, 5);//额外的使用量用5来补
//	for (int i = 0; i < vec.size(); i++)//可以像数组一样去遍历 寻找 使用
//	{
//		cout << vec[i] << " ";
//	}
//	cout << endl;
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//
//
//	vector<int>vec2{ 1,2,3,4,5,6,7,8,9 };
//	vec.swap(vec2);//数量不同也能交换
//
//	for (int i = 0; i < vec.size(); i++)
//	{
//		cout << vec[i] << " ";//可以像数组一样去遍历 寻找 使用
//	}
//	cout << endl;
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//
//
//	for (int i = 0; i < vec2.size(); i++)
//	{
//		cout << vec2[i] << " ";//可以像数组一样去遍历 寻找 使用
//	}
//	cout << endl;
//	cout << "使用量" << vec2.size() << " ,容量 " << vec2.capacity() << endl;
//
//
//	//-----------------------------------------------------------------
//
//	cout << "将所有的0换成7" << endl;
//	
//	for (int i = 0; i < vec2.size(); i++)
//	{
//		if (vec2[i] == 0)//可以像数组一样去遍历 寻找 使用
//		{
//			vec2[i] = 7;
//		}
//	}
//	for (int i = 0; i < vec2.size(); i++)
//	{
//		cout << vec2[i] << " ";//可以像数组一样去遍历 寻找 使用
//	}
//	cout << endl;
//
//	vec.reserve(100);//为向量对象保留最小的存储长度，必要时为其分配空间。
//	cout << "使用量" << vec.size() << " ,容量 " << vec.capacity() << endl;
//
//
//	return 0;
//}