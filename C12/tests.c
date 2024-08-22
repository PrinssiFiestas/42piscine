#include "ex00/ft_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ft_list_push_front(t_list **begin_list, void *data);
int ft_list_size(t_list *begin_list);
t_list *ft_list_last(t_list *begin_list);
void ft_list_push_back(t_list **begin_list, void *data);
t_list *ft_list_push_strs(int size, char **strs);
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
void ft_list_reverse(t_list **begin_list);
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void ft_list_sort(t_list **begin_list, int (*cmp)());
void ft_list_reverse_fun(t_list *begin_list);
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());

void list_equal_arr(t_list *list, int *arr, size_t arr_length, int line, size_t index)
{
	if (list == NULL && arr_length != 0)
	{
		fprintf(stderr, "Assertion failed! Not enough elements in list.\n");
		return ;
	}
	if (list == NULL)
		return ;
	if (*(int*)(list->data) != *arr)
	{
		fprintf(stderr, "Assertion failed! Line %i\nElement %zu: %i %i\n",
			line, index, *(int*)(list->data), *arr);
		return ;
	}
	list_equal_arr(list->next, arr + 1, arr_length - 1, line, index + 1);
}
#define assert_list_eq(LIST, ...) \
	list_equal_arr(LIST, (int[]){__VA_ARGS__}, sizeof((int[]){__VA_ARGS__})/4, __LINE__, 0)

int main(void)
{
	t_list* list = NULL; // TODO fix everything
	ft_list_push_front(&list, &(int){1});
	ft_list_push_front(&list, &(int){2});
	assert_list_eq(list, 1, 2);
	ft_list_clear(list, free);
}
