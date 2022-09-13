#include "minishell.h"

extern t_g	g_;

int		exe_cmd1(t_cmd *c);
void	exe_start(t_cmd *c, char *cm);

int	exe_cmd(t_cmd *c)
{
	char	*cm;
	pid_t	i;

	if (c->n_type == SYNTAXERROR)
		return (1);
	else if (c->n_type == SKIP)
		return (0);
	if (isbulitin(c->cmd[0]))
		return (exe_bulitin (c));
	cm = cm_name(c->cmd[0]);
	if (!cm)
		return (1);
	else if (!*cm)
	{
		free(cm);
		g_.exeret = 127;
		return (0);
	}
	i = fork();
	if (i < 0)
		return (1 + (printf("fork error \n") * 0));
	if (i == 0)
		exe_start(c, cm);
	free(cm);
	return (exe_cmd1(c));
}

int	exe_cmd1(t_cmd *c)
{	
	c->ps++;
	while (c->n_type != PIPE && c->ps)
	{
		wait(&(g_.exeret));
		if (WIFSIGNALED(g_.exeret))
			g_.exeret = WTERMSIG(g_.exeret) + 0x80;
		else
			g_.exeret = WEXITSTATUS(g_.exeret);
		c->ps--;
	}
	if (c->n_type == AND && g_.exeret)
		c->n_type = SKIP;
	else if (c->n_type == OR && !(g_.exeret))
		c->n_type = SKIP;
	return (0);
}

void	exe_start(t_cmd *c, char *cm)
{
	if (c->pipe[NEXT_PIPE] >= 0)
		close(c->pipe[NEXT_PIPE]);
	if (c->pipe[R_PIPE] >= 0)
	{
		dup2(c->pipe[R_PIPE], STDIN_FILENO);
		close(c->pipe[R_PIPE]);
	}
	if (c->pipe[W_PIPE] >= 0)
	{
		dup2(c->pipe[W_PIPE], STDOUT_FILENO);
		close(c->pipe[W_PIPE]);
	}
	execve(cm, c->cmd, ev(NULL));
	ft_putstr_fd("execution error\n", 2);
	exit(1);
}
