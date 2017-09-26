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

	int i = 0;
	fgets(buffer,1000,stdin);
	
	struct movie* array = (movie*)malloc(sizeof(struct movie) * 5048);
	
	while(fgets(buffer, 1000, stdin)){
		
		printf("hi\n");
		
		
			//struct movie *a = malloc(sizeof(movie));
			//array[i] = *a;
			array[i].color=strsep(&buffer,",");
			array[i].director_name=strsep(&buffer,",");
		
			char* token = strsep(&buffer,",");
			
		if(token[0] == '\0'){
			array[i].num_critic_for_reviews = -1;
		} else {
			array[i].num_critic_for_reviews = atoi(token);
		}
		
		array[i].duration=atoi(strsep(&buffer,","));
		
		array[i].director_facebook_likes=atoi(strsep(&buffer,","));
		array[i].actor_3_facebook_likes=atoi(strsep(&buffer,","));
		array[i].actor_2_name=strsep(&buffer,",");
		array[i].actor_1_facebook_likes=atoi(strsep(&buffer,","));
		array[i].gross=atoi(strsep(&buffer,","));
		array[i].genres=strsep(&buffer,",");
		array[i].actor_1_name=strsep(&buffer,",");


		array[i].movie_title=strsep(&buffer, "Â ");
			

		if(array[i].movie_title[0] =='\"'){
			array[i].movie_title = array[i].movie_title+1;
		}
		
		strsep(&buffer,",");
		
		array[i].num_voted_users=atoi(strsep(&buffer,","));
		array[i].cast_total_facebook_likes=atoi(strsep(&buffer,","));
		array[i].actor_3_name=strsep(&buffer,",");
		array[i].facenumber_in_poster=atoi(strsep(&buffer,","));
		array[i].plot_keywords=strsep(&buffer,",");
		array[i].movie_imdb_link=strsep(&buffer,",");
		array[i].num_user_for_reviews=atoi(strsep(&buffer,","));
		array[i].language=strsep(&buffer,",");
		array[i].country=strsep(&buffer,",");
		array[i].content_rating=strsep(&buffer,",");
		array[i].budget=atoi(strsep(&buffer,","));
		array[i].title_year=atoi(strsep(&buffer,","));
		array[i].actor_2_facebook_likes=atoi(strsep(&buffer,","));
		array[i].imdb_score_num=atoi(strsep(&buffer,","));
		array[i].aspect_ratio=atoi(strsep(&buffer,","));
		array[i].movie_facebook_likes=atoi(strsep(&buffer,","));
		
		
		printf("%s\n", array[i].movie_title);
		printf("%i\n", array[i].num_critic_for_reviews);
		printf("%s\n", array[i].country);
		
		//array[i] = *a;
		
		i++;
		
		
		printf("Movie No: %i\n",i);
		buffer = hold;
	}
	
	printf("%s\n",array[5000].movie_title);
	
	
	//int index = 0;
	
	/*for(index = 0; index < 2048; index++){
		free(&array[index]);
	}*/
	
	
	free(array);
	
	return 0;
}

