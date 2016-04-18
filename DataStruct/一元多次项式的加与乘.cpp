#include <iostream>

typedef struct Node {
    int xishu;
    int zhishu;
    Node *next = NULL;
} *Polynomial;

Polynomial Read(int &f);

void Attach(int xishu, int zhishu, Polynomial &Rear);

int compare(int &a, int &b);

Polynomial AddP(Polynomial &p1, Polynomial &p2);

void PrintP(Polynomial &P);

Polynomial MultP(Polynomial &p1, Polynomial &p2);

int main() {
    Polynomial P1, P2, Ap1, Ap2;
    int f0a = 1;
    int f0b = 1;
    P1 = Read(f0a);
    P2 = Read(f0b);
    if (f0a !=0 && f0b != 0) {
        Ap1 = MultP(P1, P2);
        Ap2 = AddP(P1, P2);
        PrintP(Ap1);
        PrintP(Ap2);
    }
    else {
        std::cout << 0 << " " << 0 << std::endl;
        if (f0a == 0)
            PrintP(P2);
        else
            PrintP(P1);
//        std::cout << 0 << " " << 0 << std::endl;
    }
    return 0;
}

Polynomial Read(int &f) {
    Polynomial P, Rear, temp;
//    P = (Polynomial) new Polynomial;
    P = (Polynomial) malloc(sizeof(Node));//内存中建一个头节点P,与上条语句等同
    P->next = NULL;//将尾指针清空
    Rear = P;//将头节点指针复制给Rear指针,Rear用来指向之后新建的节点
    int n;
    std::cin >> n;
    if (n == 0) {
        f = 0;
        return NULL;
    }
    else {
        int xishu;
        int zhishu;
        while (n-- != 0) {
            std::cin >> xishu >> zhishu;
            Attach(xishu, zhishu, Rear);
        }
//    P = P->next;//头节点指向第一个节点
        Rear->next = NULL;
        temp = P;
        P = P->next;
        free(temp);
        return P;//返回链表第一节点
    }
}

void Attach(int xishu, int zhishu, Polynomial &Rear) {
    Polynomial nP;
//    nP = (Polynomial) new Polynomial;
    nP = (Polynomial) malloc(sizeof(Node));//初始化新节点
    //赋值
    nP->xishu = xishu;
    nP->zhishu = zhishu;
    nP->next = NULL;
//    //将指向上一节点的Rear指针的尾指针指向此节点
    Rear->next = nP;
    //将Rear指向此节点
    Rear = nP;
}

Polynomial MultP(Polynomial &p1, Polynomial &p2) {
    Polynomial hp1 = p1;
    Polynomial hp2 = p2;
    Polynomial AnswerP, aRear, temp;
    AnswerP = (Polynomial) new Node;
    AnswerP->next = NULL;
    aRear = AnswerP;
    while (hp2 != NULL) {
        Attach(hp1->xishu * hp2->xishu, hp1->zhishu + hp2->zhishu, aRear);
        hp2 = hp2->next;
    }
    temp = AnswerP;
    AnswerP = AnswerP->next;
    free(temp);
    hp1 = hp1->next;
    while (hp1 != NULL) {
        hp2 = p2;
        aRear = AnswerP;
        while (hp2 != NULL) {
            temp = (Polynomial) new Node;
            temp->xishu = hp1->xishu * hp2->xishu;
            temp->zhishu = hp1->zhishu + hp2->zhishu;
            AnswerP = AddP(AnswerP, temp);
            hp2 = hp2->next;
        }
        hp1 = hp1->next;
    }
    return AnswerP;
}

int compare(int &a, int &b) {
    int f;
    if (a < b)
        f = -1;
    else if (a == b)
        f = 0;
    else
        f = 1;
    return f;
}

Polynomial AddP(Polynomial &p1, Polynomial &p2) {
    Polynomial hp1 = p1;
    Polynomial hp2 = p2;
    Polynomial AnswerP, aRear, temp;
//    AnswerP = (Polynomial) new Polynomial;
    AnswerP = (Polynomial) malloc(sizeof(Node));
    AnswerP->next = NULL;
    aRear = AnswerP;
    while (hp1 != NULL && hp2 != NULL) {
        int a = hp1->zhishu;
        int b = hp2->zhishu;
        switch (compare(a, b)) {
            case -1:
                Attach(hp2->xishu, hp2->zhishu, aRear);
                if (hp2->next == NULL)
                    hp2 = NULL;
                else
                    hp2 = hp2->next;
                break;
            case 0:
                int sum;
                sum = hp1->xishu + hp2->xishu;
                if (sum != 0.0) {
                    Attach(sum, a, aRear);
                    if (hp1->next == NULL)
                        hp1 = NULL;
                    else
                        hp1 = hp1->next;
                    if (hp2->next == NULL)
                        hp2 = NULL;
                    else
                        hp2 = hp2->next;
                }
                else {
                    if (aRear == AnswerP) {
                        Attach(0, 0, aRear);
                        hp1 = hp1->next;
                        hp2 = hp2->next;
                    }
                    else {
                            hp1 = hp1->next;
                            hp2 = hp2->next;
                    }
                }
                break;
            case 1:
                Attach(hp1->xishu, hp1->zhishu, aRear);
                if (hp1->next == NULL)
                    hp1 = NULL;
                else
                    hp1 = hp1->next;
                break;
            default:break;
        }
    }
    while (hp1 != NULL) {
        Attach(hp1->xishu, hp1->zhishu, aRear);
        if (hp1->next == NULL)
            hp1 = NULL;
        else
            hp1 = hp1->next;
    }
    while (hp2 != NULL) {
        Attach(hp2->xishu, hp2->zhishu, aRear);
        if (hp2->next == NULL)
            hp2 = NULL;
        else
            hp2 = hp2->next;
    }
    temp = AnswerP;
    AnswerP = AnswerP->next;
    free(temp);
    return AnswerP;
}

void PrintP(Polynomial &P) {
    Polynomial temp = P;
    while (temp != NULL) {
        std::cout << temp->xishu << " " << temp->zhishu;
        temp = temp->next;
        if (temp != NULL)
            std::cout << " ";
    }
    std::cout << std::endl;
}

git@github.com:Xliezone/DateStruct.git