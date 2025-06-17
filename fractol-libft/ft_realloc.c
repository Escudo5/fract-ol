/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:00:58 by smarquez          #+#    #+#             */
/*   Updated: 2024/10/10 16:13:57 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*realloc_line_frag(char *str, int new_size, int old_size)
{
	char	*new_line;
	int		i;

	new_line = malloc(new_size);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_line[i] = str[i];
		i++;
	}
	new_line[i] = '\0';
	free(str);
	return (new_line);
}
