/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmarti <cedricmartin06@orange.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:30:03 by cedricmarti       #+#    #+#             */
/*   Updated: 2024/10/09 13:42:47 by cedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct Element
{
	int	data;
	struct Element	*next;
}	Element;

typedef struct Liste
{
	Element	*first_element;
}	Liste;

Liste	*list_init()
{
	Liste	*liste;
	Element	*element;

	liste = malloc(sizeof(*liste));
	element = malloc(sizeof(*element));
	if (liste == NULL || element == NULL)
		return (NULL);

	element->data = 0;
	element->next = NULL;
	liste->first_element = element;

	return (liste);
}

int	liste_len(Liste *liste)
{
	int	count;
	Element	*current;

	count = 0;
	current = liste->first_element;
	if (liste == NULL)
		return (0);
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	insert(Liste *liste, int new_data)
{
	Element *new_element = malloc(sizeof(*new_element));
	if (new_element == NULL)
		exit (EXIT_FAILURE);

	new_element->data = new_data;
	new_element->next = liste->first_element;
	liste->first_element = new_element;
}

void	insert_middle(Liste *liste, int index, int new_data)
{
	Element *new_element;
	Element *current;
	int i;

	i = 0;
	current = liste->first_element;
	new_element = malloc(sizeof(*new_element));
	if (new_element == NULL)
		exit (EXIT_FAILURE);

	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}
	new_element->data = new_data;
	new_element->next = current->next;
	current->next = new_element;
}

void	delete(Liste *liste)
{
	if (liste == NULL)
		exit (EXIT_FAILURE);

	if (liste != NULL)
	{
		Element *to_delete = liste->first_element;
		liste->first_element = liste->first_element->next;
		free(to_delete);
	}
}

void	delete_middle(Liste *liste, int index)
{
	Element *current;
	Element *to_delete;
	int	i;

	current = liste->first_element;
	i = 0;

	if (liste == NULL)
		exit (EXIT_FAILURE);

	while (current != NULL && i < index - 1)
	{
		current = current->next;
		i++;
	}
	to_delete = current->next;
	current->next = current->next->next;
	free(to_delete);

}

void	print_liste(Liste *liste)
{
	if (liste == NULL)
		exit (EXIT_FAILURE);

	Element *current = liste->first_element;

	while (current != NULL)
	{
		printf("[%d] -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	Liste *mylist = list_init();

	insert(mylist, 10);
	insert(mylist, 20);
	insert(mylist, 30);

	print_liste(mylist);
	printf("%d\n", liste_len(mylist));

	insert_middle(mylist, 2, 5);
	print_liste(mylist);
	printf("%d\n", liste_len(mylist));

	delete_middle(mylist, 3);
	print_liste(mylist);
	printf("%d\n", liste_len(mylist));

	delete(mylist);
	delete(mylist);
	delete(mylist);
	delete(mylist);

	print_liste(mylist);
	printf("%d\n", liste_len(mylist));

	return (0);
}
