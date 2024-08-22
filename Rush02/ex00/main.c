#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct s_dict_value
{
	char *key;
	size_t key_length;
	char *value;
	size_t value_length;
} t_dict_value;

size_t entry_index(t_dict_value *arr, size_t arr_length, size_t arg_length)
{
	size_t i = 0;
	while (i < arr_length)
	{
		if (arg_length < arr[i].key_length)
			return i - 1;
		++i;
	}
	return (size_t)-1;
}

void putstr(const char* str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	return (0);
}

void print_words(t_dict_value *entries, size_t entries_length, const char *input, size_t input_length)
{
	size_t i;

	if (input_length == 1)
	{
		putstr(entries[input[0] - '0'].value);
		putstr(" ");
		return ;
	}
	if (input_length == 2 && input[0] == '1')
	{
		putstr(entries[10 * (input[0] - '0') + input[1] - '0'].value);
		putstr(" ");
		return ;
	}
	if (input_length == 2)
	{
		i = 0;
		while (input[0] != entries[i].key[0] || entries[i].key[1] != '0')
			++i;
		putstr(entries[i].value);
		putstr(" ");
		if (input[1] != '0')
			print_words(entries, entries_length, input + 1, 1);
		return ;
	}
	if (input_length == 3)
	{
		print_words(entries, entries_length, input, 1);
		i = entry_index(entries, entries_length, input_length);
		putstr(entries[i].value);
		putstr(" ");
		if (input[1] != '0')
			print_words(entries, entries_length, input + 1, 2);
		else if (input[2] != '0')
			print_words(entries, entries_length, input + 2, 1);
		return ;
	}
	i = entry_index(entries, entries_length, input_length);
	if (i == 27)
		i = 10;
	size_t digits = input_length - (entries[i].key_length - 1);
	print_words(entries, entries_length, input, digits);
	putstr(entries[i].value);
	putstr(" ");
	while (input_length - digits != 0)
	{
		if (input[digits] != '0')
		{
			print_words(entries, entries_length, input + digits, input_length - digits);
			break ;
		}
		++digits;
	}
}

int main(int argc, char **argv)
{
	const char *path = "numbers.dict";
	if (argc == 3)
		path = argv[1];
	int dict_fd = open(path, O_RDONLY);
	if (argc == 3)
		argv[1] = argv[2];
	size_t newline_count = 0;
	char c;
	while (read(dict_fd, &c, 1))
		if (c == '\n')
			newline_count++;
	close(dict_fd);

	t_dict_value *arr = malloc(newline_count * sizeof(t_dict_value));

	dict_fd = open(path, O_RDONLY);
	bool in_left_field = true;
	size_t length = 0;
	size_t i = 0;
	while (read(dict_fd, &c, 1))
	{
		if (c == ' ')
			continue ;
		if (c == ':')
		{
			arr[i].key_length = length;
			in_left_field = false;
			length = 0;
			continue;
		}
		if (c == '\n')
		{
			arr[i].value_length = length;
			in_left_field = true;
			length = 0;
			++i;
			continue ;
		}
		++length;
	}
	close(dict_fd);

	i = 0;
	while (i < newline_count)
	{
		arr[i].key = malloc(arr[i].key_length + sizeof"");
		arr[i].value = malloc(arr[i].value_length + sizeof"");
		++i;
	}

	dict_fd = open(path, O_RDONLY);
	i = 0;
	while (read(dict_fd, &c, 1))
	{
		if (c == ' ')
			continue ;
		if (c == ':')
		{
			arr[i].key[length] = '\0';
			in_left_field = false;
			length = 0;
			continue;
		}
		if (c == '\n')
		{
			arr[i].value[length] = '\0';
			in_left_field = true;
			length = 0;
			++i;
			continue ;
		}
		if (in_left_field)
			arr[i].key[length] = c;
		else
			arr[i].value[length] = c;
		++length;
	}
	close(dict_fd);

	// ------------------------------------------------------------------------

    while (argv[1][0] == ' ')
		argv[1]++;
	int sign = 1;
	while (argv[1][0] == '+' || argv[1][0] == '-')
	{
		if (argv[1][0] == '-')
			sign *= -1;
		argv[1]++;
	}
    while (argv[1][0] == '0')
		argv[1]++;
	if (sign == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}

	size_t input_length = 0;
	while ('0' <= argv[1][input_length] && argv[1][input_length] <= '9')
		++input_length;
	if (argv[1][input_length] != '\0')
	{
		write(1, "Error\n", 6);
		return (0);
	}

	// ------------------------------------------------------------------------

	if (input_length == 0)
		putstr(arr[0].value);
	else
		print_words(arr, newline_count, argv[1], input_length);
	putstr("\n");

	i = 0;
	while (i < newline_count)
	{
		free(arr[i].key);
		free(arr[i].value);
		++i;
	}
	free(arr);
}
