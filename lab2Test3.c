#include<stdio.h>         /* Standard C Library*/
#define students 40        /* Constant students*/
#define max_rating 10     /* Constant max_rating*/

int cafeteria_rating_array[students][1];   /* Declaration of 2D-Array */
int students_counter, total_rating;        /* Declaration of 2 variables called students_counter and total_rating*/
int frequency_array[max_rating][2];        /* Declaration of 2D-Array*/
int frequency_counter, frequency_count;    /* Declaration of 2 variables called frequency_counter and frequency_count*/
int i,j;                                   /* Declaration of 2 variables to be used in as part of the counter*/


int main(void)/* The main method*/
{
    printf("*************************************************************************** \n *                                                                        *\n *                   40 students are asked to rate the quality            *\n *                   of food in the student cafeteria on a scale          *\n *              of 1 to 10(1 means disgusting and 10 means excellent)     *\n *                   Place the 40 responses in an integer array and       *\n *                   summarise and display  the results of the poll       *\n *                                                                        *\n *************************************************************************/\n");
    printf("Please Rate The Quality Of Food In The Cafeteria On A Scale Of 1 To 10;\n1 Means Disgusting And 10 Means Excellent:\n\n");

    for(students_counter=0;students_counter<students;students_counter++)  /* Loop to ensure that the input is within range*/
    {
        do
        {   printf("Student no. %d :\t", students_counter+1);
            scanf("%d", &cafeteria_rating_array[students_counter][1]);
            if(cafeteria_rating_array[students_counter][1] < 1 || cafeteria_rating_array[students_counter][1] > max_rating ){printf("Please enter an valid. The range is between 1 and 10\n");}
        }
        while (cafeteria_rating_array[students_counter][1] < 1 || cafeteria_rating_array[students_counter][1] > max_rating );
            total_rating+=cafeteria_rating_array[students_counter][1];
    }


        printf( "\n\n"); /* Skip 2 lines*/

        for (students_counter=0;students_counter<students;students_counter++) /* Output of the data already in the cafeteria_rating_array*/
        { printf( "Student no. %d rated the cafeteria food %d/10\n", students_counter+1, cafeteria_rating_array[students_counter][ 1 ] );
        }

        for (frequency_counter=0;frequency_counter<max_rating;frequency_counter++)
        {   frequency_array[frequency_counter][0]=frequency_counter+1;
            frequency_count=0;

            for (students_counter=0;students_counter<students;students_counter++)
            {
                 if (cafeteria_rating_array[students_counter][ 1 ]==frequency_counter+1)
                {
                 frequency_count=frequency_count+1;
                }
            }
            frequency_array[frequency_counter][1]=frequency_count;

        }




        printf( "\nThe Average Rating is %.1f/10\n", (double)total_rating/students); /* Getting the average rating and its display*/

        printf("\nThe Poll Results are:\n");/* Output on the screen for poll results*/

        for ( i = 0; i <max_rating; i++ )   /* Output of poll results*/
            {	for ( j = 0; j < 2; j++ )
                {printf("%5d\t", frequency_array[i][j]);}
                 printf("\n");

            }



return 0;/* An indication that the program has run successfully */
}

