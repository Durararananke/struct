struct Stack{};
void InitStack(Stack &S);
void DestroyStack(Stack &S);
bool IsEmpty(Stack S);
bool Push(Stack &S, ElemType e);
bool Pop(Stack &S, ElemType &e);
bool Top(Stack S, ElemType &e);