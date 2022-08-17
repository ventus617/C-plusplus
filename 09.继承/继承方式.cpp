//#include<iostream>
//using namespace std;
//
//
//// 继承方式：描述了父类的成员在子类中的使用的范围，继承方式和访问修饰符 
//// 共同决定了成员的访问控制权限
//// private无论在那种继承方式下都是不可访问的
//// 判断访问修饰符是否比继承方式基本低，如果低则升级为继承方式同一级别的方式
//// 如果不低，则保持在父类中的访问修饰等级
//// 
//// public:公共继承 
//// 父类成员属性		子类成员属性
//// public			public
//// private			不可访问
//// protected		protected
//// 
//// 
//// 
//// private:私有继承 
//// 父类成员属性		子类成员属性
//// public			private
//// private			不可访问
//// protected		private
//// 
//// 
//// 
//// protected:保护继承
//// 父类成员属性		子类成员属性
////	public			protected
////	private			不可访问
////	protected		protected
////
//
//
//class Father
//{
//public:
//	int m_pub;
//protected:
//	int m_pro;
//private:
//	int m_pri;
//public:
//	Father():m_pri(10)
//	{
//		m_pub = 10;
//		m_pro = 20;
//		m_pri = 30;
//	}
//	//如何在子类下使用父类的私有属性
//	int Getpri()
//	{
//		return m_pri;
//	}
//};
//
//class Son :private Father
//{
//public:
//
//
//
//	//void showPublic()
//	//{
//	//	cout << m_pub << endl;
//	//	cout << m_pro << endl;//受保护的属性 可以在继承的类中使用 但不能在类外使用
//	//	/*cout << m_pri << endl; 不可访问的属性*/
//	//	//父类的私有成员属性 即使public继承也无法使用 
//	//	//private只能在类内使用 即自己使用 即使继承也不可以使用
//	//	cout << Getpri() << endl;
//	//}
//	
//
//
//
//	//void showprotected()
//	//{
//	//	cout << m_pub << endl;//属性：保护的
//	//	cout << m_pro << endl;//属性：保护的
//	///*	cout << m_pri << endl; 不可访问*/
//	//}
//
//
//
//
//	void showprivate()
//	{
//		cout << m_pub << endl;
//		cout << m_pro << endl;
//		/*cout << m_pri << endl; 不可访问的*/
//	}
//
//};
//
////表示在孙子类中可以使用子类的m_pro属性 
////即子类在继承m_pro属性时将其作为受保护权限
////class Csonson :public Son
////{
////public:
////	void show()
////	{
////		cout << m_pro << endl;
////		cout << m_pub << endl;
////	}
////};
//
//int main03()
//{
//	Son son;
//	
//	son.showprivate();
//	
//
//
//	return 0;
//}