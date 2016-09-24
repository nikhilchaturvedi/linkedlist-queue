/*
A simple singly Linked List based Queue holding a single character in each entry
- Nikhil Chaturvedi
*/

#include <stdlib.h>
#include <stdio.h>
#define QUEUE_SIZE 10

typedef struct queue
{
	char data;
	struct queue *next;
}queue_t;

queue_t *front = NULL;
queue_t *rear = NULL;
int queue_pos = -1;

void init_queue()
{
	front = malloc(sizeof(queue_t));
	rear = malloc(sizeof(queue_t));
}

int insert_queue(char c)
{
	if(queue_pos == QUEUE_SIZE - 1)
	{
		printf("Queue full\n");
		return -1;
	}

	if(queue_pos == -1)
	{
		queue_t *node = malloc(sizeof(queue_t));
		node->data = c;
		front = node;
		rear = node;
		rear->next = NULL;	
		queue_pos = 0;	
	}
	else
	{
		queue_t *node = malloc(sizeof(queue_t));
		node->data = c;
		rear->next = node;
		node->next = NULL;
		rear = node;
		queue_pos++;	
	}

	return 0;
}

int delete_queue()
{
	if(queue_pos == -1)
	{
		return -1;
	}

	queue_t *temp = malloc(sizeof(queue_t));
	temp = front;
	front = front->next;
	queue_pos--;

	free(temp);

	return 0;
}

char get_queue()
{
	return front->data;
}

void print_queue()
{
	queue_t *temp = front;

	while(temp != NULL)
	{
		printf("%c\n", temp->data);
		temp =temp->next;
	}
}

//Driver function to test the Queue
int main()
{
	init_queue();
	insert_queue('a');
	insert_queue('b');
	insert_queue('c');
	print_queue();
	printf("---------\n");
	delete_queue();
	printf("---------\n");
	print_queue();
	printf("---------\n");
	delete_queue();
	printf("---------\n");
	print_queue();
	printf("---------\n");
	delete_queue();
	printf("---------\n");
	print_queue();
	delete_queue();
	printf("---------\n");
	print_queue();
	insert_queue('a');
	insert_queue('b');
	insert_queue('c');
	insert_queue('d');
	insert_queue('e');
	print_queue();
	printf("---------\n");
	printf("%c\n", get_queue());
	delete_queue();
	printf("%c\n", get_queue());
	return 0;
}