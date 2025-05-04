#include <cstdio>
#include <cstdlib>

// Singly Linked List class
class SLL {
private:
  struct node {
    int data;
    struct node *next;
  };
  struct node *head;

  void displayReverse(struct node *);

public:
  SLL() { head = NULL; };
  void insbeg(int);
  void insend(int);
  int inspos(int, int);
  void delbeg();
  void delend();
  int delpos(int);
  void search(int);
  void display();
  void displayReverse();
  void reverseList();
};

int main() {
  SLL list;
  int choice, num, pos;

  while (1) {
    printf("\n*** Singly Linked List Operations ***\n");
    printf("1. Insert Beginning\n");
    printf("2. Insert End\n");
    printf("3. Insert Position\n");
    printf("4. Delete Beginning\n");
    printf("5. Delete End\n");
    printf("6. Delete Position\n");
    printf("7. Search\n");
    printf("8. Display\n");
    printf("9. Display Reverse\n");
    printf("10. Reverse Link\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter number to insert: ");
      scanf("%d", &num);
      list.insbeg(num);
      break;
    case 2:
      printf("Enter number to insert: ");
      scanf("%d", &num);
      list.insend(num);
      break;
    case 3:
      printf("Enter number to insert: ");
      scanf("%d", &num);
      printf("Enter position: ");
      scanf("%d", &pos);
      list.inspos(num, pos);
      break;
    case 4:
      list.delbeg();
      break;
    case 5:
      list.delend();
      break;
    case 6:
      printf("Enter position to delete: ");
      scanf("%d", &pos);
      list.delpos(pos);
      break;
    case 7:
      printf("Enter number to search: ");
      scanf("%d", &num);
      list.search(num);
      break;
    case 8:
      list.display();
      break;
    case 9:
      printf("List in reverse order: \n");
      list.displayReverse();
      printf("NULL\n");
      break;
    case 10:
      list.reverseList();
      printf("List reversed successfully\n");
      break;
    case 11:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}

// Function to insert a node at the beginning
void SLL::insbeg(int num) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = head;
  head = newNode;
}

// Function to insert a node at the end
void SLL::insend(int num) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  struct node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to insert a node at a specific position
int SLL::inspos(int num, int pos) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;

  if (pos == 0) {
    newNode->next = head;
    head = newNode;
    return 0;
  }

  struct node *temp = head;
  for (int i = 0; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position out of range\n");
    free(newNode);
    return 0;
  }

  newNode->next = temp->next;
  temp->next = newNode;
  return 0;
}

// Function to delete a node from the beginning
void SLL::delbeg() {
  if (head == NULL) {
    printf("The List is Empty\n");
    return;
  }

  struct node *temp = head;
  head = head->next;
  free(temp);
}

// Function to delete a node from the end
void SLL::delend() {
  if (head == NULL) {
    printf("The List is Empty\n");
    return;
  }

  struct node *temp = head;
  struct node *prev = NULL;

  if (head->next == NULL) {
    head = NULL;
    free(temp);
    return;
  }

  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  prev->next = NULL;
  free(temp);
}

// Function to delete a node from a specific position
int SLL::delpos(int pos) {
  if (head == nullptr) {
    printf("The List is Empty\n");
    return 0;
  }

  struct node *temp = head;
  struct node *prev = nullptr;

  if (pos == 0) {
    head = temp->next;
    free(temp);
    return 0;
  }

  for (int i = 0; i < pos && temp != nullptr; i++) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == nullptr) {
    printf("Position out of range\n");
    return 0;
  }

  prev->next = temp->next;
  free(temp);
  return 0;
}

// Function to search for an element in the list
void SLL::search(int num) {
  struct node *temp = head;
  int pos = 0;

  while (temp != NULL) {
    if (temp->data == num) {
      printf("Element %d found at position %d\n", num, pos);
      return;
    }
    temp = temp->next;
    pos++;
  }

  printf("Element %d not found in the list\n", num);
}

// Function to display the list
void SLL::display() {
  struct node *temp = head;

  if (head == NULL) {
    printf("The List is Empty\n");
    return;
  }

  while (temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Function to display the list in reverse order
void SLL::displayReverse() { displayReverse(head); }

// Helper function to display the list in reverse order
void SLL::displayReverse(struct node *temp) {
  if (temp == nullptr)
    return;
  displayReverse(temp->next);
  printf("%d->", temp->data);
}

// Function to reverse the list
void SLL::reverseList() {
  struct node *prev = nullptr;
  struct node *current = head;
  struct node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}
