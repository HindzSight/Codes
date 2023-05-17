#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    struct Node* NEXT;
    int info;
};

typedef struct Node Node;

Node* createNode(int val) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if(new_node == NULL) {
        printf("------QUEUE OVERFLOW------\n");
        return NULL;
    } else {
        new_node->NEXT = NULL;
        new_node->info = val;
        return new_node;
    }
}

void Enqueue(Node** top, Node** tail, int data) {
    Node *new_node = createNode(data);
    if(new_node != NULL) {
        if(*top == NULL && *tail == NULL) {
            *top = new_node;
            *tail = new_node;
        } else {
            (*tail)->NEXT = new_node;
            *tail = new_node;
        }
    }
}

void Dequeue(Node** top, Node** tail) {
    if(*top == NULL) {
        printf("------QUEUE UNDERFLOW!------\n");
    } else {
        Node *temp = *top;
        if (*top == *tail) {
            *top = NULL;
            *tail = NULL;
            free(temp);
        } else {
            *top = temp->NEXT;
            free(temp);
        }
    }
}

void disfrnt(Node** top) {
    if(*top == NULL) {
        printf("------EMPTY QUEUE------\n");
    } else {
        printf("%d\n", (*top)->info);
    }
}

void display(Node** top) {
    Node* temp = *top;
    if(*top == NULL) {
        printf("------EMPTY QUEUE!------\n");
    } else {
        printf("Frames : ");
        while(temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->NEXT;
        }
        printf("\n");
    }
}

int finder(Node** top, Node** tail, int pro) {
    Node *temp = *top;
    if(*top == NULL) {
        return 0;
    } else {
        while(temp != NULL) {
            if((temp->info) == pro) {
                return 1;
            }
            temp = temp->NEXT;
        }
        return 0;
    }
}

void fifo(Node** top, Node** tail, char* s, int frames) {
    int i = 0;
    int n = strlen(s);
    int hit = 0;
    Node *temp = NULL;
    while(i < n) {
        temp = *top;
        Node *temp1 = *top;
        int val = 0;
        while(temp != NULL) {
            val++;
            temp = temp->NEXT;
        }
        int current_value = s[i] - '0';
        if(val == frames) {
            if(finder(top, tail, current_value)) {
                hit++;
                printf("Frames : HIT!\n");
                //display(top);
            } else {
                Dequeue(top, tail);
                Enqueue(top, tail, current_value);
                display(top);
            }
            i++;
        } else {
            Enqueue(top, tail, current_value);
            display(top);
            i++;
        }
    }
    printf("Page Faults : %d\n", (n-hit));
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    printf("FIFO Page Replacement Algorithm : \n");
    char ref_str[100];
    printf("\nEnter the reference string without spaces : ");
    scanf("%s", ref_str);
    int n;
	printf("Enter the frame number\n");
    scanf("%d", &n);
    fifo(ref_string, n);
    return 0;
}
