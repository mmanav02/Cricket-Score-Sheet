//Cricket score sheet program
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void event();
void display_scorecard();
void name_team1();
void name_team2();
int toss(char[],char[]);
void strikechange();
void create_timeline(int,int);
void display_timeline();
int count,count_timeline,current_bat_team,total_over,total_runs[2],wicket[2],total_balls[2],tosswinner,index_for_bowler;
//count - for team player's names
//current_bat_team - current batting lineup
//total_over -  for total number of overs in an innings
//count_timeline - for timeline creation
char teama[20],teamh[20];//team names
//for team 1
//for batsman
struct node
{
    char name[20];
    int runs,balls,four,six;
    float str_rate;
    struct node *left;
    struct node *right;
}*h1,*t1,*h2,*t2,*bat1,*bat2,*bat3;
/* h1, t1 for team 1
   h2, t2 for team 2
   bat1, bat2 ,bat3 for default batsman
*/
// for bowlers
char name_bowler1[11][20];
int runs1[11];
int wkt1[11];
int balls1[11];
int extras1[11];
int econ1[11];
//for team 2
// for bowlers
char name_bowler2[11][20];
int runs2[11];
int wkt2[11];
int balls2[11];
int extras2[11];
int econ2[11];
// for timeline
struct node2
{
    int runs,wkts;
    struct node2 *next;
}*head,*tail;

char def_name1[11][20]={"Rohit","Rahul","Ishan","Kohli","Yadav","Dhoni","Thaku","Ashwin","Shami","Jassi","Jadeja"};
char def_name2[11][20]={"Jason","Root","Morgan","Jos","Malan","Jonny","Ali","Chris","Jordan","Wood","Khan"};

void name_team1()
{
    struct node *p;
    int count=0;
    printf("Team 1:\n");
    while(count<11)
    {
        if(count==0)
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            scanf("%s",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->right=p->left=NULL;
            h1=p;
            t1=p;
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            scanf("%s",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->left=t1;
            p->right=NULL;
            t1->right=p;
            t1=p;
        }
        count++;
    }
    struct node *t=h1;
    int i=0;
    while(i<11)
    {
        strcpy(name_bowler1[i],t->name);
        runs1[i]=wkt1[i]=balls1[i]=econ1[i]=extras1[i]=0;
        t=t->right;
        i++;
    }
}

void def_name_team1()
{
    struct node *p;
    int count=0;
    printf("Team 1:\n");
    while(count<11)
    {
        if(count==0)
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            strcpy(p->name,def_name1[count]);
            printf("%s\n",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->right=p->left=NULL;
            h1=p;
            t1=p;
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            strcpy(p->name,def_name1[count]);
            printf("%s\n",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->left=t1;
            p->right=NULL;
            t1->right=p;
            t1=p;
        }
        count++;
    }
    struct node *t=h1;
    int i=0;
    while(i<11)
    {
        strcpy(name_bowler1[i],t->name);
        runs1[i]=wkt1[i]=balls1[i]=econ1[i]=extras1[i]=0;
        t=t->right;
        i++;
    }
}

void name_team2()
{
    struct node *p;
    int count=0;
    printf("Team 2:\n");
    while(count<11)
    {
        if(count==0)
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            scanf("%s",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->right=p->left=NULL;
            h2=p;
            t2=p;
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            scanf("%s",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->left=t2;
            p->right=NULL;
            t2->right=p;
            t2=p;
        }
        count++;
    }
    struct node *t=h2;
    int i=0;
    while(i<11)
    {
        strcpy(name_bowler2[i],t->name);
        runs2[i]=wkt2[i]=balls2[i]=econ2[i]=extras2[i]=0;
        t=t->right;
        i++;
    }
}

void def_name_team2()
{
    struct node *p;
    int count=0;
    printf("Team 2:\n");
    while(count<11)
    {
        if(count==0)
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            strcpy(p->name,def_name2[count]);
            printf("%s\n",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->right=p->left=NULL;
            h2=p;
            t2=p;
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            printf("Player No. %d\n",(count+1));
            strcpy(p->name,def_name2[count]);
            printf("%s\n",p->name);
            p->runs=p->balls=p->four=p->six=p->str_rate=0;
            p->left=t2;
            p->right=NULL;
            t2->right=p;
            t2=p;
        }
        count++;
    }
    struct node *t=h2;
    int i=0;
    while(i<11)
    {
        strcpy(name_bowler2[i],t->name);
        runs2[i]=wkt2[i]=balls2[i]=econ2[i]=extras2[i]=0;
        t=t->right;
        i++;
    }
}

int check_for_end(int num)
{
    if(wicket[num]==10 || total_balls[num]/6==total_over)
        return 1;
    else
        return 0;
}

void assign_default_batsman(int num)
{
    if(num==1)
    {
        bat1=h1;
        bat2=h1->right;
        bat3=h1->right;;
    }
    if(num==2)
    {
        bat1=h2;
        bat2=h2->right;
        bat3=h2->right;
    }
}

int search_for_bowler()// searches for bowler for new over
{
    char check_name[20];
    int a=1;
    while(a)
    {
        printf("Enter the name of bowler\n");
        scanf("%s",&check_name);
        if(current_bat_team==1)//team 1 bowlers
        for(int i=0;i<12;i++)
        {
            if(strcmpi(check_name,name_bowler1[i])==0)
                return i;
        }
        if(current_bat_team==0)//team 2 bowlers
        for(int i=0;i<12;i++)
        {
            if(strcmpi(check_name,name_bowler2[i])==0)
                return i;
        }
        printf("Enter again! Error 404. Not Found.\n");
    }
}

void bat_score(int reg)
{
    if(reg<=7 && reg>=0)
    {
        /*if(reg=-1)//wicket
            bat1->balls++;*/
        if(reg%2==0)
        {
            if(reg==4)
            bat1->four++;
            else if(reg==6)
            bat1->six++;
            bat1->runs+=reg;
            bat1->balls++;
        }
        else
        {
            bat1->runs+=reg;
            bat1->balls++;
            strikechange();
        }
    }
    else
        printf("Invalid.\n");
}

void strikechange()
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=bat1;
    bat1=bat2;
    bat2=temp;
}

void ball_score(int reg,int choice,int index)
{
    //reg for run input
    //choice for byes or wickets or no balls or wides
    //index for bowler
    int wkts,strchange;//for wickets
    if(current_bat_team==0)//for team 1
    {
        if(choice==1)//byes
        {
            runs2[index]+=reg;
            balls2[index]++;
            extras2[index]++;
            if(reg%2==1)
                strikechange();
        }
        else if(choice==2)//wickets
        {
            printf("Which Batsman got out? 1. Strike or 2.Non-Strike - ");
            scanf("%d",&wkts);
            printf("Did they change strike? 1. Yes or 2. No - ");
            scanf("%d",&strchange);
            bat3=bat3->right;
            wkt2[index]++;
            balls2[index]++;
            total_runs[current_bat_team]+=reg;
            if (wkts == 1)
            {
                if (strchange == 1)
                {
                    bat1 = bat2;
                    bat2 = bat3;
                }
                else if (strchange == 2)
                {
                    bat1 = bat3;
                }
                else
                {
                    printf("Enter 1 or 2");
                }
            }
            else if (wkts == 2)
            {
                if (strchange == 1)
                {
                    bat2 = bat1;
                    bat1 = bat3;
                }
                else if (strchange == 2)
                {
                    bat2 = bat3;
                }
                else
                {
                    printf("Enter correct input! 1 or 2");
                }
            }
        }
        else if(choice==3)//no balls and wides
        {
            runs2[index]++;
            runs2[index]+=reg;
            if (reg % 2 == 1)
            {
                strikechange();
            }
        }
        else//simple run and ball
        {
            runs2[index]+=reg;
            balls2[index]++;
        }
    }
    else
    {
        if(choice==1)//byes
        {
            runs1[index]+=reg;
            balls1[index]++;
            extras1[index]++;
            if(reg%2==1)
                strikechange();
        }
        else if(choice==2)//wickets
        {
            printf("Which Batsman got out? 1. Strike or 2.Non-Strike - ");
            scanf("%d",&wkts);
            printf("Did they change strike? 1. Yes or 2. No - ");
            scanf("%d",&strchange);
            bat3=bat3->right;
            wkt1[index]++;
            balls1[index]++;
            total_runs[current_bat_team]+=reg;
            if (wkts == 1)
            {
                if (strchange == 1)
                {
                    bat1 = bat2;
                    bat2 = bat3;
                }
                else if (strchange == 2)
                {
                    bat1 = bat3;
                }
                else
                {
                    printf("Enter 1 or 2");
                }
            }
            else if (wkts == 2)
            {
                if (strchange == 1)
                {
                    bat2 = bat1;
                    bat1 = bat3;
                }
                else if (strchange == 2)
                {
                    bat2 = bat3;
                }
                else
                {
                    printf("Enter correct input! 1 or 2");
                }
            }
        }
        else if(choice==3)//no balls and wides
        {
            runs1[index]++;
            runs1[index]+=reg;
            if (reg % 2 == 1)
            {
                strikechange();
            }
        }
        else//simple run and ball
        {
            runs1[index]+=reg;
            balls1[index]++;
        }
    }
}

void display_timeline()
{
    struct node2 *p=head;
    for(int i=1;i<=(total_over*6);i++)
    {
        printf("Over: %d.%d\n",i/6,i%6);
        if(p->runs>=0)
            printf("Runs: %d\n",p->runs);
        if(p->wkts==1)
            printf("Wicket: %d\n",p->wkts);
        if(p->next)
            p=p->next;
        else
            break;
    }
    if(p->next)
    {
        for(int i=1;i<=(total_over*6);i++)
        {
            printf("Over: %d.%d\n",i/6,i%6);
            if(p->runs>=0)
                printf("Runs: %d\n",p->runs);
            if(p->wkts==1)
                printf("Wicket: %d\n",p->wkts);
            if(p->next)
                p=p->next;
            else
                break;
        }
    }
}

void create_timeline(int choice,int reg)
{
    struct node2 *p=(struct node2 *)malloc(sizeof(struct node2));
    if(choice==1)//adding runs
    {
        if(count_timeline==0)
        {
            p->runs=reg;
            p->next=NULL;
            head=p;
            tail=p;
            count_timeline++;
        }
        p->runs=reg;
        p->next=NULL;
        tail->next=p;
        tail=p;
        count_timeline++;
    }
    if(choice==2)//wicket
    {
        if(count_timeline==0)
        {
            p->wkts=1;
            p->runs=reg;
            p->next=NULL;
            head=p;
            tail=p;
            count_timeline++;
        }
        p->wkts=1;
        p->runs=reg;
        p->next=NULL;
        tail->next=p;
        tail=p;
        count_timeline++;
    }
    if(choice==3)//wide or no ball
    {
        if(count_timeline==0)
        {
            p->runs++;
            p->runs+=reg;
            p->next=NULL;
            head=p;
            tail=p;
            count_timeline++;
        }
        p->runs++;
        p->runs+=reg;
        p->next=NULL;
        tail->next=p;
        tail=p;
        count_timeline++;
    }
}

void event()
{
    //eoi - end of ininings check
    int ch, eoi = 1, reg;
    if(total_balls[current_bat_team]%6==0)
    index_for_bowler=search_for_bowler();
    do
    {
        printf("Enter the event occuring:\n1. Run off Bat 2. Leg-Bye 3. No Ball 4. Wide 5. Byes 6. Wicket 7.End of over 8. End of Innings 9.Go to mainmenu\n");
        scanf("%d", &ch);
        if (ch == 1)//Run-off
        {
            total_balls[current_bat_team]++;
            printf("Enter the runs scored of the ball - ");
            scanf("%d",&reg);
            total_runs[current_bat_team]+= reg;
            bat_score(reg);
            ball_score(reg,10,index_for_bowler);
            create_timeline(1,reg);
            if(total_balls[current_bat_team]%6!=0)
            printf("Over: %d.%d\n",total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
        }
        else if (ch == 2)//Leg-bye
        {
            total_balls[current_bat_team]++;
            printf("Enter the runs scored of the ball - ");
            scanf("%d",&reg);
            total_runs[current_bat_team]+= reg;
            ball_score(reg,1,index_for_bowler);
            create_timeline(1,reg);
            if(total_balls[current_bat_team]%6!=0)
            printf("Over: %d.%d\n",total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
        }
        else if (ch == 3)//No ball
        {
            printf("Enter the runs scored of the ball - ");
            scanf("%d",&reg);
            total_runs[current_bat_team]++;
            total_runs[current_bat_team]+= reg;
            bat_score(reg);
            ball_score(reg, 3,index_for_bowler);
            create_timeline(3,reg);
            if(total_balls[current_bat_team]%6!=0)
            printf("Over: %d.%d\n",total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
        }
        else if (ch == 4)//Wide
        {
            printf("Enter the runs scored of the ball - ");
            scanf("%d",&reg);
            total_runs[current_bat_team]++;
            total_runs[current_bat_team]+= reg;
            ball_score(reg,3,index_for_bowler);
            create_timeline(3,reg);
            if(total_balls[current_bat_team]%6!=0)
            printf("Over: %d.%d\n",total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
        }
        else if (ch == 5)//Byes
        {
            total_balls[current_bat_team]++;
            printf("Enter the runs scored of the ball - ");
            scanf("%d",&reg);
            total_runs[current_bat_team]+= reg;
            ball_score(reg, 1,index_for_bowler);
            create_timeline(1,reg);
            if(total_balls[current_bat_team]%6!=0)
            printf("Over: %d.%d\n",total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
        }
        else if (ch == 6)//Wicket
        {
            total_balls[current_bat_team]++;
            printf("Enter the runs scored of the ball - ");
            scanf("%d",&reg);
            total_runs[current_bat_team]+= reg;
            ball_score(reg,2,index_for_bowler);
            bat_score(reg);
            wicket[current_bat_team]++;
            create_timeline(2,reg);
            if(total_balls[current_bat_team]%6!=0)
            printf("Over: %d.%d\n",total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
        }
        else if (ch == 7)//End of over
        {
            strikechange();
            system("cls");
            display_scorecard();
            index_for_bowler=search_for_bowler();
        }
        else if (ch == 8)//end of innings
        {
            eoi = 0;
            return;
        }
        else if(ch==9)
        {
            return;
        }
        else
        {
            printf("Enter a correct input! Making mistakes here is not an option! Welcome to Nirma!\n");
        }
        }while(eoi && (total_balls[current_bat_team]/6)!=total_over);
        if(check_for_end(current_bat_team))
        {
            printf("End of innings.\n");
            return;
        }
}

int toss(char team1[20], char team2[20])
{
    char ch;
    int headtail;
    int correctin=1,tosschoice,tosslost;
    while(correctin){
        printf("What was the outcome of the toss?1. Head 2. Tail\n");
        scanf("%d",&headtail);
        if(headtail==1 || headtail==2){
            break;
        }
        else{
            printf("Enter correct input!\n");
            continue;
        }
    }
    correctin=1;
    while(correctin){
        printf("Enter the Team that Won the toss: 1. %s or 2. %s\n",team1,team2);
        scanf("%d",&tosswinner);
        if(tosswinner==1 || tosswinner==2){
            if(tosswinner==1)
                tosslost=2;
            else
                tosslost=1;
            break;
        }
        else{
            printf("Enter correct input!\n");
            continue;
        }
    }
    if(headtail==1)
    ch='H';
    else
    ch='T';
    correctin=1;
    while(correctin){
        printf("What was the choice they made? 1. Bat or 2. Bowl\n");
        scanf("%d",&tosschoice);
        if(tosschoice==1){
            printf("The outcome was %c and was won by Team %d and choose to Bat\n",ch, tosswinner);
            assign_default_batsman(tosswinner);
            break;
        }
        else if(tosschoice==2){
            printf("The outcome was %c and was won by Team %d and choose to Bowl\n",ch, tosswinner);
            assign_default_batsman(tosslost);
            break;
        }
        else{
            printf("Enter correct input!\n");
            continue;
        }
    }
    if(tosschoice==1)
        return tosswinner-1;
    else
        return tosslost-1;
}

int sum(int arr[])//total number of extras
{
    int extra = 0;
    for(int i=0;i<11;i++)
        extra += arr[i];
    return extra;
}

void display_scorecard()
{
    // // refer dream11 scorecard( for more details)
    // eg                       IND vs PAK in line 1 at center
    // total score of t1/wicket(total overs)               total score of t2/wicket(total overs)
    // t1/t2 won by x runs / y wickets

    printf("--------------------------------------------------------------------------------------");
    printf("\nInning 1 ScoreCard \t\t\t"); // stats of team who did bat first
    // printf("IND  49/4(5.0)");
    printf("%d / %d (%d.%d) ", total_runs[0], wicket[0], total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
    // for batsman
    printf("\n\nBatsman Name \t Runs \t Balls \t 4s \t 6s \t Strike Rate\n");
    struct node *q = h1;
    while (q != NULL) // it shold be till NULL(as any players didn't bat)
    {
        if(q->balls !=0)
        printf("%s \t\t %d \t %d \t %d \t %d \t %.2f\n", q->name, q->runs, q->balls, q->four, q->six, (float)(((float)q->runs*100)/(float)q->balls));
        q = q->right;
    }
    printf("\nExtra runs = %d",sum(extras2));
    printf("\nScore : %d / %d (%d) ", total_runs[0], wicket[0], total_over);
    // printf("\nScore : 49/4(5.0)");

    printf("\n\nYet to BAT : ");
    q = h1;
    while (q != NULL)
    {
        if (q->balls == 0)
        {
            printf("%s", q->name);
            if (q->right != NULL)
                printf(", ");
            else
                printf(".");
        }
            q = q->right;
    }
    // for bowlers
    printf("\n\nBowler Name \t Over \t Runs \t Wicket\t\tEconomy\n");
    for (int i = 0; i < 11; i++)
    {
        if(balls2[i]!=0)
        printf("%s \t\t %d.%d \t %d \t %d \t \t%.2f\n", name_bowler2[i], balls2[i]/6 , balls2[i]%6 , runs2[i] , wkt2[i] , (float)runs2[i]/(balls2[i]/6));
    }

    printf("--------------------------------------------------------------------------------------");

    // PAK (Same as INDIA) (inning 2)
    printf("\nInning 2 ScoreCard \t\t\t");
    printf("%d / %d (%d.%d) ", total_runs[1], wicket[1], total_balls[current_bat_team]/6,total_balls[current_bat_team]%6);
    // printf("PAK  45/4(5.0)");
    // for batsman
    printf("\n\nBatsman Name \t Runs \t Balls \t 4s \t 6s \t Strike Rate\n");
    struct node *r = h2;
    while (r != NULL) // it shold be till NULL(as amny players didn't bat)
    {
        if(r->balls !=0)
        printf("%s \t\t %d \t %d \t %d \t %d \t %.2f\n", r->name, r->runs, r->balls, r->four, r->six, (float)(((float)r->runs*100)/(float)r->balls));
        r = r->right;
    }
    printf("\nExtra runs = %d",sum(extras1));
    printf("\nScore : %d / %d (%d) ", total_runs[1], wicket[1], total_over);
    // printf("\nScore : 45/4(5.0)");

    printf("\nYet to BAT : ");
    r = h2;
    while (r != NULL)
    {
        if (r->balls == 0)
        {
            printf("%s", r->name);
            if (r->right != NULL)
                printf(", ");
            else
                printf(".");
        }
        r = r->right;
    }
    // for bowlers
    printf("\n\nBowler Name \t Over \t Runs \t Wicket\t\tEconomy\n");
    for (int i = 0; i < 11; i++)
    {
        if(balls1[i]!=0)
        printf("%s \t\t %d.%d \t %d \t %d \t \t%.2f\n", name_bowler1[i], balls1[i]/6 , balls1[i]%6, runs1[i], wkt1[i], (float)runs1[i]/(balls1[i]/6));
    }
}

void display_result()
{
    if(total_runs[0]>total_runs[1])
    {
        if(tosswinner==1)
        printf("%s team won by %d runs\n",teama,total_runs[0] - total_runs[1]);
        else
        printf("%s team won by %d wickets\n",teama,10-wicket[current_bat_team]);
    }
    else if(total_runs[0]<total_runs[1])
    {
        if(tosswinner==1)
        printf("%s team won by %d wickets\n",teamh,10-wicket[current_bat_team]);
        else
        printf("%s team won by %d runs\n",teamh,total_runs[1] - total_runs[0]);
    }
    else if((total_balls[current_bat_team]/6)<total_over)
    {
        printf("Too soon to give result\n");
        return;
    }
}

void main_menu()
{
    int a=1;
    int innings_count=0;
    count_timeline=0;
    printf("Cricket Score Sheet:\n");
    printf("Enter team name:\nTeam 1: ");
    scanf("%s",&teama);
    printf("Team 2: ");
    scanf("%s",&teamh);
    while(a)
    {
        printf("\nDo you want to 1. Enter player names or 2. Want player's names by default?\n");
        scanf("%d",&a);
        if(a==1)
        {
            name_team1();
            name_team2();
            break;
        }
        else
        {
            def_name_team1();
            def_name_team2();
            break;
        }
    }
    current_bat_team=toss(teama,teamh);
    printf("Enter Total no. of overs: ");
    scanf("%d",&total_over);
    a=1;
    while(a!=0)
    {
        printf("Menu:\n1. Add to timeline(event)\n2. Enter details for next innings\n3. Display scorecard\n4. Display Timeline\n5. Display result\n0. Exit\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            innings_count++;
            event();
            break;
            case 2:
            if(innings_count>0 && check_for_end(current_bat_team)==1)
            {
                if(current_bat_team==1)
                assign_default_batsman(1);
                else
                assign_default_batsman(2);
                if(current_bat_team==1)
                    current_bat_team=0;
                else
                    current_bat_team=1;
                event();
                innings_count=0;
            }
            else
            printf("Go to add to timeline\n");
            break;
            case 3:
            display_scorecard();
            break;
            case 4:
            display_timeline();
            break;
            case 5:
            display_result();
            break;
            case 0:
            a=0;
            break;
            default:
            printf("Wrong input\n");
            break;
        }
    }
}

void main()
{
    main_menu();
}
