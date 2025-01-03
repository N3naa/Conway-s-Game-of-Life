#include <stdlib.h>
#include "cell.h"

int CreateCell(Position head_cell, int x, int y)
{
	Position new_cell = (Position )malloc(sizeof(struct Cell));

	if(new_cell == NULL)
	{
		perror("Could not allocate!");
		return EXIT_FAILURE;
	}

	new_cell->x = x;
	new_cell->y = y;
	new_cell->next = head_cell->next;
	head_cell->next = new_cell;
	new_cell->prev = head_cell;
	if(new_cell->next != NULL) new_cell->next->prev = new_cell;

	return EXIT_SUCCESS;
}

int LexicalOrder(Position cell, int x, int y)
{
	if(cell->next == NULL)
	{
		CreateCell(cell,x,y);
		return EXIT_SUCCESS;
	}

	else if(cell->next->x > x)
	{
		CreateCell(cell,x,y);
		return EXIT_SUCCESS;		
	}

	else
	{
		while(cell->next != NULL && cell->next->x < x)
		{
			cell = cell->next;
		}

		if((cell->next != NULL && cell->next->x > x)|| cell->next == NULL)
		{
			CreateCell(cell,x,y);
			return EXIT_SUCCESS;
		}

		else
		{
			if(cell->next->y > y)
			{
				CreateCell(cell,x,y);
				return EXIT_SUCCESS;
			}

			else
			{
				while(cell->next != NULL && cell->next->y < y)
				{
					cell = cell->next;
				}

				if(cell->next == NULL || (cell->next->y != y && cell->next != NULL))
				{
					CreateCell(cell,x,y);
				}

			}	
		}
	}

	return EXIT_SUCCESS;
}
