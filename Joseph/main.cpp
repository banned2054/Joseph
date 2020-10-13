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
int n, m;//��ǰȦn���ˣ�ÿm���˳�һ��Ȧ
int x, y;//n��m������
node* head, * now_que;//���׺͵�ǰ��ָ���λ��

void init_que()//�����ʼ��
{
	node* list;
	list = new(node);
	list->data = 1;
	list->next = list;
	head = list;
	now_que = head;
	return;
}
void add_que(int x)//��ӽڵ㣬���ݣ���ţ�Ϊx
{
	node* list;
	list = new(node);
	list->data = x;
	list->next = NULL;
	now_que->next = list;
	now_que = list;
	return;
}
void Joseph()//�㷨���壬Լɪ���㷨
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
void print1(int q,int w)//�����ϸ��Ϣ
{
	if (w == 1)//���������δ֪ԭ��ʹ��w=1ʱ��Լɪ��������
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
	//cout << head->data << endl;//����head->data���������q+2-(head->data)
}
void print2(int q,int w)//Ԥ����������Ϣ�����ں�����������
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