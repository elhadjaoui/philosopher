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
	pthread_mutex_t *forks;
	pthread_mutex_t *print;
	struct timeval	start;
}					t_data;

typedef struct s_philo
{
	int				id;
	int				last_ate;
	int				last_slept;
	int				eating;
	int				eat_count;
	int				data_eat_count;
	int				num_philo;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t *fork;
	pthread_mutex_t *print;
	struct timeval	start;
}					t_philo;


int     ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	check_if_integer(char *s);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
int     ft_strlen(const char *s);
int 	argument_checker(char **av);
int		current_time(struct timeval start);
void	think(t_philo *philo);
void	take_fork1(t_philo *philo);
void	take_fork2(t_philo *philo);
void	busy(int time_to_rest, int last, struct timeval start_time);
void	eat(t_philo *philo);
void	to_bed(t_philo *philo);
void	died(t_philo philo);
#endif