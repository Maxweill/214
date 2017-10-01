/*
 * mergesort.c
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Sorter.h"
#include <stdio.h>

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
        
        free(tempL);
        free(tempR);
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

