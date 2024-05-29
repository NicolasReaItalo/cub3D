/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <nrea@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 11:37:36 by nrea              #+#    #+#             */
/*   Updated: 2024/05/29 12:12:22 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


/*
[]	Verifier l'extension du fichier -->ER_BAD_EXTENSION
[]	ouvrir le fichier  --> ER_OPEN_FILE
[]	lire le fichier ligne par ligne -> liste chainee (remplacer les \n par \0)
[]	chercher les identifiants remplir les donnees
 - verification ouverture et creation des textures
 - verification des valeurs de couleurs
Si on detecte un [espace/0/1/N/W/S] -> la carte debute
- On determine les dimensions de la carte
 - remplissage de la carte -> si autre caractere que [espace/0/1/N/W/S] ou chaine vide ou error
 - si pas entouree de murs --> error
 - si pos personnage pas initialisee ou initialisee deux fois--> error
*/


int	append_line(t_line **head, char	*content)
{
	t_line	*new;
	t_line	*lst;

	if (!content)
		return (1);
	new = malloc(sizeof(t_line));
	if (!new)
		return (1);
	new->content = ft_strdup(content);
	if (!new->content)
	{
		free(new);
		return (1);
	}
	new->next = NULL;
	if (!*head)
		*head = new;
	else
	{
		lst = *head;
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	return (0);
}

void	free_scene(t_line **scene)
{
	t_line	*cur;
	t_line	*next;

	cur = NULL;
	next = NULL;
	if (!scene || !*scene)
		return;
	cur = *scene;
	while (cur)
	{
		next = cur->next;
		free(cur->content);
		free(cur);
		cur = next;
	}
	*scene = NULL;
}

/*replace \n char with \0*/
char *replace_eol(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			s[i] = '\0';
		i++;
	}
	return (s);
}

int	load_scene(char *file_path, t_line **scene)
{
	char	*line;
	int		file;

	*scene = NULL;
	line = NULL;
	if (!file_path || !ft_check_extension(file_path))
		return (error_handler(ERR_INVALID_EXTENSION));
	file = open(file_path, O_RDONLY);
	if (file == -1)
		return (error_handler(ERR_OPEN));
	line = get_next_line(file);
	while (line)
	{
		if (append_line(scene, replace_eol(line)))
		{
			free_scene(scene);
			return (error_handler(ERR_INTERNAL));
		}
		free(line);
		line = NULL;
		line = get_next_line(file);
	}
	close(file);
	return (SUCCESS);
}
