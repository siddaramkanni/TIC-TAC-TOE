#include <stdio.h>
#include <stdlib.h>

///............Functions.................//////
void Display();
int game_over();
void input_event();
int check();

///...........Variables.................///////
char box[] = ".........";
int count = 1;


int main()
{
    Display();
    while(1)
    {
        if(game_over()!=1 && check() == 0)
        {
            input_event();
            count++;
        }
        else if(check() == 1)
        {
            if(count % 2 == 0)
            {
                printf(" PLAYER 1 WINS!\n");
                break;
            }
            else
            {
                printf(" PLAYER 2 WINS!\n");
                break;
            }

        }
        else
        {
            printf("GAME OVER: NO MORE ENTRIES!\n");
            break;
        }

    }
    return 0;
}

void Display()
{
    printf("\t\t\t TIC-TAC-TOE\n");
    printf("\t\t PLAYER_1 : X \n");
    printf("\t\t PLAYER_2 : O \n\n");
    printf("\t\t .....................\n");
    printf("\t\t |  %c  |   %c  |   %c  |\n", box[0],box[1], box[2]);
    printf("\t\t .....................\n");
    printf("\t\t |  %c  |   %c  |   %c  |\n", box[3],box[4], box[5]);
    printf("\t\t .....................\n");
    printf("\t\t |  %c  |   %c  |   %c  |\n", box[6],box[7], box[8]);
    printf("\t\t .....................\n");
}

void input_event()
{
    int input=0;
    if(count %2 ==0)
    {
        printf("\n");
        printf("Input Player 2:");
        scanf("%d", &input);
        box[input-1]= 'O';
        Display();
    }
    else
    {
        printf("\n");
        printf("Input Player 1:");
        scanf("%d", &input);
        box[input-1]= 'X';
        Display();
    }


}

int game_over()
{
    int entry_count =0;
    for(int i=0; i<9;i++)
    {
        if(box[i]== 'X' || box[i]== 'O')
        {
            entry_count++;
        }
    }
    if(entry_count==9)
        return 1;
}

int check()
{
    if(box[0] == box[1] && box[1] == box[2] && box[0] !='.')
        return 1;
    else if(box[3] == box[4] && box[4] == box[5] && box[3] !='.')
        return 1;
    else if(box[6] == box[7] && box[7] == box[8] && box[6] !='.')
        return 1;
    else if(box[0] == box[3] && box[3] == box[6] && box[0] !='.')
        return 1;
    else if(box[1] == box[4] && box[4] == box[7] && box[1] !='.')
        return 1;
    else if(box[2] == box[5] && box[5] == box[8] && box[2] !='.')
        return 1;
    else if(box[0] == box[4] && box[4] == box[8] && box[0] !='.')
        return 1;
    else if(box[2] == box[4] && box[4] == box[6] && box[2] !='.')
        return 1;
    else
        return 0;

}
