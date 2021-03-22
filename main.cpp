#include <graphics.h>
#include <conio.h>
#include <time.h>
#include "LinkList.h"
#include "ball.h"

#define WINDOWWITH 600
#define WINDOWHEIGHT 600

COLORREF ballColorTable[] = {
BLUE, GREEN, RED, YELLOW, MAGENTA, BROWN
};

//��ͼ����ʾ��
void drawExample(void)
{
	// ���û�ͼɫΪ��ɫ
	setcolor(RED);
	setfillcolor(RED);

	// ������
	rectangle(100, 100, 300, 300);
	solidcircle(200, 200, 100);

}

//������ײ��
void drawColBall(ball* b, int x, int y)
{
	b->x = x;
	b->y = y;

	setcolor(ballColorTable[b->c]);
	setfillcolor(ballColorTable[b->c]);
	solidcircle(b->x, b->y, BALLRADIUS);
}

//�������������벹ȫ�ú���
void drawBallList(Node* head)
{
	Node* cur = head->next;
	while(cur)
	{
		drawColBall(&(cur->data), (cur->data).x, (cur->data).y);
		cur = cur->next;
	}
}

//��ʼ���������������������������һЩ���벹ȫ�ú���
void initBallList(Node* head)
{
	for (int i = 0; i < 10; ++i)
	{
		struct ball b1;
		b1.x = 10 + 20 * i;
		b1.y = 200;
		b1.c = i % 6;
		ListInsert(head, i, b1);
	}
}

int main()
{
	// ��ʼ����ͼ����
	initgraph(WINDOWWITH, WINDOWHEIGHT);
	setbkcolor(BLACK);
	cleardevice();

	//����һ���յ�������
	Node* head = NULL;
	head = CreateEmptyList();
	
	//��ʼ����������
	initBallList(head);

	//�ڴ����л���������
	drawBallList(head);
	//��ͼʾ����������ȫdrawBallList������������ɾ��
	/*drawExample();*/


	//����ײ��
	ball cball;
	cball.c = rand() % 6;
	drawColBall(&cball, WINDOWWITH / 2, WINDOWHEIGHT);

	//�ȴ�������˳�
	_getch();
	//������������ͻ�ͼ����
	DestroyList(head);
	closegraph();
	
	return 0;
}
	
