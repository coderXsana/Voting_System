#include <stdio.h>
#include <time.h>
#include<string.h>
#include <stdlib.h>
#include<unistd.h>
#include <windows.h>

// Define a structure to store the candidate information
struct candidate
{
    char name[20]; 
    int votes;     
};

// Define a structure to store the voter information
struct voter
{
    char voter_code[20]; // secret code
};


void init_candidates(struct candidate c[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        
        printf("Enter the name of candidate %d: ", i + 1);
        scanf("%s", c[i].name);

                c[i].votes = 0;
    }
}

// Define a function to display the candidates
void display_candidates(struct candidate c[], int n)
{

    for (int i = 0; i < n; i++)
    {
        
        printf("%s: %d votes\n", c[i].name, c[i].votes);
    }
}
// check_votercode to prevent repeating of same voter
int check_votercode(struct voter v[], int z)
{
    int c = 0;//strcmp(str1, str2)
    for (int i = 0; i < z; i++)
    {
        if (strcmp (v[z].voter_code , v[i].voter_code)==0)
        {
          
            c = 1;
            break;
        }
    }
    return c;
}



// Define a function to cast a vote
void cast_vote(struct candidate c[], int n, struct voter v[], int z)
{
    printf("Enter your voter code : ");

    scanf("%s", v[z].voter_code);
    int x = check_votercode(v, z);
    if(x==1){
      printf("You are already voted\n");
    }
    else
    {
    
        for (int i = 0; i < n; i++)
        {
            printf("Press %d to vote %s\n", i + 1, c[i].name);
        }

        
        int choice;
        
        printf("Enter the number of your choice: ");
        scanf("%d", &choice);
        
        if (choice > 0 && choice <= n)
        {
            
            c[choice - 1].votes++;
            
            printf("You have voted for %s.\n", c[choice - 1].name);
        }
        else
        {
            
            printf("Invalid choice.\n");
        }
    }
    printf("Wait 4 sec ");
    Beep (800, 325);
    sleep(4);
    
    system("cls");

    printf("Your vote is hidden now.\n");
}

// Define a function to find the winner
void find_winner(struct candidate c[], int n)
{

    int max_votes = 0;
    int winner = -1;

    for (int i = 0; i < n; i++)
    {

        if (c[i].votes >= max_votes)
        {
            
            if (c[i].votes == max_votes)
            {
                winner = -1;
            }
            
            else
            {
                max_votes = c[i].votes;
                winner = i;
            }
        }
    }
    
    if (winner != -1)
    {
        // Print the name and the votes of the winner
        printf("The winner is %s with %d votes.\n", c[winner].name, max_votes);
    }
    else
    {

        printf("There is no winner.\n");
    }
}

int main()
{
     int sp_code=1234,sp=0,count=0;
     printf("Enter the special code provide by Election commission to start election \n");
     while (sp!=sp_code&&count<=10)                     //doubt
     {
         scanf("%d",&sp);
         count++;
         if(sp!=sp_code){
            printf("Please try again\n you have only %d time left \n",10-count);
         }
         if(count==10){
            printf("your are not eligible");
         }
     }
     
       
        
    
    printf("IMPORTANT INSTRUCTION FOR ELECTION COMMITTEE\n");
    printf("press 1 for voting(a)\npress -1 for pause the election(a) \npress -9 for stop the election(a)\n");

    

    int N;
    printf("Enter the number of candidates participate in election : ");
    scanf("%d", &N);
    // Declare an array of candidates using the structure
    struct candidate candidates[N];
                                  

    // Initialize the candidates using the function
    init_candidates(candidates, N);
    char start;
    
    display_candidates(candidates, N);

     int voters;

     printf("Enter the number of voters max limit: ");

    scanf("%d", &voters);
    // Declare an array of voter using the structure
   struct voter voter[voters];
    int a=10000;
    for (int i = 0;a!=-9 ; i++)
    {
        // Print a message to indicate the current voter
        printf("Voter %d:\n", i + 1);
        // Cast a vote using the function             {
        // cast_vote(candidates, N, voter, i);           i make some change here   1
        // Beep (750, 1025);                           }
        printf("press 1 for voting(a) : ");
        scanf("%d",&a);
        if(a==-1){
            printf("Enter the special code provide by Election commission to pause election \n");
            scanf("%d",&sp);
            if(sp==sp_code){
            float t;
            printf("Enter time in min : ");
            scanf("%f",&t);
            sleep(t*60);
            i--;//  some change
            continue;
            }
            
        }
        if(a==-9){
               printf("Enter the special code provide by Election commission to end election \n"); 
               scanf("%d",&sp);
               if(sp!=sp_code){
                a=1;
                i--; // some change 
               }
               continue;
            }
            // Cast a vote using the function    {
        cast_vote(candidates, N, voter, i);    //    i make some change here 
        Beep (750, 1025);                      //      }
    }
    // Shown the total vote of each candidate
    display_candidates(candidates, N);

    // Find the winner using the function
    find_winner(candidates, N);

    return 0;
}
