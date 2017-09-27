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


int main(int argc, char **argv) {
	
	//char buffer[1000];
	char *buffer = malloc(1000);
	char *hold=buffer;
	int size=128;
	int i = 0;
	
	fgets(buffer,1000,stdin);
	
	struct movie* array = malloc(sizeof(struct movie) * size);
	
	while(fgets(buffer, 1000, stdin)){
		
		//Array size increaser
		if (i == size-1){
			printf("Wow, you entered a lot of stuff, we have to make our array bigger!\n");
			size = size*2;
			array = realloc(array,sizeof(struct movie) * size);
		}
		
		//printf("Movie No: %i\n",i);
		char* token;
		//struct movie *a = malloc(sizeof(movie));
		//array[i] = *a;
		
		// 1) STRING - Color 
		token = strsep(&buffer,",");
		array[i].color = malloc(strlen(token) + 1);
		strcpy(array[i].color,token);

		// 2) STRING - Director Name 
		token = strsep(&buffer, ",");
		array[i].director_name=malloc(strlen(token) + 1);
		strcpy(array[i].director_name,token);
		
		// 3) INT - Number of critic review 
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].num_critic_for_reviews = -1;
		} else {
			array[i].num_critic_for_reviews = atoi(token);
		}
		
		// 4) INT - Duration
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].duration = -1;
		} else {
			array[i].duration = atoi(token);
		}
		
		// 5) INT - Director facebook likes
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].director_facebook_likes = -1;
		} else {
			array[i].director_facebook_likes = atoi(token);
		}
		
		// 6) INT - Actor 3 facebook likes
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].actor_3_facebook_likes = -1;
		} else {
			array[i].actor_3_facebook_likes = atoi(token);
		}
		
		// 7) STRING - Actor 2 name
		token = strsep(&buffer,",");
		array[i].actor_2_name=malloc(strlen(token)+1);
		strcpy(array[i].actor_2_name,token);
		
		// 8) INT - actor 1 facebook likes
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].actor_1_facebook_likes = -1;
		} else {
			array[i].actor_1_facebook_likes = atoi(token);
		}
		
		// 9) INT - Gross
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].gross = -1;
		} else {
			array[i].gross = atoi(token);
		}
		
		// 10) STRING - Genres 
		token = strsep(&buffer,",");
		array[i].genres=malloc(strlen(token) + 1);
		strcpy(array[i].genres,token);
		
		// 11) STRING - Actor 1 name
		token = strsep(&buffer,",");
		array[i].actor_1_name=malloc(strlen(token)+1);
		strcpy(array[i].actor_1_name,token);
		
		// 12) STRING - Movie title
		token = strsep(&buffer,"Â ");
		array[i].movie_title=malloc(strlen(token)+1);
		strcpy(array[i].movie_title,token);
		
		if(array[i].movie_title[0] =='\"'){
			free(array[i].movie_title);
			array[i].movie_title = malloc(strlen(token));
			strcpy(array[i].movie_title,token+1);
		}
		
		//skip
		strsep(&buffer, ",");
			
		// 13) INT - Num_voted_users
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].num_voted_users = -1;
		} else {
			array[i].num_voted_users = atoi(token);
		}
		
				// 14) INT - cast total facebook likes
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].cast_total_facebook_likes = -1;
		} else {
			array[i].cast_total_facebook_likes = atoi(token);
		}
		
		// 15) STRING - actor 3 name
		token = strsep(&buffer, ",");
		array[i].actor_3_name=malloc(strlen(token)+1);
		strcpy(array[i].actor_3_name,token);
		
		// 16) INT - facenumber_in_poster
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].facenumber_in_poster = -1;
		} else {
			array[i].facenumber_in_poster = atoi(token);
		}
		
		// 17) STRING - plot keywords
		token = strsep(&buffer,",");
		array[i].plot_keywords=malloc(strlen(token)+1);
		strcpy(array[i].plot_keywords,token);
		
		// 18) STRING - movie imdb link
		token = strsep(&buffer,",");
		array[i].movie_imdb_link=malloc(strlen(token)+1);
		strcpy(array[i].movie_imdb_link,token);
		
		// 19) INT - num user for reviews
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].num_user_for_reviews = -1;
		} else {
			array[i].num_user_for_reviews = atoi(token);
		}
		
		// 20) STRING
		token = strsep(&buffer,",");
		array[i].language=malloc(strlen(token)+1);
		strcpy(array[i].language, token);
		
		// 21) STRING
		token = strsep(&buffer,",");
		array[i].country=malloc(strlen(token)+1);
		strcpy(array[i].country, token);
		
		// 22) STRING
		token = strsep(&buffer,",");
		array[i].content_rating=malloc(strlen(token)+1);
		strcpy(array[i].content_rating,token);
		
		// 23) INT
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].budget = -1;
		} else {
			array[i].budget = atoi(token);
		}
		
		// 24) INT
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].title_year = -1;
		} else {
			array[i].title_year = atoi(token);
		}
		
		//25) INT
		token = strsep(&buffer,",");
		if(token[0] == '\0'){
			array[i].actor_2_facebook_likes = -1;
		} else {
			array[i].actor_2_facebook_likes = atoi(token);
		}
		
		// 26) DOUBLE
		token = strsep(&buffer, ",");
		char* temp;
		if(token[0] == '\0'){
			array[i].imdb_score_num = -1;
		} else {
			array[i].imdb_score_num = strtod(token, &temp);
		}
		
		// 27) DOUBLE
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].aspect_ratio = -1;
		} else {
			array[i].aspect_ratio = strtod(token, &temp);
		}
		
		// 28) INT
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].movie_facebook_likes = -1;
		} else {
			array[i].movie_facebook_likes = atoi(token);
		}
		
		// Checks / Print Statements
		printf("------ Movie No: %i ------\n", i);
		printf("%s\n", array[i].color);
		printf("%s\n", array[i].director_name);
		printf("%i\n", array[i].num_critic_for_reviews);
		printf("%i\n", array[i].duration);
		printf("%i\n", array[i].director_facebook_likes);
		printf("%i\n", array[i].actor_3_facebook_likes);
		printf("%s\n", array[i].actor_2_name);
		printf("%i\n", array[i].actor_1_facebook_likes);
		printf("%i\n", array[i].gross);
		printf("%s\n", array[i].genres);
		printf("%s\n", array[i].actor_1_name);
		printf("%s\n", array[i].movie_title);
		printf("%i\n", array[i].num_voted_users);
		printf("%i\n", array[i].cast_total_facebook_likes);
		printf("%s\n", array[i].actor_3_name);
		printf("%i\n", array[i].facenumber_in_poster);
		printf("%s\n", array[i].plot_keywords);
		printf("%s\n", array[i].movie_imdb_link);
		printf("%i\n", array[i].num_user_for_reviews);
		printf("%s\n", array[i].language);
		printf("%s\n", array[i].country);
		printf("%s\n", array[i].content_rating);
		printf("%i\n", array[i].budget);
		printf("%i\n", array[i].title_year);
		printf("%i\n", array[i].actor_2_facebook_likes);
		printf("%f\n", array[i].imdb_score_num);
		printf("%f\n", array[i].aspect_ratio);
		printf("%i\n", array[i].movie_facebook_likes);
		
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

