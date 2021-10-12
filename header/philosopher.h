#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
#include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count;
	// struct timeval	begining;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				last_ate;
	int				last_slept;
	int				eating;
	int				eat_count;
}					t_philo;


int     ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	check_if_integer(char *s);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(const char *s);
int 	argument_checker(char **av);

#endif