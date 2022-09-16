#include "minishell.h"
#include "debug.h"

extern t_g	g_;

int		exe_cmd1(t_cmd *c, pid_t pid);
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
	else if (!*cm && c->cmd[0][0] != '(')
	{
TEST
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
	return (exe_cmd1(c, i));
}

int	exe_cmd1(t_cmd *c, pid_t pid)
{
	t_pid	*buf;

	buf = malloc(sizeof(t_pid));
	if (!buf)
		kill(SIGKILL, 0);
	buf->p = pid;
	buf->befor = c->ps;
	c->ps = buf;
	while (c->n_type != PIPE && c->ps)
	{
		waitpid(c->ps->p, &(g_.exeret), 0);
		if (WIFSIGNALED(g_.exeret))
			g_.exeret = WTERMSIG(g_.exeret) + 0x80;
		else
			g_.exeret = WEXITSTATUS(g_.exeret);
		buf= c->ps;
		c->ps = c->ps->befor;
		free(buf);
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
	if (c->cmd[0][0] == '(')
	{
		c->cmd[0][ft_strlen(c->cmd[0]) - 1] = '\0';
		sub_shell(c->cmd[0] + 1);
		exit(g_.exeret);
	}
	execve(cm, c->cmd, ev(NULL));
	ft_putstr_fd("execution error\n", 2);
	exit(1);
}
