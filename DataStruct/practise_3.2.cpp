//practise 3.2
#include <iostream>

using namespace std;

struct linkedList
{
    int number;
    linkedList *next;
};

void Swap(linkedList *list, int pos1, int pos2)
{
    int index = 0;
    linkedList *Olist = list;
    linkedList *node1 = Olist;

    while(index < pos1-1)
    {
        index++;
        node1 = node1->next;
    }

    linkedList *node2 = node1;
    while(index < pos2-1)
    {
        index++;
        node2 = node2->next;
    }

    linkedList *temp = node1->next->next;
    node1->next->next = node2->next->next;
    node2->next->next = temp;
    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
}

int main(int argc, char const *argv[])
{
    return 0;
}