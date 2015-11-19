
#include<iostream.h>

class A
{
	int x,y;
public:
	static int count; //对象计数器
public:
	A(){x=y=0;count++;}
	A(int m,int n){x=m;y=n;count++;}
	A(A& ra){x=ra.x;y=ra.y;count++;}//可能会涉及深度拷贝和浅度拷贝
	~A(){ count--;}
	void SetXY(int m,int n){x=m;y=n;}
	void Print(){cout<<"x="<<x<<",y="<<y<<endl;}
	void Copy(A* pa){x=pa->x;y=pa->y;}
};
int A::count=0;

void fun(A a,A* pa){a.SetXY(3,5);pa->SetXY(10,20);cout<<A::count<<endl;}
void main()
{
	A a1,a2(1,2);
	A a3(a2);
	cout<<A::count<<endl;

	a1.Copy(&a3);
	a1.Print();a2.Print();a3.Print();
	cout<<A::count<<endl;

	fun(a1,&a3);
	a1.Print();a2.Print();a3.Print();
}
