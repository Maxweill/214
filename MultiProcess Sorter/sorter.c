/*
 * sorter.c
 * 
 * Authors: 
 * Ronak Gandhi
 * Maxwell Mucha
 * 
 * TODO LIST:
 * 1.) Error checking if directory path is incorrect/invalid
 * 2.) Get output directory working ("-o <output dir path>")
 * 3.) Giving proper output of project:
 * 			1.) Initial PID --> done
 * 			2.) PIDS of all child processes: AAA,BBB,CCC,DDD,EEE,FFF, etc --> done
 * 			3.) Total number of processes: ZZZZZ --> made global variable 'num_processes' but still working on it
 * 4.) Wrapping arguments that contain directory paths with quotes if they have space(s)??? (check piazza cause Tjang said that, but it makes no sense b/c space as input signals next argument)
 * 5.) Trying to figure out and fixing the few errors from our mergesort/sorter from Project 0 (use strcmp instead or try figuring out how to alphabetically sort) -> working on it
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mergesort.c"
#include "Sorter.h"
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int numchild;
char *sortname;	//Name of the file being sorted
char *sortpath;	//Path leading to the file being sorted
char *fullname;
char *category;
int num_processes;

int main(int argc, char **argv) {
	
	// Argument 2 -> category (e.g. "movie_title")
	if (argv[2] == '\0' || argv[2] == NULL){
		printf("ERROR: Invalid input, one or more arguments are null.\n");
		return -1;
	}
	
	char *input_dir; 
	char *output_dir;

	DIR *dir;
	char path[4096];
	num_processes = 0;
	
	// Case 1 - "./sorter -c movie_title"
	if(argc == 3){
		
		// Argument 1 -> "-c"
		if (strcmp(argv[1], "-c") != 0){
			printf("ERROR: Expected '-c' as first argument.\n");
			return -1;
		}
		
		// gets cwd, you'll need to change this so that it give you the correct starting directory with different inputs
		if(getcwd(path, sizeof(path)) != NULL){
			//printf("%s\n",path);
		} else {
			printf("Error with getcwd");
			return -1;
		}
		
		sortpath = path;
		dir = opendir(path);
	
	// Case 2 & 3 - "./sorter -c movie_title -d [full directory]" or "./sorter -c movie_title -d [local directory]"
	// 				"./sorter -c movie_title -d [full directory]" -o [full directory]"
	} else if(argc >= 5){
		
		// Argument 1 -> "-c"
		if (strcmp(argv[1], "-c") != 0){
			printf("ERROR: Expected '-c' as first argument.\n");
			return -1;
		}
		
		// Argument 3 -> "-d"
		if (strcmp(argv[3],"-d") != 0 || argv[3] == NULL){
			printf("ERROR: Expected '-d' as third argument.\n");
			return -1;
		}
		
		input_dir = argv[4];
		
		// remove slash at the end of directory
		//if(input_dir[strlen(input_dir) - 1] == '/'){
		//	input_dir[strlen(input_dir) - 1] = '\0';
		//}
		
		//printf("check: %s\n", input_dir);

		if(argc >= 6){
			
			// Argument 5 -> "-o"
			if (strcmp(argv[5],"-o") != 0){
				printf("ERROR: Expected '-o' as fifth argument.\n");
			return -1;
			}
			
			output_dir = argv[6];
		} 
		
		sortpath = input_dir;
		int p;
		for(p = 0; p < strlen(input_dir); p++){ //copy input directory to path
			path[p] = input_dir[p];
		}
		dir = opendir(path);
		
		//printf("directory: %s\n", path);

	} else {
		printf("error\n"); //other: arguments not valid -> will edit message later
		return -1;
	}
	
	printf("Initial PID: %d\n", getpid());
	printf("PIDS of all child processes: ");
	fflush(stdout);
	
	numchild = 0; 	// Number of children a process spawns
	//Directory and directory structure
    struct dirent *str;
    
    
    if ( dir != NULL) // null check for directory
    {
		str = readdir(dir); // reads the first thing in the directory
		for(;str != NULL; str = readdir(dir)) //for loop that goes through everything in the loop.
		{
			if((strcmp(str->d_name,"..") != 0) && (strcmp(str->d_name,".") != 0)) //checks for .  and .. directories
			{
				num_processes++;
				
				if(str->d_type == DT_DIR) // if its a directory
				{
					int pid = fork(); // fork here
					if(pid == 0) //if its a child
					{
						
						printf("%d, ", getpid());
						fflush(stdout);
						
						closedir(dir); //close the original directory
						strcat(path,"/"); //append the folder to the path
						strcat(path, str->d_name);
						//printf("%s\n",nextdir);
						dir = opendir(path);	//open the new directory
						numchild = 0;	//reset number of children			
					}
					else
					{
						numchild++; //increment number of children in parent
					}
					
				}
				else
				{
					char* extension = strrchr(str->d_name,'.'); // gets the extension of the file
					if(extension!=NULL)
					{
						if(strcmp(extension,".csv")==0)			// ALL CSV FILES GO HERE
						{
							int pid = fork(); // fork on here
							if(pid == 0) // if its  a child
							{
								
								printf("%d, ", getpid());
								fflush(stdout);
								numchild = 0; //reset number of children
								sortname = str->d_name; //set the name of the file
								sortpath = path; //set the path of the file
								break; //exit look
							}
							else
							{		
								numchild++; //increment number of children in parent
							}			
						}
					}
					
				}		
			}	
		}	
	}
	closedir(dir); //close whatever directory is open.
	
	//at this point every file and every directory has its own process

	int i;
	if(sortpath != NULL && sortname == NULL) // goes in here if its a directory fork.
	{
			for(i = numchild;i>0;i--) // wait for all the children that the directory spawned. 
									  //returns if a directory has no children, or finishes waiting
			{
				//printf("[%i] waiting on child #%i\n", getpid(),i);
				wait();
				//printf("[%i] wait [%i] complete\n",getpid(),i);
			}
		return 0;
	}	
	
	//printf("[%i] %s/%s\n",getpid(),sortpath,sortname);
	fullname = malloc(4096); //for some reason sortpath and sortname get corrupted
																//so if you want to use them for something else
																//you'll need to malloc them into a variable.
	fullname = strcpy(fullname, sortpath);
	fullname = strcat(fullname, "/");
	fullname = strcat(fullname, sortname); // Sets the full path name 
	
	
	
	//printf("[%i] %s\n",getpid() ,fullname);
	
	sort(argv);
	
	return 0;
	
} //end of 'main' function

void sort(char **argv){
	
	char* buffer = malloc(1000);
	char* hold = buffer;
	int size = 128;
	int i = 0;
	FILE* fp = fopen(fullname,"r");
	
	fgets(buffer, 1000, fp);

	//You'll need to edit the stuff below here to make sure the input path is the correct one.
	//Also you may need to fix the input error checking.
	//If you want to output to a different path you'll need to do something in printcsv
	//to write to the right output
	
	char *token = strsep(&buffer, ",");
	int isin = 0;
	
	while(token != NULL){
		//printf("%s\n",token);
		if(strcmp(token, argv[2]) == 0 || strcmp(argv[2], "movie_facebook_likes") == 0){	
			//printf("%s\n",token);
			isin = 1;
			break;
		}
		token = strsep(&buffer, ",");
	}
	
	if(isin == 0){ //argument does not match column category
		printf("ERROR: Malformed input.\n");
		return;
	}
	
	/*
	if(argv[3] != '\0'){ //extra argument
		printf("ERROR: Extra argument received.\n");
		return -1;
	}
	*/
	
	category = argv[2]; //category/column that needs to be sorted
	
	struct movie* array = malloc(sizeof(struct movie) * size);
	//printf("[%i] FILEPATH IS STILL\n %s/%s\n",getpid(),sortpath,sortname);
	while(fgets(buffer, 1000, fp)){
		
		//Array size increaser
		if (i == size-1){
			//printf("Wow, you entered a lot of stuff, we have to make our array bigger!\n");
			size = size * 2;
			array = realloc(array,sizeof(struct movie) * size);
		}
		
		char* token;
		//struct movie *a = malloc(sizeof(movie));
		//array[i] = *a;
		
		// 1) STRING - Color 
		token = strsep(&buffer, ",");
		trim(token); //remove trailing and leading spaces
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
			buffer = buffer + 1;
			token = strsep(&buffer, "\"");
			trim(token); //remove trailing and leading spaces
			array[i].movie_title = malloc(strlen(token));
			strcpy(array[i].movie_title, token);
			strsep(&buffer, ",");	
		} else {
			token = strsep(&buffer, ",");
			trim(token); //remove trailing and leading spaces
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
	
	int m = i;
	int n = 27;
	//printf("[%i] FILEPATH IS STILL\n %s/%s\n",getpid(),sortpath,sortname);
	mergesort(array, category, 0, (m - 1)); //MERGE SORT
	printCSV(array, m, n); //PRINT OUTPUT/SORTED ARRAY
	
	// Free malloc'd fields/variables
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
	
	free(fullname);
	free(array);
	free(buffer);
	
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
	
} //end of 'trim' function

//fullname
void printCSV(struct movie* array, int m, int n) {
	
	FILE *fp2;
	int i;
	//you wont be able to use
	
	
	char*extension = strrchr(fullname,'.'); //properly formats the name of the output file
	strcpy(extension,"-sorted-");
	strcat(extension,category);
	strcat(extension,".csv");
	//printf("%s\n",fullname);
	//char* filename = name;
	//filename = strcat(name, ".csv");
	fp2 = fopen(fullname, "w+");
	
	// Print column titles
	fprintf(fp2, "color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes, actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");
	//fprintf(stdout, "color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes, actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");
	
	// Print each struct (each movie is 1 row with 28 columns)
	for(i = 0; i < m; i++){
		
		if(strchr(array[i].movie_title, ',')){
			fprintf(fp2, "%s,%s,%i,%i,%i,%i,%s,%i,%i,%s,%s,\"%s\",%i,%i,%s,%i,%s,%s,%i,%s,%s,%s,%i,%i,%i,%f,%f,%i\n", array[i].color,array[i].director_name,array[i].num_critic_for_reviews,array[i].duration,array[i].director_facebook_likes,array[i].actor_3_facebook_likes,array[i].actor_2_name,array[i].actor_1_facebook_likes,array[i].gross,array[i].genres,array[i].actor_1_name,array[i].movie_title,array[i].num_voted_users,array[i].cast_total_facebook_likes,array[i].actor_3_name,array[i].facenumber_in_poster,array[i].plot_keywords,array[i].movie_imdb_link,array[i].num_user_for_reviews,array[i].language,array[i].country,array[i].content_rating,array[i].budget,array[i].title_year,array[i].actor_2_facebook_likes,array[i].imdb_score_num,array[i].aspect_ratio,array[i].movie_facebook_likes);	
			//fprintf(stdout, "%s,%s,%i,%i,%i,%i,%s,%i,%i,%s,%s,\"%s\",%i,%i,%s,%i,%s,%s,%i,%s,%s,%s,%i,%i,%i,%f,%f,%i\n", array[i].color,array[i].director_name,array[i].num_critic_for_reviews,array[i].duration,array[i].director_facebook_likes,array[i].actor_3_facebook_likes,array[i].actor_2_name,array[i].actor_1_facebook_likes,array[i].gross,array[i].genres,array[i].actor_1_name,array[i].movie_title,array[i].num_voted_users,array[i].cast_total_facebook_likes,array[i].actor_3_name,array[i].facenumber_in_poster,array[i].plot_keywords,array[i].movie_imdb_link,array[i].num_user_for_reviews,array[i].language,array[i].country,array[i].content_rating,array[i].budget,array[i].title_year,array[i].actor_2_facebook_likes,array[i].imdb_score_num,array[i].aspect_ratio,array[i].movie_facebook_likes);		
		} else {
			fprintf(fp2, "%s,%s,%i,%i,%i,%i,%s,%i,%i,%s,%s,%s,%i,%i,%s,%i,%s,%s,%i,%s,%s,%s,%i,%i,%i,%f,%f,%i\n", array[i].color,array[i].director_name,array[i].num_critic_for_reviews,array[i].duration,array[i].director_facebook_likes,array[i].actor_3_facebook_likes,array[i].actor_2_name,array[i].actor_1_facebook_likes,array[i].gross,array[i].genres,array[i].actor_1_name,array[i].movie_title,array[i].num_voted_users,array[i].cast_total_facebook_likes,array[i].actor_3_name,array[i].facenumber_in_poster,array[i].plot_keywords,array[i].movie_imdb_link,array[i].num_user_for_reviews,array[i].language,array[i].country,array[i].content_rating,array[i].budget,array[i].title_year,array[i].actor_2_facebook_likes,array[i].imdb_score_num,array[i].aspect_ratio,array[i].movie_facebook_likes);
			//fprintf(stdout, "%s,%s,%i,%i,%i,%i,%s,%i,%i,%s,%s,%s,%i,%i,%s,%i,%s,%s,%i,%s,%s,%s,%i,%i,%i,%f,%f,%i\n", array[i].color,array[i].director_name,array[i].num_critic_for_reviews,array[i].duration,array[i].director_facebook_likes,array[i].actor_3_facebook_likes,array[i].actor_2_name,array[i].actor_1_facebook_likes,array[i].gross,array[i].genres,array[i].actor_1_name,array[i].movie_title,array[i].num_voted_users,array[i].cast_total_facebook_likes,array[i].actor_3_name,array[i].facenumber_in_poster,array[i].plot_keywords,array[i].movie_imdb_link,array[i].num_user_for_reviews,array[i].language,array[i].country,array[i].content_rating,array[i].budget,array[i].title_year,array[i].actor_2_facebook_likes,array[i].imdb_score_num,array[i].aspect_ratio,array[i].movie_facebook_likes);
		}
		
		
	}
	//printf("[%i] FILEPATH IS STILL\n %s/%s\n",getpid(),sortpath,sortname);
	//fclose(fp);
	
	
	//for(i = 0; i < m; i++){
		
		// Checks / Print Statements
		//printf("------ Movie No: %i (i = %i) ------\n", i+1, i);
		//printf("%s\n", array[i].director_name);
		//printf("%i\n", array[i].num_critic_for_reviews);
		//printf("%i\n", array[i].duration);
		//printf("%i\n", array[i].director_facebook_likes);
		//printf("%i\n", array[i].actor_3_facebook_likes);
		//printf("%s\n", array[i].actor_2_name);
		//printf("%i\n", array[i].actor_1_facebook_likes);
		//printf("%i\n", array[i].gross);
		//printf("%s\n", array[i].genres);
		//printf("%s\n", array[i].actor_1_name);
		//printf("%s\n", array[i].movie_title);
		//printf("%i\n", array[i].num_voted_users);
		//printf("%i\n", array[i].cast_total_facebook_likes);
		//printf("%s\n", array[i].actor_3_name);
		//printf("%i\n", array[i].facenumber_in_poster);
		//printf("%s\n", array[i].plot_keywords);
		//printf("%s\n", array[i].movie_imdb_link);
		//printf("%i\n", array[i].num_user_for_reviews);
		//printf("%s\n", array[i].language);
		//printf("%s\n", array[i].country);
		//printf("%s\n", array[i].content_rating);
		//printf("%i\n", array[i].budget);
		//printf("%i\n", array[i].title_year);
		//printf("%i\n", array[i].actor_2_facebook_likes);
		//printf("%f\n", array[i].imdb_score_num);
		//printf("%f\n", array[i].aspect_ratio);
		//printf("%i\n", array[i].movie_facebook_likes);
		
	//}
	
	
} //end of 'printCSV' function
