// 指针数组和数组指针的使用
#include <stdio.h>
#include <iostream>

int main()
{
	char *str[] = {"Welcome","to","Fortemedia","Nanjing"};
	char **p = str +1;
	str[0] = (*p++)+2;
	str[1] = *(p+1);
	std::cout << (p[0]) <<"---"<< (p[1])<<"-------"<< (p[2])<< std::endl;
	str[2] = p[1]+3;
	str[3] = p[0] + (str[2] - str[1]);
    std::cout << (p[0]) <<"---"<< (p[1])<<"-------"<< (p[2])<< std::endl;
	printf("%s\n", str[0]);
	printf("%s\n", str[1]);
	printf("%s\n", str[2]);
	printf("%s\n", str[3]);
}
