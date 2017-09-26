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
#include <ctype.h>
#include "Sorter.h"

int main(int argc, char **argv)
{
	
	char *buffer = malloc(1000);
	fgets(buffer,1000,stdin);
	
	/*while(fgets(buffer, 1000, stdin)){
		
		printf("%s", buffer);
		

		
	}*/
	
	fgets(buffer,1000,stdin);
	struct movie *a = malloc(sizeof(movie));
	
	char* temp;
	a->color=strsep(&buffer,",");
	a->director_name=strsep(&buffer,",");
	
	temp = strsep(&buffer,",");
	//printf("%s, %c",temp, temp[0]);
	a->num_critic_for_reviews = isdigit(temp[0]) ? atoi(temp) : -1;
	 
	temp = strsep(&buffer,",");
	a->duration = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->director_facebook_likes = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->actor_3_facebook_likes = isdigit(temp[0]) ? atoi(temp) : -1;
	
	a->actor_2_name=strsep(&buffer,",");
	
	temp = strsep(&buffer,",");
	a->actor_1_facebook_likes = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->gross = isdigit(temp[0]) ? atoi(temp) : -1;
	
	
	a->genres=strsep(&buffer,",");
	a->actor_1_name=strsep(&buffer,",");
	a->movie_title=strsep(&buffer,"Â ");
	if(a->movie_title[0] =='\"')
	{a->movie_title=a->movie_title+1;}
	strsep(&buffer,",");
	
	
	temp = strsep(&buffer,",");
	a->num_voted_users = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->cast_total_facebook_likes = isdigit(temp[0]) ? atoi(temp) : -1;
	
	a->actor_3_name=strsep(&buffer,",");
	
	temp = strsep(&buffer,",");
	a->facenumber_in_poster = isdigit(temp[0]) ? atoi(temp) : -1;
	
	a->plot_keywords=strsep(&buffer,",");
	
	a->movie_imdb_link=strsep(&buffer,",");
	
	temp = strsep(&buffer,",");
	a->num_user_for_reviews = isdigit(temp[0]) ? atoi(temp) : -1;
	
	a->language=strsep(&buffer,",");
	
	a->country=strsep(&buffer,",");
	
	a->content_rating=strsep(&buffer,",");
	
	temp = strsep(&buffer,",");
	a->budget = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->title_year = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->actor_2_facebook_likes = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->imdb_score_num = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->aspect_ratio = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->movie_facebook_likes = isdigit(temp[0]) ? atoi(temp) : -1;
	
	temp = strsep(&buffer,",");
	a->movie_facebook_likes = isdigit(temp[0]) ? atoi(temp) : -1;
	
	
	
	//printf("%s\n",a->movie_title);
	
	//printf("%i\n",a->num_voted_users);
	
	return 0;
}

