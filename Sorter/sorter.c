/*
 * sorter.c
 * 
 * Copyright 2017 Ronak J. Gandhi <rjg184@utility.cs.rutgers.edu>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Sorter.h"

int main(int argc, char **argv)
{
	
	char buffer[1000];
	fgets(buffer,1000,stdin);
	
	/*while(fgets(buffer, 1000, stdin)){
		
		printf("%s", buffer);
		

		
	}*/
	fgets(buffer,1000,stdin);
	struct movie *a = malloc(sizeof(movie));
	a->color=strtok(buffer,",");
	a->director_name=strtok(NULL,",");
	a->num_critic_for_reviews=atoi(strtok(NULL,","));
	a->duration=atoi(strtok(NULL,","));
	a->director_facebook_likes=atoi(strtok(NULL,","));
	a->actor_3_facebook_likes=atoi(strtok(NULL,","));
	a->actor_2_name=strtok(NULL,",");
	a->actor_1_facebook_likes=atoi(strtok(NULL,","));
	a->gross=atoi(strtok(NULL,","));
	a->genres=strtok(NULL,",");
	a->actor_1_name=strtok(NULL,",");
	a->movie_title=strtok(NULL,"Â ");
	if(a->movie_title[0] =='\"')
	{a->movie_title=a->movie_title+1;}
	strtok(NULL,",");
	a->num_voted_users=atoi(strtok(NULL,","));
	a->cast_total_facebook_likes=atoi(strtok(NULL,","));
	a->actor_3_name=strtok(NULL,",");
	a->facenumber_in_poster=atoi(strtok(NULL,","));
	a->plot_keywords=strtok(NULL,",");
	a->movie_imdb_link=strtok(NULL,",");
	a->num_user_for_reviews=atoi(strtok(NULL,","));
	a->language=strtok(NULL,",");
	a->country=strtok(NULL,",");
	a->content_rating=strtok(NULL,",");
	a->budget=atoi(strtok(NULL,","));
	a->title_year=atoi(strtok(NULL,","));
	a->actor_2_facebook_likes=atoi(strtok(NULL,","));
	a->imdb_score_num=atoi(strtok(NULL,","));
	a->aspect_ratio=atoi(strtok(NULL,","));
	a->movie_facebook_likes=atoi(strtok(NULL,","));
	
	
	printf("%s\n",a->movie_title);
	printf("%i\n",a->num_voted_users);
	
	return 0;
}

