
#include "push_swap.h"

#define BUCKETSIZE 19

/*
	-500 / 500
	-500 -400 -300 -200 -100 0 100 200 300 400 500
	14 21 35 -29 -2 -35 23 -7 -36 10
	sm = -36
*/
 
// Function to print the array contents
void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}
 
// Function to return the length
// of the Linked List
int findlength(t_stack *head)
{
    t_stack *curr = head;
    int cnt = 0;
    while (curr != NULL) {
        cnt++;
        curr = curr->next;
    }
    return cnt;
}
 
// Function to convert the
// Linked List to an array
int * convertArr(t_stack *head)
{
 
    // Find the length of the
    // given linked list
    int len = findlength(head);
 
    // Create an array of the
    // required length
    int arr[len];
 
    int index = 0;
    t_stack *curr = head;
 
    // Traverse the Linked List and add the
    // elements to the array one by one
    while (curr != NULL) {
        arr[index++] = curr->value;
        curr = curr->next;
    }

	int a;
	for (int i = 0; i < len; ++i) 
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (arr[i] > arr[j]) 
			{
				a = arr[i];
				arr[i] = arr[j];
				arr[j] = a;
			}
		}
	}

	printArr(arr, len);
	return (arr);
}


int *min_value_in_stack(t_stack *a)
{
	int arr[BUCKETSIZE];
	int n = 0;
	
	int smallest_node = get_min_value(&a);

	arr[0] = smallest_node;
	n++;

	int *temp = convertArr(a);

	// while (n < BUCKETSIZE)
	// {
	// 	arr[n] = temp[n];
	// 	n++;
	// }
	// // return &arr;
	// printArr(arr, n);
	return NULL;
}
