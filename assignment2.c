/* This is a program to play the national lottery game. A set of options is  diplayed to user , each option is a function performing a specific task. If the user selects option 1, the program allows the user to enter
their 6 choosen lotto numbers. The user can then select option 2 for the program to display the choosen numbers and option 3 for the program to sort the numbers in ascending order. Option 4 then compares
the user's numbers to the winning numbers stored in an array . The frequency of each entered number is displayed in option 5 and opton 6 ends the program .

Author: Ashley Fitzgerald C15406208
Date: 27/02/16
Submission date: 06/03/16   11.59pm
*/


#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
#define BONUS 42

//Declare my prototypes

int option1(int *);
void option2(int *);
void option3(int *);
void option4(int*,int*);
void option5(int*);




//Start of main
main()
{
    
    //Declaring all of my vairables.
    
    int winning_array[SIZE]={1,3,5,7,9,11};
    int choice;
    int user_array[SIZE];
    int counter=0;
    
    
    //This statement is out of the loop so it displays at the start and doesnt keep displaying after each option is choosen
    printf("Welcome to the national lottery\n\n");
    do
    {
        
        //Each option is listed for the user.
        printf("Main menu:\n\n");
        
        printf("\nOption 1: Enter your 6 lotto numbers\n");
        
        printf("\nOption 2: Display choosen numbers\n");
        
        printf("\nOption 3: Sort numbers in ascending order\n");
        
        printf("\nOption 4: Compare numbers to winning numbers\n");
        
        printf("\nOption 5: Check frequency of each number entered\n");
        
        printf("\nOption 6: End the game\n\n");
        
        printf("Please select which option you would like:\n");
        
        
        //When the user selects one of these options it's stored in the variable called choice.
        scanf("%d", &choice);
        
        
        //When the user selects an option, the program jumps into this switch statement based on the number the user selected and calls the relevant function.
        switch(choice)
        {
            case 1:
                
            {
                
                printf("Please Enter your 6 numbers\n");
                

                //Call option1()  to read in the  user's  6  lotto numbers. When the user selects 1, option 1 is called. returning counter value back to main
                counter = option1(user_array);
                if(counter>1)
                {
                    printf("Thank you for entering your numbers!\n");
                }
                break;
                
            }//end case 1
            
            
            case 2:
            {
                
                //If the counter is greater than 1, the user has completed option1. i.e if the users numbers are in range the counter will increment also if no duplicates the counter will incrememnt. Hence if the counter is greater than 1, allow access to other options.
                if(counter>1)
                {
                    //Call option2() To display the numbers the user choose.
                    option2(user_array);
                }
                
                else
                {
                    printf("Error! You must do option1 first\n");
                }
                break;
                
            }//end case 2 
            
            
                
            case 3:
            {
                
                //To ensure the user has completed option 1
                if(counter>1)
                {
                    //calloption3() To sort the users number in ascending order.
                    option3(user_array);
                }
                
                else
                {
                    printf("Error! You must do option 1 first\n");
                }
                
                break;
                
            }//end case 3
            
            
            case 4:
            {
                
                //To ensure the user has completed option 1
                if(counter>1)
                {
                    //Call option 4() To compare the users numbers to the winning numbers
                    option4(user_array,winning_array);
                }
                
                else
                {
                    printf("Error! You must do option1 first\n");
                }
                break;
                
            }//end case 4
            
            
            case 5:
            {
                
                //To ensure the user has completed option 1
                if(counter>1)
                {
                    //Call option 5() To display the frequency of the users numbers
                    option5(user_array);
                }
                
                else
                {
                    printf("Error! You must do option 1 first\n");
                }
                break;
                
            }//end case 5
            
            
            case 6:
            {
                
                //To exit the program
                exit(0);
                
                
            }//end case 6
            
            default:
            {
                
                //If the user hasn't selected any valid options from the menu, this message will be displayed.
                printf("Sorry that is not a valid option");
                break;
            }
                
                
        }//end switch

        
    } while(choice==1||2||3||4||5||6);
    
    getchar();
    getchar();
}//end main

    //Implement option1()
    
    int option1(int *user_array)
    {
        
        int i,j;
        
        //This varialble will be ruturned to main to allow or block access to other options
        int counter=0;
        
        //If there are dublicates, this counter will incrememnt
        int num=0;
        
        //If the number is out of range, this counter will incremement
        int invalid=0;
    
    
        
        //Scan numbers into the array
        for(i=0; i<SIZE; i++)
        {
            scanf("%d",user_array+i);
        }
    
    
        //Check if any of the numbers are greater than 42 or less than 1
        for(i=0; i<SIZE; i++)
        {
            if(*(user_array+i) > 42 || *(user_array+i) < 0)
            {
                invalid++;
            }
        }
        
        //Check if there are any duplicates
        for(i=0; i<SIZE; i++)
        {
            for(j=0; j<SIZE; j++)
            {
            
                //This compares each to number in the array to everyother number. It loops around 36 timese cause  it compares each number against eachother.
                if(user_array[i] == user_array[j])
                {
                  num++;
                }
            }
        }
    
    
        //Check if any of nums out of range are out of range. If invalid is greater than 0, the numbers the user entered are out of range
        if (invalid > 0)
        {
            
            printf("Sorry you cannot use numbers greater than 42 and less than 0. Try again\n");
            
            
            //If the numbers are out of range, here i am reinitialising the users array to 0
             for ( i = 0 ; i < SIZE ; i++ )
            {
                * ( user_array + i ) = 0 ;
            }
        
        }

        else
        {
            //If the numbers are in range, increment a counter by 1.
            counter++;
        }
    
        //If the numbers were the same, a variable called num was incremeted. If num is greater than 6 (6 would be perfect input) then the user has entered in duplicate numbers.
        if(num > 6)
        {
            
            printf("Sorry you cannot use a number more than once. Try again\n");
            
            //If the numbers are the same, i reinitialising the array to 0
              for ( i = 0 ; i < SIZE ; i++ )
            {
                * ( user_array + i ) = 0 ;
            }
        }
        
        else
        {
            //If the numbers are the same, increment a counter by 1.
            counter++;
        }
        
        
        //I am returning the value of counter back to main here. 
        return(counter);
    
    }//end option1()


    //Implement option2(). This option displays the users choosen numbers
    
    //This line passes down the nummbers in the the user_array to display to the user their choosen numbers.
    void option2(int *user_array)
    
    {
        printf("The numbers you choose are:\n");
        
        int i;
        
        
        //This for loop prints the values of each element in the array as the array was passed down.
        for(i=0;i<SIZE;i++)
        {
            printf(" %d\n",*( user_array+i));
            
        }
        
        
    }//end option2()



    //Implement option 3() . This option implements the bubble sort algorithm to sort the numbers in ascending order
    
    void option3(int *user_array)
    {
        
        int i,j,swap_num;
        
        //This outer for loop runs through every element in the array
        for (i = 0 ; i < ( SIZE - 1 ); i++)
        {
            //This inner for loop makes the swap
            for (j = 0 ; j < SIZE - i - 1; j++)
            {
                //The conditon in this if statement is calculating if the number the user entered eg if 3 is bigger then the next number in the array.  if its true the statment will excecute.
                if ( *( user_array+ j )> *(user_array +(j+1)) )
                {
                    
                    //if the users number is bigger then the next number in the array, it is strored into a varable called swap_num.
                    swap_num= user_array[j];
                    
                    
                    //This line places the position of the number compared 3 in to the position 3 was in
                    *(user_array+j)   = *(user_array+(j+1));
                    
                    
                    //This line than places the contents of the temporary variable eg.3 in the positon of the next number the number originally compared to 3.
                    *(user_array +(j+1)) = swap_num;
                }
            }//end inner for
        }//end outer for
        
        printf("Numbers you entered in increasing order:\n");
        
        
        //This prints out each of the numbers in ascending order to the user.
        for ( i = 0 ; i < SIZE; i++ )
        {
            printf("%d\n", *(user_array+i));
        }
        
    }//end option3()



    //Implement option 4.  Option 4 Compares the users numbers to the winning array letting them know if they've won anything
    void option4( int *user_array,int *winning_array)
    {
        int i;
        int j;
        int match=0;
        
        //This nested for loop compares the numbers the users entered to the winning numbers
        for(i=0;i<SIZE;i++)
        {
            for(j=0;j<SIZE;j++)
            {
                
                //The condition calculates if the winning numbers match the users numbers, if so increment a counter.
                if(*(user_array+i)==*(winning_array+j))
                {
                    
                    //Each time the users number matches the winning numbers , a counter called match is incrememented.
                    match++;
                    
                }
                
            }//end inner for
        }//end outer for
        
        //The following if statements comapare how many matches were made, and display to the user if they have won anything.
        if(match==6)
        {
            printf(" You have won:\n The Jackpot!\n\n");
        }
        
        else
        if(match==5 && BONUS)
        {
            printf(" You have won:\n A New car\n\n");
        }
        
        else
        if(match==5)
        {
            printf(" You have won:\n A Holiday\n\n");
        }
        
        else
        if(match==4 && BONUS)
        {
            printf("You have won:\n A Weekend away\n\n");
        }
        
        else
        if(match==4)
        {
            printf("You have won:\n A Night out\n\n");
        }
        
        else
        if(match==3 && BONUS)
        {
            printf("You have won:\n A Cinema ticket\n\n");
        }
        
        //This will display if the user has won nothing
        else
        {
            printf("Sorry you havent one anything! Better luck next time\n");
        }
        
        
    }//end option 4()

    //implement option5()
    void option5( int *user_array )
    {
        int j,i;
        
        //I have made an array and declared its size to be 42.
        int freq_array[42];
        
        
        printf("\nThe frequency of each of the numbers you have entered:\n\n");
        
        //First I started off with initialising my array in a for loop  to 0 to ensure  random data is not printed and the numbers i enter are stored correctly
        for ( i = 0 ; i < 42 ; i++ )
        {
            * ( freq_array + i ) = 0 ;
        }
        
        //In this line, I am placing the position of the users number to the corresponding postion in the frequency array 
        for( i = 0 ; i < SIZE ; i++ )
        {
            
            (*(freq_array+*(user_array+i)))++;
            
        }
        
        
        for(j=0;j<42;j++)
        {
            
            //If the elements are greater than 0, print them out. If something is stored in a position in the frequency array, its in range.
            if( *( freq_array + j ) > 0)
            {
                printf("%d was selected %d time(s)\n", j, *( freq_array + j ));
            }
            
        }
                
            
    }//end option 5()