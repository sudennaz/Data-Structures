#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// Düðümü oluþturma fonksiyonu
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Düðüm eklemek için kullanýlan fonksiyon
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Büyükten küçüðe sýralamak için kullanýlan fonksiyon
void sortList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;
    int temp;

    while (current != NULL) {
        nextNode = current->next;

        while (nextNode != NULL) {
            if (current->data < nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }

            nextNode = nextNode->next;
        }

        current = current->next;
    }
}

// Düðümleri yazdýrmak için kullanýlan fonksiyon
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list = NULL;
    int i, data;


    for (i = 0; i < 100 ; i++) {
        data = rand() % 100; // 0 ile 99 arasýnda rastgele sayý üretme
        insertNode(&list, data);
    }

    printf("Random list: ");
    printList(list);

    sortList(&list);

    printf("Sorted list: ");
    printList(list);

    return 0;
}

