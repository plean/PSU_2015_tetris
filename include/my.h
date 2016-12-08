/*
** my.h :D
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Thu Oct  8 14:34:15 2015 David Zeng
** Last update Tue Mar  8 19:46:34 2016 David Zeng
*/

#ifndef MY_H_
# define MY_H_

# include <stdarg.h>

/* MY_H */

#ifndef READ_SIZE
# define READ_SIZE (256)
#endif /* !READ_SIZE */

void	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
double	my_get_dbl(char *str);
int	my_getnbr_err(char *str);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
void	my_putnbr_base(char *str, int nb, int n);
char	*my_strdup(char *src);
void	my_show_tab(char **tabi);
void	my_free_tab(char **tabi);
void	my_put_err(char *str);
char	*my_strndup(char *str, int nb);
int	my_tablen(char **tabi);
char	*get_next_line(const int fd);
char	*my_realloc(char *pointer, unsigned int size);
unsigned int	my_getnbr_base(char *str, char *base);

/* MY_PRINTF */

typedef int	(*t_cas)(va_list, int*);

int	my_printf(const char *format, ...);
int	my_printi(va_list list, int *n);
int	my_prints(va_list list, int *n);
int	my_printc(va_list list, int *n);
int	my_printx(va_list list, int *n);
int	my_printX(va_list list, int *n);
int	my_printo(va_list list, int *n);
void	my_put_nbr_base(unsigned int nb, char *base);
int	my_printper(va_list list, int *n);
int	my_printu(va_list list, int *n);
int	my_printb(va_list list, int *n);
void	my_putunsigned(unsigned int nb);
int	my_get_oct(unsigned char nb);
void	my_put_S(unsigned char c, int *n);
int	my_printS(va_list list, int *n);
int	my_printp(va_list list, int *n);
int	my_printtab(va_list list, int *n);
void	my_put_16(unsigned long int nb, char *base);
int	disp_stdarg(const char *format, int *i, va_list list, int *n);

/* MY_SPRINTF */

# define SPRINTF_SIZE 2048

typedef int	(*t_cass)(va_list, char*);

void	my_sputchar(char *buffer, char c);
void	my_sputstr(char *buffer, char *str);
void	my_sshow_tab(char *buffer, char **tabi);
void	my_sput_nbr(char *buffer, int nb);
int	disp_sprintf(const char *str, int *i, va_list list, char *buffer);
int	my_sprinti(va_list list, char *buffer);
int	my_sprints(va_list list, char *buffer);
int	my_sprintc(va_list list, char *buffer);
int	my_sprintper(va_list list, char *buffer);
int	my_sprinto(va_list list, char *buffer);
int	my_sprintX(va_list list, char *buffer);
int	my_sprintx(va_list list, char *buffer);
void	my_sput_nbr_base(char *buffer, unsigned int nb, char *base);
int	my_sprintp(va_list list, char *buffer);
void	my_sput_16(char *buffer, unsigned long int nb, char *base);
int	my_sprintb(va_list list, char *buffer);
int	my_sprintu(va_list list, char *buffer);
void	my_sputunsigned(char *buffer, unsigned int nb);
int	my_sget_oct(unsigned char nb);
void	my_sput_S(unsigned char c, char *buffer);
int	my_sprintS(va_list list, char *buffer);
int	my_sprintf(char *out, const char *format, ...);

#endif /* !MY_H_ */
