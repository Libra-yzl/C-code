#pragma once

int arrange(int a[], int low, int high, int x)
{// low和 high 分别为数据区的下界和上界
	int i, j, t;
	i = low; j = high;
	while (i < j) {
		while (i < j && a[j] >= x)
			j--;

		while (i < j && a[i] < x)
			i++;

		if (i < j)
		{
			t = a[j];
			a[j] = a[i];
			a[i] = t;
		}
	}
	if (a[i] < x)
		return i;
	return i - 1;
}

int func(int b[], int size)
{
	int index1 = arrange(b, 0, size - 1, 0);
	int index2 = arrange(b, index1, size - 1, 1);
	int count = index2 - index1;
	printf("count = %d\n", count);
	return count;
}

#define MAX 10

typedef int DT;

typedef struct Queue2
{
	int front[2];
	int rear[2];
	DT data[MAX];
}SharedQueue;

// 入队操作
int Enqueue(SharedQueue* Q, int queueNumber, int element) {
	// 检查队列是否已满
	if ((Q->rear[queueNumber] + 1) % MAX == Q->front[queueNumber]) {
		printf("Queue %d is full\n", queueNumber);
		return -1; // 队列已满，返回错误码
	}

	// 将元素添加到队列
	Q->data[Q->rear[queueNumber]] = element;

	// 更新尾指针
	Q->rear[queueNumber] = (Q->rear[queueNumber] + 1) % MAX;

	printf("Enqueued %d to Queue %d\n", element, queueNumber);
	return 0; // 入队成功，返回成功码
}