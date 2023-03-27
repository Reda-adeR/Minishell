/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharrass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:56:51 by aharrass          #+#    #+#             */
/*   Updated: 2023/03/15 14:46:18 by aharrass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_echo(t_cmd *cmd)
{
	int	i;

	i = 1;
	if (cmd->args[1] && ft_strcmp2(cmd->args[1], "-n") == 0)
		i++;
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], 1);
		if (cmd->args[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if ((cmd->args[1] && ft_strcmp2(cmd->args[1], "-n") != 0) || !cmd->args[1])
		ft_putchar_fd('\n', 1);
}
