#include <iostream>

#define MaxSize 10

// 定义队列结构体
struct Queue
{
    int data[MaxSize];
    int front, rear;
};

// 初始化队列
void Init(Queue &Q)
{
    Q.front = Q.rear = 0;
}

// 判断队列是否为空
bool IsEmpty(Queue &Q)
{
    return Q.front == Q.rear;
}

// 判断队列是否已满
bool IsFull(Queue &Q)
{
    return (Q.rear + 1) % MaxSize == Q.front;
}

// 头部入队
void F_Enqueue(Queue &Q, int value)
{
    if (IsFull(Q))
    {
        std::cout << "Queue is full. Cannot enqueue." << std::endl;
        return;
    }

    // 更新头部位置，确保循环
    Q.front = (Q.front - 1 + MaxSize) % MaxSize;
    Q.data[Q.front] = value;
}

// 尾部入队
void R_Enqueue(Queue &Q, int value)
{
    if (IsFull(Q))
    {
        std::cout << "Queue is full. Cannot enqueue." << std::endl;
        return;
    }

    // 更新尾部位置，确保循环
    Q.data[Q.rear] = value;
    Q.rear = (Q.rear + 1) % MaxSize;
}

// 头部出队
int F_Dequeue(Queue &Q)
{
    if (IsEmpty(Q))
    {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return -1; // Assuming -1 is not a valid element in the queue
    }

    // 获取并更新头部元素
    int deleted_item = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return deleted_item;
}

// 尾部出队
int R_Dequeue(Queue &Q)
{
    if (IsEmpty(Q))
    {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return -1; // Assuming -1 is not a valid element in the queue
    }

    // 获取并更新尾部元素
    Q.rear = (Q.rear - 1 + MaxSize) % MaxSize;
    return Q.data[Q.rear];
}

// 获取头部元素
int GetFront(Queue &Q)
{
    if (IsEmpty(Q))
    {
        std::cout << "Queue is empty." << std::endl;
        return -1; // Assuming -1 is not a valid element in the queue
    }

    return Q.data[Q.front];
}

// 获取尾部元素
int GetRear(Queue &Q)
{
    if (IsEmpty(Q))
    {
        std::cout << "Queue is empty." << std::endl;
        return -1; // Assuming -1 is not a valid element in the queue
    }

    return Q.data[(Q.rear - 1 + MaxSize) % MaxSize];
}

int main()
{
    // 创建队列并初始化
    Queue myQueue;
    Init(myQueue);

    // 操作队列
    F_Enqueue(myQueue, 1);
    R_Enqueue(myQueue, 2);
    F_Enqueue(myQueue, 3);
    R_Enqueue(myQueue, 4);

    // 打印队列头尾元素
    std::cout << "Front element: " << GetFront(myQueue) << std::endl;
    std::cout << "Rear element: " << GetRear(myQueue) << std::endl;

    // 出队操作
    std::cout << "Deleted front element: " << F_Dequeue(myQueue) << std::endl;
    std::cout << "Deleted rear element: " << R_Dequeue(myQueue) << std::endl;

    // 打印出队后的头尾元素
    std::cout << "Front element after dequeue: " << GetFront(myQueue) << std::endl;
    std::cout << "Rear element after dequeue: " << GetRear(myQueue) << std::endl;

    return 0;
}
