#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

// D���m� olu�turma fonksiyonu
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// D���m eklemek i�in kullan�lan fonksiyon
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// B�y�kten k����e s�ralamak i�in kullan�lan fonksiyon
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

// D���mleri yazd�rmak i�in kullan�lan fonksiyon
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
        data = rand() % 100; // 0 ile 99 aras�nda rastgele say� �retme
        insertNode(&list, data);
    }

    printf("Random list: ");
    printList(list);

    sortList(&list);

    printf("Sorted list: ");
    printList(list);

    return 0;
}

