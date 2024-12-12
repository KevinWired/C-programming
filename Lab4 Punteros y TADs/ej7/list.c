#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"


struct _list { // DSA for linked-list.
    data item;
    struct _list* next;
};


// ==== Constructors ===

list create_list() {
	return NULL;
}


static list create_node(data e) { 
	list node;
	node = (void*) calloc(1, sizeof(struct _list));
	if (node == NULL) {
		fprintf(stderr, "Error: failed to allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	node->item = e;
	node->next = NULL;	
	return node;
}


list append(list ls, data e) { 
	if(empty_list(ls)) {
		return create_node(e);
	}
	list curr = ls;
	while(curr->next != NULL) {
		curr = curr->next;
	}
	list new_node = create_node(e);
	curr->next = new_node;
	return ls;
} 


// === Operations ===

bool empty_list(list ls) {
	return ls == NULL;
}


data head(list ls) {
	assert(!empty_list(ls));
	return ls->item;
}


list tail(list ls) {
    assert(!empty_list(ls));
    return ls->next;
}


unsigned int length(list ls) {
	if(empty_list(ls)) {
		return 0;
	}
	list curr = ls;
	unsigned int len = 0;
	while(curr->next != NULL) {
		curr = curr->next;
		len++;
	}
	return len;
}


list concat(list ls1, list ls2){
	list curr = ls2;
	while (curr != NULL) {
		ls1 = append(ls1, curr->item);
		curr = curr->next;
	}
	return ls1;
}


data nth_element(list ls, unsigned int index) {
    assert(!empty_list(ls) && index < length(ls));
    unsigned int aux = 0;
    list curr = ls;
    while (curr->next != NULL && aux != index) {
        curr = curr->next;
        aux++;
    }
    assert(curr != NULL);
    data element = curr->item;  
    return element;
}


list take(list ls, unsigned int n) {
    assert(!empty_list(ls) && n <= length(ls));
    unsigned int i = 0;
    list taken = create_list(); // Creating a new list involves freeing dynamic memory.
    list curr = ls;
    while (curr != NULL && i != n) {
        taken = append(taken, curr->item);
        curr = curr->next;
        i++;
    }
    return taken;
}


list drop(list ls, unsigned int n) {
    assert(!empty_list(ls) && n <= length(ls));
    list dropped = copy_list(ls);
    for (unsigned int i = 0; i != n; i++) {
        dropped = tail(dropped);
    }
    return dropped;
}


list copy_list(list ls) {
	list cpy = create_list(); // Creating a new list involves freeing dynamic memory.
	list curr = ls;
	while (curr != NULL) {
		cpy = append(cpy, curr->item);
		curr = curr->next;
	}
	return cpy;
}


// === Destructors ===

list destroy_list(list l) {
  if(l != NULL) {
    list a, b;
    a = l;
    b = a->next;
    while(a != NULL) {
      free(a);
      a = b;
      if(a != NULL) {
        b = a->next;
      }
    }
    l = a;
  }
  return l;
}
