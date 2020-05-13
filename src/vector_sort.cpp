#include <iostream>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <vector>
using namespace std;
using namespace cv;
vector<Point2d> po;
 
//自定义排序函数  
bool sortFun(const cv::Point2d &p1, const cv::Point2d &p2)
{
	return p1.x > p2.x;//升序排列  
}
 
int main()
{
	Point2d p1(2, 4), p2(4, 3), p3(1, 7), p4(0,4);
	po.push_back(p1);
	po.push_back(p2);
	po.push_back(p3);
	po.push_back(p4);
	cout << "排序前： ";
	for (auto elem : po)
		cout << elem << " ";
 
	sort(po.begin(), po.end(), sortFun);
	cout << endl << "排序后： " ;
	for (auto elem : po)
		cout << elem << " ";
	
	cout << endl;
	return 0;
}
