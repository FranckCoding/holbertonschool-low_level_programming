#include "main.h"

/**
 * read_textfile - Reads a text file and prints it
 * to the POSIX standard output
 *
 * @filename: Name of the file
 * @letters: Numbers of letters it should read and print
 *
 * Return: 0 if the file can not be opened or read. Or if filename is NULL.
 * Or if write fails or does not write the expected amount of bytes.
 * Otherwise, return the actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	size_t numberWrite, numberRead;
	char *buf;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);

	if (buf == NULL)
		return (0);

	numberRead = read(fd, buf, letters);

	if (numberRead == -1)
		return (0);

	numberWrite = write(1, buf, letters);
	close(fd);
	free(buf);

	if (numberWrite == -1)
		return (0);

	return (numberWrite);
}
