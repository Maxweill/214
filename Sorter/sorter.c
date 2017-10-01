/*
 * sorter.c
 * 
 * Authors: 
 * Ronak Gandhi
 * Maxwell Mucha
 * 
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Sorter.h"


int main(int argc, char **argv) {
	char *buffer = malloc(1000);
	char *hold = buffer;
	int size = 128;
	int i = 0;
	
	fgets(buffer, 1000, stdin);
	
	//char buffer[1000];
	if (argv[1][0] != '-' || argv[1][1] != 'c')
	{
		printf("ERROR:Expected '-c' as first argument.\n");
		return -1;
	}
	if (argv[2] == '\0')
	{
		printf("ERROR:Invalid input, one or more arguments are null.\n");
		return -1;
	}
	char *token;
	token = strsep(&buffer, ",");
	int isin=0;
	while(token!=NULL)
	{
			if(strcmp(token,argv[2])==0)
			{
				printf("We got a match!\n");
				isin=1;
			}
			token = strsep(&buffer, ",");
	}
	if (isin==0)
	{
		printf("ERROR:Malformed input.\n");
		return -1;
	}
	if (argv[3] != '\0')
	{
		printf("ERROR:Extra argument received.\n");
		return -1;
	}
	
	
	struct movie* array = malloc(sizeof(struct movie) * size);
	buffer = hold;
	while(fgets(buffer, 1000, stdin)){
		
		//Array size increaser
		if (i == size-1){
			//printf("Wow, you entered a lot of stuff, we have to make our array bigger!\n");
			size = size*2;
			array = realloc(array,sizeof(struct movie) * size);
		}
		
		//printf("Movie No: %i\n",i);
		char* token;
		//struct movie *a = malloc(sizeof(movie));
		//array[i] = *a;
		
		// 1) STRING - Color 
		token = strsep(&buffer, ",");
		trim(token);
		array[i].color = malloc(strlen(token) + 1);
		strcpy(array[i].color, token);

		// 2) STRING - Director Name 
		token = strsep(&buffer, ",");
		array[i].director_name=malloc(strlen(token) + 1);
		strcpy(array[i].director_name, token);
		
		// 3) INT - Number of critic review 
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].num_critic_for_reviews = -1;
		} else {
			array[i].num_critic_for_reviews = atoi(token);
		}
		
		// 4) INT - Duration
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].duration = -1;
		} else {
			array[i].duration = atoi(token);
		}
		
		// 5) INT - Director facebook likes
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].director_facebook_likes = -1;
		} else {
			array[i].director_facebook_likes = atoi(token);
		}
		
		// 6) INT - Actor 3 facebook likes
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].actor_3_facebook_likes = -1;
		} else {
			array[i].actor_3_facebook_likes = atoi(token);
		}
		
		// 7) STRING - Actor 2 name
		token = strsep(&buffer, ",");
		array[i].actor_2_name = malloc(strlen(token) + 1);
		strcpy(array[i].actor_2_name, token);
		
		// 8) INT - Actor 1 facebook likes
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].actor_1_facebook_likes = -1;
		} else {
			array[i].actor_1_facebook_likes = atoi(token);
		}
		
		// 9) INT - Gross
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].gross = -1;
		} else {
			array[i].gross = atoi(token);
		}
		
		// 10) STRING - Genres 
		token = strsep(&buffer, ",");
		array[i].genres=malloc(strlen(token) + 1);
		strcpy(array[i].genres, token);
		
		// 11) STRING - Actor 1 name
		token = strsep(&buffer, ",");
		array[i].actor_1_name = malloc(strlen(token) + 1);
		strcpy(array[i].actor_1_name, token);
		
		// 12) STRING - Movie title
		if(buffer[0]=='\"'){
			buffer = buffer+1;
			token = strsep(&buffer, "\"");
			trim(token);
			array[i].movie_title = malloc(strlen(token));
			strcpy(array[i].movie_title, token);
			strsep(&buffer, ",");	
		} else {
			token = strsep(&buffer, ",");
			trim(token);
			array[i].movie_title = malloc(strlen(token) + 1);
			strcpy(array[i].movie_title, token);
		}
		
		// 13) INT - Num_voted_users
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].num_voted_users = -1;
		} else {
			array[i].num_voted_users = atoi(token);
		}
		
		// 14) INT - Cast total facebook likes
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].cast_total_facebook_likes = -1;
		} else {
			array[i].cast_total_facebook_likes = atoi(token);
		}
		
		// 15) STRING - Actor 3 name
		token = strsep(&buffer, ",");
		array[i].actor_3_name = malloc(strlen(token) + 1);
		strcpy(array[i].actor_3_name,token);
		
		// 16) INT - Facenumber_in_poster
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].facenumber_in_poster = -1;
		} else {
			array[i].facenumber_in_poster = atoi(token);
		}
		
		// 17) STRING - plot keywords
		token = strsep(&buffer, ",");
		array[i].plot_keywords = malloc(strlen(token) + 1);
		strcpy(array[i].plot_keywords,token);
		
		// 18) STRING - Movie imdb link
		token = strsep(&buffer, ",");
		array[i].movie_imdb_link = malloc(strlen(token) + 1);
		strcpy(array[i].movie_imdb_link,token);
		
		// 19) INT - Num user for reviews
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].num_user_for_reviews = -1;
		} else {
			array[i].num_user_for_reviews = atoi(token);
		}
		
		// 20) STRING - Language
		token = strsep(&buffer, ",");
		array[i].language = malloc(strlen(token) + 1);
		strcpy(array[i].language, token);
		
		// 21) STRING - Country
		token = strsep(&buffer, ",");
		array[i].country = malloc(strlen(token) + 1);
		strcpy(array[i].country, token);
		
		// 22) STRING - Content Rating
		token = strsep(&buffer, ",");
		array[i].content_rating = malloc(strlen(token) + 1);
		strcpy(array[i].content_rating,token);
		
		// 23) INT - Budget
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].budget = -1;
		} else {
			array[i].budget = atoi(token);
		}
		
		// 24) INT - Title Year
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].title_year = -1;
		} else {
			array[i].title_year = atoi(token);
		}
		
		//25) INT - Actor 2 Facebook Likes
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].actor_2_facebook_likes = -1;
		} else {
			array[i].actor_2_facebook_likes = atoi(token);
		}
		
		// 26) DOUBLE - IMDB Score Num
		char* temp;
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].imdb_score_num = -1;
		} else {
			array[i].imdb_score_num = strtod(token, &temp);
		}
		
		// 27) DOUBLE - Aspect Ratio
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].aspect_ratio = -1;
		} else {
			array[i].aspect_ratio = strtod(token, &temp);
		}
		
		// 28) INT - Movie Facebook Likes
		token = strsep(&buffer, ",");
		if(token[0] == '\0'){
			array[i].movie_facebook_likes = -1;
		} else {
			array[i].movie_facebook_likes = atoi(token);
		}
	
		// Checks / Print Statements
		/*
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
		*/
		//array[i] = *a;
		
		i++;
		buffer = hold;
	}
		printf("Ready to mergesort by: %s\n",argv[2]);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
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

void trim(char* token) {
	
	if(token[0] == ' '){ //leading white spaces
		
		int i, j;
		for(i = 0; token[i] == ' '; i++);
		
		for(j = 0; token[i+j] != '\0'; j++){
			token[j] = token[i+j];
		}
		
		token[j] = '\0';
		
	} 
	
	if(token[strlen(token)] == ' ' || token[strlen(token)] == '\0'){ //trailing white spaces
		
		int i = strlen(token);
		
		while(token[i] == ' ' || token[i] == '\0'){
			i--;
		}
		
		token[i + 1] = '\0';
		
	}
	
}
