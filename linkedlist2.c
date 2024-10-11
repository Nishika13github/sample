#include <stdio.h>

#define MAX_NODES 100

struct Node {
    int data;
    int next;
};

int main() {
    struct Node linkedList[MAX_NODES];
    int head = -1;
    int currentIndex = 0;

    int dataToInsert[] = {10, 20, 30};
    int dataCount = sizeof(dataToInsert) / sizeof(dataToInsert[0]);

    for (int i = 0; i < dataCount; i++) {
        if (currentIndex >= MAX_NODES) {
            printf("List is full!\n");
            return 1;
        }

        linkedList[currentIndex].data = dataToInsert[i];
        linkedList[currentIndex].next = -1;

        if (head == -1) {
            head = currentIndex;
        } else {
            int temp = head;
            while (linkedList[temp].next != -1) {
                temp = linkedList[temp].next;
            }
            linkedList[temp].next = currentIndex;
        }

        currentIndex++;
    }

    printf("Linked list: ");
    int temp = head;
    while (temp != -1) {
        printf("%d -> ", linkedList[temp].data);
        temp = linkedList[temp].next;
    }
    printf("NULL\n");

    return 0;
}
