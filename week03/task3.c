#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  struct Node* nextNode;
  int value;
};

typedef struct LinkedList {
  int size;
  struct Node* head;
};

void print_list(struct LinkedList* list) {
  printf("Array: \n");
  if (list->size > 0) {
    struct Node* currNode = list->head;
    while (currNode != NULL) {
      printf("%d ", currNode->value);
      currNode = currNode->nextNode;
    }
    printf("\n");
  }
}

struct Node* insert_node(struct LinkedList* list, int value) {
  if (list->size == 0) {
    list->head = malloc(sizeof(struct Node));
    list->head->value = value;
    list->head->nextNode = NULL;
    list->size += 1;
    return list->head;
  } else {
    struct Node* currNode = list->head;
    while (currNode->nextNode != NULL) {
      currNode = currNode->nextNode;
    }
    currNode->nextNode = malloc(sizeof(struct Node));
    currNode->nextNode->value = value;
    currNode->nextNode->nextNode = NULL;
    list->size += 1;
    return currNode->nextNode;
  }

}

void delete_node(struct LinkedList* list, struct Node* node) {
  if (list->size > 0) {
    if (list->head == node) {
      list->head = list->head->nextNode;
    } else {
      struct Node* prevNode = list->head;
      struct Node* currNode = list->head;
      while (currNode != node && currNode->nextNode != NULL) {
        prevNode = currNode;
        currNode = currNode->nextNode;
      }
      if (currNode == node) {
        if (currNode->nextNode != NULL) {
          prevNode->nextNode = currNode->nextNode;
        } else {
          prevNode->nextNode = NULL;
        }
        list->size -= 1;
      }
    }
  }
}

int main() {

  struct LinkedList list;
  list.size = 0;

  struct Node* first = insert_node(&list, 5);
  struct Node* second = insert_node(&list, 7);
  printf("Sometibng\n");
  print_list(&list);
  delete_node(&list, second);
  print_list(&list);

  return 0;
}
