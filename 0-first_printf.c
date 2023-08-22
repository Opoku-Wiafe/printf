#include "main.h"
/**
 * _printf - Function that print all characters that is %s, %c, %%
 * @format: The character being printed
 * Return: return *format and Nothing else
 */

int _printf(const char *format, ...)
{
	int print_char = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
	/* if first char is not % which is a parsing argument just print to stdio*/
	if (*format != '%')
	{
		write(1, format, 1);
		print_char++;
	}
	else
	{
		format++;	/*move to second char and check*/
		if (*format == '\0')	/*if next char is null*/
			break;
		if (*format == '%')	/*if its % then its a percentage sign*/
		{
			write(1, format, 1);
			print_char++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(args, int);	/*loop through characters*/

			write(1, &c, 1);
			print_char++;
		}
		else if (*format == 's')	/*check if char is string*/
		{
			char *str_char = va_arg(args, char*);
			int i;	/*length of string.*/

			for (i = 0; str_char[i] != '\0'; i++)
			write(1, &str_char[i], 1);
			print_char += i;
		}
	}
	format++;
	}
	va_end(args);
	return (print_char);
}

int main(void)
{
	_printf("Hello %s!\n", "Opoku Wiafe Stephen");
	_printf("The character is %c\n", 'A');
	_printf("You also welcome to another exciting programming class\n");
	_printf("This Text contain a %% sign\n");
	return (0);
}
