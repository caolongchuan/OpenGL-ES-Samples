#include <iostream.h>
using namespace std;
struct MyByteStruct
{
	char c;
	float a;
	int b;
};
/*�����������Ϊ 4+4+1=9*/
/*�˴�ʹ�����ֽڶ��룬ʹ�������ʸ���,����Ϊ4+4+4=12  ���������*/
int main() {
	printf("%d\n",sizeof(float));//4 byte
	printf("%d\n", sizeof(int));//4 byte
	printf("%d\n", sizeof(char));//1 byte
	printf("%d\n", sizeof(long));//4 byte
	printf("%d\n", sizeof(float *));//ָ�붼Ϊ4�ֽ�
	MyByteStruct myTest;
	printf("%d", sizeof(myTest));//12 byte
	cin.get();
}