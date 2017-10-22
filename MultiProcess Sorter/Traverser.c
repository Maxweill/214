/*
 * Traverser.c
 * 
 * Copyright 2017 Maxwell Mucha <mem434@null.cs.rutgers.edu>
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


#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char **argv) {
	
	char* path = "/ilab/users/mem434/Documents/Testing Garbage/How to traverse ";
	recurseFileSystem(path);
	return 0;
}
	
	void recurseFileSystem(char *path)
{

    DIR *dir;
    struct dirent *str;
    dir = opendir(path);
    
    if ( dir != NULL) {
  
	str = readdir(dir);
		while (str != NULL) 
		{
			if((strcmp(str->d_name,"..") != 0) && (strcmp(str->d_name,".") != 0))
			{
				if(str->d_type == DT_DIR) //IT'S A DIRECTORY, DO RECURSION
				{
					char nextdir[1024];
					strcpy(nextdir, path);
					strcat(nextdir, "/");
					strcat(nextdir, str->d_name);
	
					recurseFileSystem(nextdir);
				}
				
				else // IT MUST BE A FILE, DO SORT STUFF
				{
						char* extension = strrchr(str->d_name,'.');
						if(extension!=NULL)
						{
							//printf ("%s\n", str->d_name); 
							//printf ("%s", extension);
							//printf("\n");
							char* mal = malloc(strlen(extension)*sizeof(char));
							strcpy(mal,extension);
							
							if(strcmp(mal,".csv")==0)							// ALL CSV FILES GO HERE
							{
									printf("%s is a .csv file\n",str->d_name);
									//do stuff
							}
							free(mal);						
						}
						
	
				}
			}
			str = readdir(dir);
		}
    closedir (dir);
	}
	
	return;
}



