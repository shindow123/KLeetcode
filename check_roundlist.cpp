/*
 * 判断一个链表是否有循环。
 */
#include <iostream>
#include <string>
#include <stdio.h>

typedef struct Node
{
	int value;
	struct Node* next;
}Node;

bool checkRound(Node* p)
{
	if (p == NULL || p->next == NULL)
	{
		return false;
	}

	Node* n1 = p;
	Node* n2 = p;

	while (n1 != NULL && n2 != NULL && n2->next != NULL)
	{
		n1 = n1->next;
		n2 = n2->next;
		n2 = n2->next;
		
		std::cout <<"111"<<std::endl;
		if (n1 == n2)
		{
			return true;
		}
	}
	
	
	return false;
}

int main()
{
	Node* head = new Node();
	head->next = new Node();
	head->next->next = new Node();
	head->next->next->next = NULL;
	//for (int i=0; i < 2; i++)
	//{
	//	Node* c = new Node();	
	//	c->next = NULL;
	//	p->next = c;
	//	p = p->next;
	//}

	bool ret = checkRound(head);
	std::cout << ret << std::endl;

	head->next->next = head->next;

	ret = checkRound(head);
	std::cout << ret << std::endl;

	return 0;
}
