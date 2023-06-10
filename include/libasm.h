/* ************************************************************************** */
/*                                                                            */
/*                                                    :::       :::     :::   */
/*   libasm.h                                        :+:       :+: :+: :+:    */
/*                                                +:+ +:+     +:+  +  +:+     */
/*   By: ammah <ammah.connect@outlook.fr>       +#+   +:+    +#+     +#+      */
/*                                            +#+     +#+   +#+     +#+       */
/*   Created: 2023/06/09 18:23:13 by ammah   #+#      #+#  #+#     #+#        */
/*   Updated: 2023/06/09 19:28:28 by ammah ###       ########     ########    */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBASM_H__
# define __LIBASM_H__

# include <unistd.h>

typedef struct s_list {
  void *data;
  struct s_list *next;
} t_list;

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char * dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);
int		ft_atoi_base(char *str, char *base);
void	ft_list_push_front(t_list **, void *data);
int		ft_list_size(t_list *);
void	ft_list_sort(t_list **, int (*cmp)());
void	ft_list_remove_if(t_list **, void *data_ref, \
			int (*cmp)(void *,void *), void (*free_fn)(void *));


#endif
