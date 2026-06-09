/*
 * ============================================
 * PROJECT: DATA STRUCTURES LIBRARY
 * INTERN ID: CITS3437
 * NAME: Aditya Singla
 * WEEKS: 4 Weeks (3rd June - 1st July)
 * COMPANY: CodTech IT Solutions
 * ============================================
 */

#include <stdio.h>
#include <stdlib.h>

/* ============================================
   DATA STRUCTURE 1: LINKED LIST
   ============================================ */

/* Node structure for Linked List */
struct Node {
    int data;
    struct Node *next;
};

/* Head pointer for linked list */
struct Node *head = NULL;

/* ============================================
   DATA STRUCTURE 2: STACK
   ============================================ */

#define STACK_SIZE 50

/* Stack structure */
struct Stack {
    int items[STACK_SIZE];
    int top;
};

/* ============================================
   DATA STRUCTURE 3: QUEUE
   ============================================ */

#define QUEUE_SIZE 50

/* Queue structure */
struct Queue {
    int items[QUEUE_SIZE];
    int front;
    int rear;
};

/* ============================================
   DATA STRUCTURE 4: BINARY SEARCH TREE
   ============================================ */

/* BST Node structure */
struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

/* Root of BST */
struct BSTNode *root = NULL;

/* ============================================
   LINKED LIST FUNCTIONS
   ============================================ */

/* Insert node at beginning of linked list */
void ll_insert_begin(int data) {
    /* Create new node */
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    printf("Inserted %d at beginning!\n", data);
}

/* Insert node at end of linked list */
void ll_insert_end(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    /* If list is empty */
    if (head == NULL) {
        head = new_node;
    } else {
        /* Traverse to last node */
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Inserted %d at end!\n", data);
}

/* Delete node from linked list */
void ll_delete(int data) {
    struct Node *temp = head;
    struct Node *prev = NULL;

    /* If head node contains data */
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from list!\n", data);
        return;
    }

    /* Search for node to delete */
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found!\n", data);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from list!\n", data);
}

/* Display linked list */
void ll_display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

/* Search in linked list */
void ll_search(int data) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at position %d!\n", data, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Element %d not found!\n", data);
}

/* ============================================
   STACK FUNCTIONS
   ============================================ */

/* Initialize stack */
void stack_init(struct Stack *s) {
    s->top = -1;
}

/* Check if stack is empty */
int stack_isEmpty(struct Stack *s) {
    return s->top == -1;
}

/* Check if stack is full */
int stack_isFull(struct Stack *s) {
    return s->top == STACK_SIZE - 1;
}

/* Push element to stack */
void stack_push(struct Stack *s, int data) {
    if (stack_isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    s->items[++s->top] = data;
    printf("Pushed %d to stack!\n", data);
}

/* Pop element from stack */
void stack_pop(struct Stack *s) {
    if (stack_isEmpty(s)) {
        printf("Stack Underflow! Stack is empty!\n");
        return;
    }
    printf("Popped %d from stack!\n", s->items[s->top--]);
}

/* Peek top element */
void stack_peek(struct Stack *s) {
    if (stack_isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element: %d\n", s->items[s->top]);
}

/* Display stack */
void stack_display(struct Stack *s) {
    if (stack_isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack (top to bottom): ");
    int i;
    for (i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

/* ============================================
   QUEUE FUNCTIONS
   ============================================ */

/* Initialize queue */
void queue_init(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

/* Check if queue is empty */
int queue_isEmpty(struct Queue *q) {
    return q->front == -1;
}

/* Check if queue is full */
int queue_isFull(struct Queue *q) {
    return q->rear == QUEUE_SIZE - 1;
}

/* Enqueue element */
void queue_enqueue(struct Queue *q, int data) {
    if (queue_isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", data);
        return;
    }

    if (queue_isEmpty(q)) {
        q->front = 0;
    }

    q->items[++q->rear] = data;
    printf("Enqueued %d to queue!\n", data);
}

/* Dequeue element */
void queue_dequeue(struct Queue *q) {
    if (queue_isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue!\n");
        return;
    }

    printf("Dequeued %d from queue!\n", q->items[q->front]);

    if (q->front == q->rear) {
        /* Queue becomes empty */
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
}

/* Display queue */
void queue_display(struct Queue *q) {
    if (queue_isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue (front to rear): ");
    int i;
    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

/* ============================================
   BINARY SEARCH TREE FUNCTIONS
   ============================================ */

/* Create new BST node */
struct BSTNode* bst_new_node(int data) {
    struct BSTNode *node = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Insert into BST */
struct BSTNode* bst_insert(struct BSTNode *node, int data) {
    /* If tree is empty */
    if (node == NULL) {
        return bst_new_node(data);
    }

    /* Insert in left subtree if data is smaller */
    if (data < node->data) {
        node->left = bst_insert(node->left, data);
    }
    /* Insert in right subtree if data is larger */
    else if (data > node->data) {
        node->right = bst_insert(node->right, data);
    }

    return node;
}

/* Inorder traversal (Left -> Root -> Right) */
void bst_inorder(struct BSTNode *node) {
    if (node != NULL) {
        bst_inorder(node->left);
        printf("%d ", node->data);
        bst_inorder(node->right);
    }
}

/* Preorder traversal (Root -> Left -> Right) */
void bst_preorder(struct BSTNode *node) {
    if (node != NULL) {
        printf("%d ", node->data);
        bst_preorder(node->left);
        bst_preorder(node->right);
    }
}

/* Postorder traversal (Left -> Right -> Root) */
void bst_postorder(struct BSTNode *node) {
    if (node != NULL) {
        bst_postorder(node->left);
        bst_postorder(node->right);
        printf("%d ", node->data);
    }
}

/* Search in BST */
void bst_search(struct BSTNode *node, int data) {
    if (node == NULL) {
        printf("Element %d not found in BST!\n", data);
        return;
    }

    if (data == node->data) {
        printf("Element %d found in BST!\n", data);
    } else if (data < node->data) {
        bst_search(node->left, data);
    } else {
        bst_search(node->right, data);
    }
}

/* ============================================
   MENU FUNCTIONS
   ============================================ */

void linked_list_menu();
void stack_menu();
void queue_menu();
void bst_menu();

/* Main menu */
void main_menu() {
    printf("\n========================================\n");
    printf("        DATA STRUCTURES LIBRARY        \n");
    printf("     Aditya Singla | CITS3437          \n");
    printf("========================================\n");
    printf("1. Linked List\n");
    printf("2. Stack\n");
    printf("3. Queue\n");
    printf("4. Binary Search Tree\n");
    printf("5. Exit\n");
    printf("========================================\n");
}

/* ---- MAIN FUNCTION ---- */
int main() {
    int choice;

    /* Initialize stack and queue */
    struct Stack s;
    struct Queue q;
    stack_init(&s);
    queue_init(&q);

    printf("\nWelcome to Data Structures Library!\n");

    while (1) {
        main_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: linked_list_menu();  break;
            case 2: stack_menu();        break;
            case 3: queue_menu();        break;
            case 4: bst_menu();          break;
            case 5:
                printf("\nGoodbye Aditya! Keep coding!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}

/* ---- LINKED LIST MENU ---- */
void linked_list_menu() {
    int choice, data;

    while (1) {
        printf("\n--- LINKED LIST ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Element\n");
        printf("4. Search Element\n");
        printf("5. Display List\n");
        printf("6. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                ll_insert_begin(data);
                ll_display();
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                ll_insert_end(data);
                ll_display();
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                ll_delete(data);
                ll_display();
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                ll_search(data);
                break;
            case 5:
                ll_display();
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

/* ---- STACK MENU ---- */
void stack_menu() {
    struct Stack s;
    stack_init(&s);
    int choice, data;

    while (1) {
        printf("\n--- STACK ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                stack_push(&s, data);
                stack_display(&s);
                break;
            case 2:
                stack_pop(&s);
                stack_display(&s);
                break;
            case 3:
                stack_peek(&s);
                break;
            case 4:
                stack_display(&s);
                break;
            case 5:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

/* ---- QUEUE MENU ---- */
void queue_menu() {
    struct Queue q;
    queue_init(&q);
    int choice, data;

    while (1) {
        printf("\n--- QUEUE ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                queue_enqueue(&q, data);
                queue_display(&q);
                break;
            case 2:
                queue_dequeue(&q);
                queue_display(&q);
                break;
            case 3:
                queue_display(&q);
                break;
            case 4:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

/* ---- BST MENU ---- */
void bst_menu() {
    int choice, data;

    while (1) {
        printf("\n--- BINARY SEARCH TREE ---\n");
        printf("1. Insert\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Search\n");
        printf("6. Back\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = bst_insert(root, data);
                printf("Inserted %d in BST!\n", data);
                printf("Inorder: ");
                bst_inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Inorder Traversal: ");
                bst_inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                bst_preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                bst_postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter data to search: ");
                scanf("%d", &data);
                bst_search(root, data);
                break;
            case 6:
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}
