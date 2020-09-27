#include <stdio.h>
#define MAX_SIZE	10000
int stack[MAX_SIZE];
top = -1;

void push(int item)
{
	if (top >= MAX_SIZE - 1)
	{
		return -1;
	}
	stack[++top] = item;
}

int pop()
{
	if (top == -1)
	{
		return -1;
	}
	return stack[top--];
}

int empty()
{
	if (top == -1)
		return 1;
	return 0;
}

int istop()
{
	if (top == -1)
	{
		return -1;
	}
	return stack[top];
}

int main(void)
{
	int n, i, item;
	char cmd[10];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", cmd);
		if (strcmp(cmd, "push") == 0)
		{
			scanf("%d", &item);
			push(item);
		}
		else if(strcmp(cmd, "pop") == 0)
		{
			item = pop();
			printf("%d\n", item);
		}
		else if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n", top + 1);
		}
		else if (strcmp(cmd, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if (strcmp(cmd, "top") == 0)
		{
			printf("%d\n", istop());
		}
	}
	return 0;
}