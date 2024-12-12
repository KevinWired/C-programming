#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

/* Define `list` as an opaque pointer for encapsulation */
typedef struct _list* list;
typedef int data;

/**
 * Check if the list is empty.
 * @param ls The list to check.
 * @return `true` if the list is empty, `false` otherwise.
 */
bool empty_list(list ls);

/**
 * Create a new empty list.
 * @return A new empty list.
 */
list create_list();

/**
 * Get the first element of the list.
 * @param ls The list to get the head element from.
 * @return The first item of the list.
 */
data head(list ls);

/**
 * Get the list without the first element.
 * @param ls The list to get the tail from.
 * @return The list without the first element.
 */
list tail(list ls);

/**
 * Append an element to the end of the list.
 * @param ls The list to which the element will be added.
 * @return The modified list with the new element appended.
 */
list append(list ls, data e);

/**
 * Get the number of elements in the list.
 * @param ls The list to count.
 * @return The number of elements in the list.
 */
unsigned int length(list ls);

/**
 * Concatenate two lists.
 * @param ls1 The first list.
 * @param ls2 The second list.
 * @return ls1 containing the elements of `ls1` followed by `ls2`.
 */
list concat(list ls1, list ls2);

/**
 * Get the element at a specific index.
 * @param ls The list to get the element from.
 * @param index The zero-based index of the element.
 * @return The element at the specified index.
 */
data nth_element(list ls, unsigned int index);

/**
 * Take the first `n` elements from a list.
 * @param ls The list to take elements from.
 * @param n The number of elements to take.
 * @return A new list with the first `n` elements.
 */
list take(list ls, unsigned int n);

/**
 * Remove the first `n` elements from a list.
 * @param ls The list to drop elements from.
 * @param n The number of elements to drop.
 * @return the list without the first `n` elements.
 */
list drop(list ls, unsigned int n);

/**
 * Create a copy of a list.
 * @param ls The list to copy.
 * @return A new list that is a copy of the given list.
 */
list copy_list(list ls);

/**
 * Destroy the list and free its memory.
 * @param ls The list to destroy.
 */
list destroy_list(list ls);

#endif // _LIST_H
