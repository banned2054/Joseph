/*
 *Description
 *Code:Joseph list
 *Author:banned
 *Last Edit time:2020/10/13 14:04
 */


#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct node
{
	int data;
	node* next;
}que;
int n, m;//当前圈n个人，每m个人出一次圈
int x, y;//n和m的上限
node* head, * now_que;//链首和当前链指向的位置

void init_que()//链表初始化
{
	node* list;
	list = new(node);
	list->data = 1;
	list->next = list;
	head = list;
	now_que = head;
	return;
}
void add_que(int x)//添加节点，数据（编号）为x
{
	node* list;
	list = new(node);
	list->data = x;
	list->next = NULL;
	now_que->next = list;
	now_que = list;
	return;
}
void Joseph()//算法主体，约瑟夫算法
{
	node* list, * next;
	while (n > 1)
	{
		list = head;
		for (int i = 2; i < m; i++)
		{
			list = list->next;
		}
		next = list->next;
		list->next = next->next;
		head = next->next;
		free(next);
		n--;
	}
	return;
}
void print1(int q,int w)//输出详细信息
{
	if (w == 1)//特殊情况，未知原因使得w=1时，约瑟夫结果出错
	{
		printf("length of circle:%d,every %d pass a soldier,from No.2 begin.\n", q, w);
		//cout << q << '\t' << w << '\t' << "2" << endl;
		return;
	}

	
	//cout << q << "\t" << w << "\t";
	printf("length of circle:%d,every %d pass a soldier,from No.", q, w);

	if (head->data == 1) cout << "1 begin." << endl;
	else cout << q + 2 - (head->data) << " begin." << endl;
	//debug
	//cout << head->data << endl;//根据head->data求出上述的q+2-(head->data)
}
void print2(int q,int w)//预留精简版的信息，用于后续处理数据
{
	if (w == 1)
	{
		cout << q << '\t' << w << '\t' << "2" << endl;
		return;
	}
	
	cout << q << "\t" << w << "\t";
	if (head->data == 1) cout << "1" << endl;
	else cout << q + 2 - (head->data) << endl;
}
int main()
{
	cin >> x >> y;

	for (int q = 2; q <= x; q++)
	{

		for (int w = 1; w <= y; w++)
		{
			n = q;
			m = w;
			init_que();
			for (int i = 2; i <= n; i++)
			{
				add_que(i);
			}
			now_que->next = head;
			Joseph();
			print1(q, w);
			//print2(q, w);
			free(head);
		}
		cout << endl;
	}
	return 0;
}