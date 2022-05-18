#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * _getline - extracts characters & stores them in a string
 * until the delim char is found
 * @lineptr: address of the buffer to store the line read
 * @n: length
 * @fd: file descriptor to read from
 * Return: no. of characters read
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	const size_t initial = 50, step = 50;
	size_t newsize;
	char *temp, *str;
	size_t num_read = 0;

	if ((lineptr == NULL) || (n == NULL))
		return (-1);
	if (*lineptr == NULL)
	{
		*lineptr = malloc(initial);
		if (*lineptr == NULL)
			return (-1);
		*n = initial;
	}
	str = malloc(sizeof(char));
	while ((read(fd, str, 1)) != EOF)
	{
		num_read++;
		if (num_read >= *n)
		{
			newsize = *n + step;
			temp = _realloc(*lineptr, *n, newsize + 1);
			if (temp != NULL)
				*lineptr = temp, *n = newsize;
			else
				return (-1);
		}

		(*lineptr)[num_read - 1] = *str;
		if (*str == '\n')
			break;
	}
	if (*str == EOF)
		return (-1);
	(*lineptr)[num_read] = '\0';
	free(str);
	return (num_read);
}

/**
 * _realloc - reallocates a memory block
 * @ptr: initial memory block
 * @old_size: size of the allocated space for ptr
 * @new_size: new space size to be allocated
 * Return: the new memory block if initial & new memory blocks
 * are same, else return NULL
 */

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;
	unsigned int init_size;

	if (new_size == old_size)
		return (ptr);
	if (new_size <= 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		free(ptr);
		return (new_ptr);
	}

	init_size = old_size < new_size ? old_size : new_size;
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	_memcpy(new_ptr, ptr, init_size);

	free(ptr);
	return (new_ptr);
}

/**
 *_memcpy - copies a memory area
 * @dest: destination memory
 * @src: source memory
 * @n: no. of bytes to copy
 * Return: pointer to the destination
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; ++a)
		*(dest + a) = *(src + a);
	return (dest);
}
