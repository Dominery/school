#include<stdio.h>
 
 void f0(int b)
 {
 	printf("the function %d is called!\n",b);
 }
void f1(int b)
 {
 	printf("the function %d is called!\n",b);
 }
 void f2(int b)
 {
 	printf("the function %d is called!\n",b);
 }
 void f3(int b)
 {
 	printf("the function %d is called!\n",b);
 }
 void f4(int b)
 {
 	printf("the function %d is called!\n",b);
 }
 void f5(int b)
 {
 	printf("the function %d is called!\n",b);
 }
 void f6(int b)
 {
 	printf("the function %d is called!\n",b);
 }
 void f7(int b)
 {
 	printf("the function %d is called!\n",b);
 }
struct bits{
	unsigned char bit0:1,bit1:1,bit2:1,bit3:1,bit4:1,bit5:1,bit6:1,bit7:1;
}bit={0,0,0,1,0,0,0,0};
 int main()
 {
 	
 	void (*p_fun[])(int b)=
 	{
 		f0,f1,f2,f3,f4,f5,f6,f7
	};
	
		if(bit.bit0)
		p_fun[0](bit.bit0);
		if(bit.bit1)
		p_fun[1](bit.bit1);
		if(bit.bit2)
		p_fun[2](bit.bit2);
		if(bit.bit3)
		p_fun[3](bit.bit3);
		if(bit.bit4)
		p_fun[4](bit.bit4);
		if(bit.bit5)
		p_fun[5](bit.bit5);
		if(bit.bit6)
		p_fun[6](bit.bit6);
		if(bit.bit7)
		p_fun[7](bit.bit7);
	
 }
