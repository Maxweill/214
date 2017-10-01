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
//#include "mergesort.c"


int main(int argc, char **argv) {
	
	// ERROR CHECKING
	if(argc != 3){ //no or too many arguments
		printf("Invalid, input must contain 3 arguments.\n-> For example: ./sorter -c  movie_title\n");
		return 0;
	}
	
	char* col = argv[2]; //category/column that needs to be sorted
	int category = checkColumn(col);
	
	//char buffer[1000];
	char *buffer = malloc(1000);
	char *hold = buffer;
	int size = 128;
	int i = 0;
	
	fgets(buffer, 1000, stdin);
	
	struct movie* array = malloc(sizeof(struct movie) * size);
	
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
		
		/*
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
		*/

		//array[i] = *a;
		
		i++;
		buffer = hold;
	}
	
	// Printing to CSV
	int m = i;
	int n = 27;
	
	mergesort(array, category, i);
	
	printCSV(array, m, n);
	
	// Free
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

void printCSV(struct movie* array, int m, int n){
	
	/*
	FILE *fp;
	int i;
	char temp[] = "sortedmovies";
	char* filename = temp;
	
	filename = strcat(temp, ".csv");
	fp = fopen(filename, "w+");
	
	// Print column titles
	fprintf(fp, "color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes, actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");
	
	// Print each struct (each movie is 1 row with 28 columns)
	for(i = 0; i < m; i++){
		
		fprintf(fp, "%s,%s,%i,%i,%i,%i,%s,%i,%i,%s,%s,%s,%i,%i,%s,%i,%s,%s,%i,%s,%s,%s,%i,%i,%i,%f,%f,%i\n", array[i].color,array[i].director_name,array[i].num_critic_for_reviews,array[i].duration,array[i].director_facebook_likes,array[i].actor_3_facebook_likes,array[i].actor_2_name,array[i].actor_1_facebook_likes,array[i].gross,array[i].genres,array[i].actor_1_name,array[i].movie_title,array[i].num_voted_users,array[i].cast_total_facebook_likes,array[i].actor_3_name,array[i].facenumber_in_poster,array[i].plot_keywords,array[i].movie_imdb_link,array[i].num_user_for_reviews,array[i].language,array[i].country,array[i].content_rating,array[i].budget,array[i].title_year,array[i].actor_2_facebook_likes,array[i].imdb_score_num,array[i].aspect_ratio,array[i].movie_facebook_likes);
		
	}
	
	fclose(fp);
	*/
	
	int i;
	
	for(i = 0; i < m; i++){
		
		// Checks / Print Statements
		printf("------ Movie No: %i (i = %i) ------\n", i+1, i);
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
		
	}
	
}

int firstString(char * s1, char * s2){ //compares to strings alphabetically and returns the alphabetically first string
    if(strcmp(s1,s2)>0){    //this means s1 is alphabetically first
        return 0;  
    }else{          //this means that s2 was alphabetically first;
        return 1;
    }
}
 
void NUMmerge(struct movie* arr, int l, int m, int r, int colnum) {
	
	int i, j, k;
	int n1 = m - l + 1;     //size of left array
	int n2 =  r - m;    //size of right array
	
	struct movie * tempL = malloc(sizeof(struct movie)*n1);
	struct movie * tempR = malloc(sizeof(struct movie)*n2);
 
        for (i = 0; i < n1; i++){   //copy data to temp arrays
            tempL[i] = arr[l + i];
    }
        for (j = 0; j < n2; j++){
            tempR[j] = arr[m + 1 + j];
    }
   
        /* merge back into temp array*/
        i = 0; // first index of first subarray
        j = 0; // first index of second subarray
        k = l; // first index of merged subarray
 
    switch(colnum){
        case(0):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].color,tempR[j].color);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(1):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].director_name,tempR[j].director_name);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(2): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].num_critic_for_reviews <= tempR[j].num_critic_for_reviews){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(3)://INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].duration <= tempR[j].duration){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(4): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].director_facebook_likes <= tempR[j].director_facebook_likes){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(5): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].actor_3_facebook_likes <= tempR[j].actor_3_facebook_likes){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(6):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].actor_2_name,tempR[j].actor_2_name);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(7): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].actor_1_facebook_likes <= tempR[j].actor_1_facebook_likes){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(8): //FLOAT/DOUBLE
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].gross <= tempR[j].gross){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(9):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].genres,tempR[j].genres);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(10):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].actor_1_name,tempR[j].actor_1_name);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(11): //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].movie_title,tempR[j].movie_title);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(12): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].num_voted_users <= tempR[j].num_voted_users){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;     
        case(13): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].cast_total_facebook_likes <= tempR[j].cast_total_facebook_likes){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(14):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].actor_3_name,tempR[j].actor_3_name);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break; 
        case(15): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].facenumber_in_poster <= tempR[j].facenumber_in_poster){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(16):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].plot_keywords,tempR[j].plot_keywords);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break; 
        case(17):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].movie_imdb_link,tempR[j].movie_imdb_link);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;     
        case(18): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].num_user_for_reviews <= tempR[j].num_user_for_reviews){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break; 
        case(19):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].language,tempR[j].language);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;     
        case(20):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].country,tempR[j].country);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(21):
            //CHAR
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                int result = firstString(tempL[i].content_rating,tempR[j].content_rating);
                    if (result == 1){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(22): //FLOAT/DOUBLE
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].budget <= tempR[j].budget){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(23): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].title_year <= tempR[j].title_year){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(24): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].actor_2_facebook_likes <= tempR[j].actor_2_facebook_likes){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(25): //FLOAT/DOUBLE
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].imdb_score_num <= tempR[j].imdb_score_num){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(26): //FLOAT/DOUBLE
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].aspect_ratio <= tempR[j].aspect_ratio){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
        case(27): //INT
            while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
                    if (tempL[i].movie_facebook_likes <= tempR[j].movie_facebook_likes){
                            arr[k] = tempL[i]; 
                            i++;
                    }else{
                            arr[k] = tempR[j];
                            j++;
                    }
                    k++;
                }
            break;
    }
 
    /*
    //original white loop just here in case errors
        while (i < n1 && j < n2){ //sees if i or j is larger and puts the smallest one into temp
            if (tempL[i].movieFBlikes <= tempR[j].movieFBlikes){
                    arr[k] = tempL[i]; 
                    i++;
            }else{
                    arr[k] = tempR[j];
                    j++;
            }
            k++;
        }
    */
 
        //copy remaining elements of tempL[], if there are any
        while (i < n1){
            arr[k] = tempL[i];
            i++;
            k++;
        }
    //same thing but with tempR[]
        while (j < n2){
            arr[k] = tempR[j];
            j++;
            k++;
        }
}
 
void NUMmergeSorter(struct movie* arr, int l, int r , int colnum ){
	
        if (l < r){
            int m = l+(r-l)/2; //round down if m is a decimal (i.e 4.5 -> 4)
            // sort first and second halves
            NUMmergeSorter(arr, l, m,colnum);       //split the left sub arrays
            NUMmergeSorter(arr, m+1, r,colnum);     //split the right sub arrays
            NUMmerge(arr, l, m, r, colnum);         //compares two sub-arrays and sorts them in arr
        }
}

struct movie* mergesort(struct movie* records, int colnum, int size){ //splits array into arrays of one
	
	NUMmergeSorter(records, 0, size-1 ,colnum);
	
    return records;
}

int checkColumn(char* col){
	
	int colnum;
	
	if(strcmp(col,"color") == 0){
        colnum = 0;
    } else if(strcmp(col,"director_name")==0){
        colnum = 1;
    }else if(strcmp(col,"num_critic_for_reviews")==0){
        colnum = 2;
    }else if(strcmp(col,"duration")==0){
        colnum = 3;
    }else if(strcmp(col,"director_facebook_likes")==0){
        colnum = 4;
    }else if(strcmp(col,"actor_3_facebook_likes")==0){
        colnum = 5;
    }else if(strcmp(col,"actor_2_name")==0){
        colnum = 6;
    }else if(strcmp(col,"actor_1_facebook_likes")==0){
        colnum = 7;
    }else if(strcmp(col,"gross")==0){
        colnum = 8;
    }else if(strcmp(col,"genres")==0){
        colnum = 9;
    }else if(strcmp(col,"actor_1_name")==0){
        colnum = 10;
    }else if(strcmp(col,"movie_title")==0){
        colnum = 11;
    }else if(strcmp(col,"num_voted_users")==0){
        colnum = 12;
    }else if(strcmp(col,"cast_total_facebook_likes")==0){
        colnum = 13;
    }else if(strcmp(col,"actor_3_name")==0){
        colnum = 14;
    }else if(strcmp(col,"facenumber_in_poster")==0){
        colnum = 15;
    }else if(strcmp(col,"plot_keywords")==0){
        colnum = 16;
    }else if(strcmp(col,"movie_imdb_link")==0){
        colnum = 17;
    }else if(strcmp(col,"num_user_for_reviews")==0){
        colnum = 18;
    }else if(strcmp(col,"language")==0){
        colnum = 19;
    }else if(strcmp(col,"country")==0){
        colnum = 20;
    }else if(strcmp(col,"content_rating")==0){
        colnum = 21;
    }else if(strcmp(col,"budget")==0){
        colnum = 22;
    }else if(strcmp(col,"title_year")==0){
        colnum = 23;
    }else if(strcmp(col,"actor_2_facebook_likes")==0){
        colnum = 24;
    }else if(strcmp(col,"imdb_score")==0){
        colnum = 25;
    }else if(strcmp(col,"aspect_ratio")==0){
        colnum = 26;
    }else if(strcmp(col,"movie_facebook_likes")==0){
        colnum = 27;
    }
    
    return colnum;
	
}
