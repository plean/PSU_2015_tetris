/*
** my_list.h for list in /home/zeng_d/usefull/my_lib/source
**
** Made by David Zeng
** Login   <zeng_d@epitech.net>
**
** Started on  Tue Oct 20 15:38:09 2015 David Zeng
** Last update Wed Mar 16 00:01:58 2016 Jean PLANCHER
*/

#ifndef MY_LIST_H_
# define MY_LIST_H_

typedef struct	s_node
{
  void		*data;
  struct s_node	*next;
  struct s_node *prev;
}		t_node;

typedef struct s_list
{
  int		max_h;
  int		max_w;
  int		length;
  struct s_node	*fin;
  struct s_node	*debut;
}		t_list;

t_list	*my_declare_list();
int	my_add_list(t_list *list, void *data);
int	my_add_first(t_list *list, void *data);
void	my_show_list(t_list *list);
int	my_del_node(t_list *list, t_node *node);
void	my_free_list(t_list **list);
void	my_free_all(t_list **list, void (*ptr)());

#endif /* !MY_LIST_H_ */
