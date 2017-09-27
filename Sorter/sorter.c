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


int main(int argc, char **argv){
	
	//char buffer[1000];
	char *buffer = malloc(1000);
	char *hold=buffer;
	int size=128;
	int i = 0;
	fgets(buffer,1000,stdin);
	
	struct movie* array = malloc(sizeof(struct movie) * size);
	
	while(fgets(buffer, 1000, stdin)){
		//Array size increaser
		if (i==size-1)
		{
				printf("Wow, you entered a lot of stuff, we have to make our array bigger!");
				size=size*2;
				array=realloc(array,sizeof(struct movie) * size);
		}
		
		printf("Movie No: %i\n",i);
			char* token;
			//struct movie *a = malloc(sizeof(movie));
			//array[i] = *a;
			//STRING - color 
			token=strsep(&buffer,",");
				array[i].color=malloc(strlen(token)+1);
				strcpy(array[i].color,token);
			//STRING - director name 
			token=strsep(&buffer,",");
				array[i].director_name=malloc(strlen(token)+1);
				strcpy(array[i].director_name,token);
			//INT - number of critic review 
			token = strsep(&buffer,",");
				if(token[0] == '\0')
				{
				array[i].num_critic_for_reviews = -1;
				}
				else{
				array[i].num_critic_for_reviews = atoi(token);
				}
			//INT - duration
	array[i].duration=atoi(strsep(&buffer,","));
			//INT - director facebook likes
	array[i].director_facebook_likes=atoi(strsep(&buffer,","));
			//INT - actor 3 facebook likes
	array[i].actor_3_facebook_likes=atoi(strsep(&buffer,","));
			//STRING - actor 2 name
			token=strsep(&buffer,",");
				array[i].actor_2_name=malloc(strlen(token)+1);
				strcpy(array[i].actor_2_name,token);
			//INT - actor 1 facebook likes
	array[i].actor_1_facebook_likes=atoi(strsep(&buffer,","));
			//INT - gross
	array[i].gross=atoi(strsep(&buffer,","));
			//STRING - genres 
			token = strsep(&buffer,",");
				array[i].genres=malloc(strlen(token)+1);
				strcpy(array[i].genres,token);
			//STRING - actor 1 name
			token = strsep(&buffer,",");
				array[i].actor_1_name=malloc(strlen(token)+1);
				strcpy(array[i].actor_1_name,token);
			//STRING - movie title
			token = strsep(&buffer,"Â ");
				array[i].movie_title=malloc(strlen(token)+1);
				strcpy(array[i].movie_title,token);
				
				if(array[i].movie_title[0] =='\"'){
				free(array[i].movie_title);
				array[i].movie_title = malloc(strlen(token));
				strcpy(array[i].movie_title,token+1);
				}
			//skip
			strsep(&buffer,",");
			
			//INT - num_voted_users
	array[i].num_voted_users=atoi(strsep(&buffer,","));
			//INT - cast total facebook likes
	array[i].cast_total_facebook_likes=atoi(strsep(&buffer,","));
			//STRING - actor 3 name
			token = strsep(&buffer,",");
				array[i].actor_3_name=malloc(strlen(token)+1);
				strcpy(array[i].actor_3_name,token);
			//INT - facenumber_in_poster
	array[i].facenumber_in_poster=atoi(strsep(&buffer,","));
			//STRING - plot keywords
			token = strsep(&buffer,",");
				array[i].plot_keywords=malloc(strlen(token)+1);
				strcpy(array[i].plot_keywords,token);
			//STRING - movie imdb link
			token = strsep(&buffer,",");
				array[i].movie_imdb_link=malloc(strlen(token)+1);
				strcpy(array[i].movie_imdb_link,token);
			//INT - num user for reviews
	array[i].num_user_for_reviews=atoi(strsep(&buffer,","));
			//STRING
			token = strsep(&buffer,",");
			array[i].language=malloc(strlen(token)+1);
			strcpy(array[i].language, token);
			//STRING
			token = strsep(&buffer,",");
			array[i].country=malloc(strlen(token)+1);
			strcpy(array[i].country, token);
			//STRING
			token = strsep(&buffer,",");
			array[i].content_rating=malloc(strlen(token)+1);
			strcpy(array[i].content_rating,token);
			//INT
	array[i].budget=atoi(strsep(&buffer,","));
			//INT
	array[i].title_year=atoi(strsep(&buffer,","));
			//INT
	array[i].actor_2_facebook_likes=atoi(strsep(&buffer,","));
			//INT
	array[i].imdb_score_num=atoi(strsep(&buffer,","));
			//INT
	array[i].aspect_ratio=atoi(strsep(&buffer,","));
			//INT
	array[i].movie_facebook_likes=atoi(strsep(&buffer,","));
		
		
		printf("%s\n", array[i].movie_title);
		printf("%i\n", array[i].num_critic_for_reviews);
		printf("%s\n", array[i].country);
		
		//array[i] = *a;
		
		i++;
		
		buffer = hold;
	}
	
	
	int index;
	
	for(index = 0; index <= i; index++){
		free(array[index].color);
		free(array[index].director_name);
		free(array[index].actor_2_name);
		free(array[index].genres);
		free(array[index].actor_1_name);
		free(array[index].movie_title);
		free(array[index].actor_3_name);
		free(array[index].plot_keywords);
		free(array[index].movie_imdb_link);
		free(array[index].language);
		free(array[index].country);
		free(array[index].content_rating);
	}
	
	
	free(array);
	free(buffer);
	return 0;
}

