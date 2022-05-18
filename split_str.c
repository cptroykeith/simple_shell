#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "shell.h"

/**
 * _strtok - splits a string into smaller string tokens
 * @str: string
 * @delim: delimiters
 * Return: pointer to the next token
 */

char *_strtok(char *str, char *delim)
{
	static char *data;
	char *token;
	int x;

	if (str != NULL)
		data = str;

	if (data == NULL)
		return (NULL);

	token = malloc(_strlen(data) + 1);
	if (token == NULL)
		return (NULL);

	x = 0;
	while (data[x])
	{
		if (isdelim(data[x], delim))
		{
			token[x] = '\0';
			data = data + x + 1;
			return (token);
		}
		else
		{
			token[x] = data[x];
		}
		++x;
	}
	token[x] = '\0';
	data = NULL;

	return (token);
}

/**
 * isdelim - check if a character is from a set of delimiters
 * @ch: character to check
 * @delim: an array of delimiters
 * Return: 1 if found, otherwise 0
 */

int isdelim(char ch, char *delim)
{
	int y;

	y = 0;
	while (delim[y])
	{
		if (delim[y] == ch)
			return (1);
		y++;
	}
	return (0);
}
