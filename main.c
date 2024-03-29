#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>
#include <time.h>

int n, m, menu, startGame, gamemode, load, save, turn, freelines;                                                   // n = array size , m = no of lines which can be connected
int r, c, r1, c1, r2, c2, count, player_id, minutes_of_game, k, p1moves, p2moves, compumoves;                       // if count is even, player1 turn  and if it is odd , player 2 turn & k = counter to do automatic choose for file saving                                                                   // for player id
clock_t start, end, start2, end2;                                                                                   // clock_t is a type(class) and this is used in the timer function
double cpu_time_used, seconds_of_game, tmp;                                                                         // clock_t is a type(class)

typedef struct {
    char name[25];
    int score;
}player;
player p[2], topGamers[1000], temp, comp, p1;

void human() {
    system("cls");
    FILE *game;
    FILE *rank;

    //Way to make the game able to do Automatic Choosing of saving File

    // Saving certain value to let us do loop for choosing file of saving

    game = fopen("Save0.txt", "r");
    fscanf(game,"%d",&k);
    fflush(stdin);
    fclose(game);

    // choosing the file automatically
    k++;

    // loading this value

    game = fopen("Save0.txt", "w");
    fprintf(game,"%d",k);
    fclose(game);

    // Choosing Game Mode

    a21 :
    system("cls");
    printf("(1) Beginner\n(2) Expert\n\n");
    a14 :
    scanf("%d",&gamemode) ;
    fflush(stdin);
    switch (gamemode) {
    case 1 :
        n = 5;                                                                                  // No. of Beginner Array Elements
        m = 12;                                                                                 // No. of Lines can be Connected
        break;
    case 2 :
        n = 11 ;                                                                                // No. of Expert Array Elements
        m = 60 ;                                                                                // No. of Lines can be Connected
        break;
    default :
        printf("Invalid Input Please Enter Again\n\n");
        goto a14;
        break;
    }

    // Checking New Game Or Load Saved Game

    a25 :
    system("cls");
    printf("(1) Start A New Game\n(2) Load Game\n(3) Return\n\n");
    char gridArray[n][n][2];
    a23 :
    scanf("%d",&load);
    fflush(stdin);
    switch (load) {
        case 1 :
            goto a24;
            break;
        case 2 :
            system("cls");
            printf("(1) To Load Game 1\n(2) To Load Game 2\n(3) To Load Game 3\n(4) Return\n\n");
            a22 :
            scanf("%d",&load);
            fflush(stdin);
            switch (load) {
                case 1 :
                    game = fopen("Save1.txt", "r");                                                       //Open Text File with the name "Save1" to load the last saved data of the grid
                    for(int i=0; i<n; i++) {                                                              //Loop for Scanning the saved data of the grid to the game
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][0]);
                        }
                    }
                    for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][1]);
                        }
                    }
                    fscanf(game, "%d", &m);
                    fscanf(game, "%d", &n);
                    fscanf(game, "%d", &p[0].score);
                    fscanf(game, "%d", &p[1].score);
                    fscanf(game, "%d", &player_id);
                    fscanf(game, "%d", &p1moves);
                    fscanf(game, "%d", &p2moves);
                    fscanf(game, "%d", &count);
                    fscanf(game, "%d", &minutes_of_game);
                    fscanf(game, "%lf", &seconds_of_game);
                    fclose(game);
                    break;
                case 2 :
                    game = fopen("Save2.txt", "r");                                                       //Open Text File with the name "Save2" to load the last saved data of the grid
                    for(int i=0; i<n; i++) {                                                              //Loop for Scanning the saved data of the grid to the game
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][0]);
                        }
                    }
                    for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][1]);
                        }
                    }
                    fscanf(game, "%d", &m);
                    fscanf(game, "%d", &n);
                    fscanf(game, "%d", &p[0].score);
                    fscanf(game, "%d", &p[1].score);
                    fscanf(game, "%d", &player_id);
                    fscanf(game, "%d", &p1moves);
                    fscanf(game, "%d", &p2moves);
                    fscanf(game, "%d", &count);
                    fscanf(game, "%d", &minutes_of_game);
                    fscanf(game, "%lf", &seconds_of_game);
                    fclose(game);
                    break;
                case 3 :
                    game = fopen("Save3.txt", "r");                                                       //Open Text File with the name "Save3" to load the last saved data of the grid
                    for(int i=0; i<n; i++) {                                                              //Loop for Scanning the saved data of the grid to the game
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][0]);
                        }
                    }
                    for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][1]);
                        }
                    }
                    fscanf(game, "%d", &m);
                    fscanf(game, "%d", &n);
                    fscanf(game, "%d", &p[0].score);
                    fscanf(game, "%d", &p[1].score);
                    fscanf(game, "%d", &player_id);
                    fscanf(game, "%d", &p1moves);
                    fscanf(game, "%d", &p2moves);
                    fscanf(game, "%d", &count);
                    fscanf(game, "%d", &minutes_of_game);
                    fscanf(game, "%lf", &seconds_of_game);
                    fclose(game);
                    break;
                case 4 :
                    goto a25;
                    break;
                default :
                    printf("Invalid Input Please Enter Again\n");
                    goto a22;
                    break;
                }

            // Check The Chosen Mode is compatible with Loaded Grid

            if (gamemode == 1 && n == 11) {
                    printf("\nThe Loaded Grid is Greater than Beginner Mode Grid ");
                    Sleep(1500);
                    goto a21;
            }
            else if (gamemode == 2 && n == 5) {
                printf("\nThe Loaded Grid is Smaller than Beginner Mode Grid ");
                Sleep(1500);
                goto a21;
            }
            goto a26;
            break;
        case 3 :
            goto a21;
            break;
        default :
            printf("Invalid Input Please Enter Again\n\n");
            goto a23;
            break;
    }

    // Designing the grid

    a24 :
    for (int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if (i%2 == 0 && j%2 == 0) {
                gridArray[i][j][0] = 254;
            }
            else if (i%2 == 0 && j%2 == 1) {
                gridArray[i][j][0] = ' ' ;
            }
            else if (i%2 == 1 && j%2 == 0) {
                gridArray[i][j][0] = ' ';
            }
            else if (i%2 == 1 && i%2 == 1){
                gridArray[i][j][0] = ' ';
            }
        }
    }

    // Printing the Grid Before The Match

    a26 :
    system("cls");
    if (gamemode == 1) {
        printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
        printf("\t\t\t     0 1 2 3 4\n\n");
    }
    else if (gamemode == 2) {
        printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
        printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
    }
    for (int i=0 ; i<n ; i++) {
        if (i != 10) {
            printf("\t\t\t%d    ",i);
        }
        else if (i == 10) {
            printf("\t\t       %d    ",i);
        }
        for (int j=0 ; j<n ; j++) {
            printf("%c ",gridArray[i][j][0]);
        }
        printf("\n");
    }
    printf("\n");

    // Loop of The Game

    for( int i=0 ; i<m ; i++) {
        a11:
        cpu_time_used = 0;
        player_id = count%2;

        if (gamemode == 1) {
            if ((player_id+1) == 1) {
                printf("\n\t\t\t\033[1;34mPlayer (%d)\033[0m Turn\n\n", player_id+1);
            }
            else if ((player_id+1) == 2) {
                printf("\n\t\t\t\033[1;31mPlayer (%d)\033[0m Turn\n\n", player_id+1);
            }
        }
        else if (gamemode == 2) {
            if ((player_id+1) == 1) {
                printf("\n         \t\t\t\033[1;34mPlayer (%d)\033[0m Turn\n\n", player_id+1);
            }
            else if ((player_id+1) == 2) {
                printf("\n         \t\t\t\033[1;31mPlayer (%d)\033[0m Turn\n\n", player_id+1);
            }
        }

        // Asking Player to enter coordinates of the required connected lines
        a30 :
        printf("Enter Row Then Column of Required Line [example: 0 3] --> ");
        a10 :
        start = clock();                                                                                        //the beginning of counting
        scanf("%d %d",&r,&c);                                                                                   //r = row , c = column
        fflush(stdin);
        end = clock();                                                                                          //the end of counting
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Undo One Move

        if (r == 0 && c == 0) {
        }
        else {
            r1 = r;
            c1 = c;
        }
        if (i>0) {
            if ( r == 0 && c == 0 ) {
                if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == 'A' && gridArray[r1+1][c1][0] == 'A' ) {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == 'B' && gridArray[r1+1][c1][0] == 'B') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == 'A' && gridArray[r1+1][c1][0] == 'B') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == 'B' && gridArray[r1+1][c1][0] == 'A') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == 'A' && gridArray[r1+1][c1][0] == ' ') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == 'B' && gridArray[r1+1][c1][0] == ' ') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == ' ' && gridArray[r1+1][c1][0] == 'A') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '-' && gridArray[r1-1][c1][0] == ' ' && gridArray[r1+1][c1][0] == 'B') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == 'A' && gridArray[r1][c1-1][0] == 'A') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == 'B' && gridArray[r1][c1-1][0] == 'B') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == ' ' && gridArray[r1][c1-1][0] == 'B') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == ' ' && gridArray[r1][c1-1][0] == 'A') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == 'A' && gridArray[r1][c1-1][0] == ' ') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == 'B' && gridArray[r1][c1-1][0] == ' ') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == 'B' && gridArray[r1][c1-1][0] == 'A') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                else if (gridArray[r1][c1][0] == '|' && gridArray[r1][c1+1][0] == 'A' && gridArray[r1][c1-1][0] == 'B') {
                    printf("\nDon't Cheat! Ya Hrami\n");
                    goto a30;
                }
                gridArray[r1][c1][0] = ' ';
                count++;
                turn--;
                if (count % 2 == 0) {
                    p1moves-- ;
                }
                else {
                    p2moves-- ;
                }
                system("cls");

                // printing the grid after doing undo

                if (gamemode == 1) {
                    printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                    printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
                    printf("\t\t\t     0 1 2 3 4\n");
                }
                else if (gamemode == 2) {
                    printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                    printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
                    printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
                }
                for (int i=0 ; i<n ; i++) {
                   if (i != 10) {
                        printf("\t\t\t%d    ",i);
                    }
                    else if (i == 10) {
                        printf("\t\t       %d    ",i);
                    }
                    for (int j=0 ; j<n ; j++) {
                        if ( (i%2 == 1)&& (j%2==1)&&(gridArray[i][j][0]=='A') ) {                       //we here check whether the cell saving a character A
                            printf("\033[1;34m");                                                       //using ANSI color of blue
                            printf("%c ",gridArray[i][j][0]);
                            printf("\033[0m");                                                          //using ANSI color of reset
                        }
                        else if ( (i%2 == 1)&& (j%2 == 1) && (gridArray[i][j][0] == 'B') ) {            //we here check whether the cell saving a character B
                            printf("\033[1;31m");                                                       //using ANSI color of Red
                            printf("%c ",gridArray[i][j][0]);
                            printf("\033[0m");                                                          //using ANSI color of reset
                        }
                        else if ( (i%2 == 0) && (j%2 == 1 ) && (gridArray[i][j][0] == '-') ) {
                            if (gridArray[i][j][1]==0) {
                                printf("\033[1;34m");                                                   //using ANSI color of blue
                                printf("%c ",gridArray[i][j][0]);
                                printf("\033[0m");
                            }
                            else {
                                printf("\033[1;31m");                                                   //using ANSI color of red
                                printf("%c ",gridArray[i][j][0]);
                                printf("\033[0m");
                            }
                        }
                        else if ( (i%2 == 1) && (j%2 == 0 ) && (gridArray[i][j][0] == '|') ) {
                            if (gridArray[i][j][1]==0) {
                                printf("\033[1;34m");                                                  //using ANSI color of blue
                                printf("%c ",gridArray[i][j][0]);
                                printf("\033[0m");
                            }
                            else {
                                printf("\033[1;31m");                                                  //using ANSI color of red
                                printf("%c ",gridArray[i][j][0]);
                                printf("\033[0m");
                            }
                        }
                        else {
                        printf("%c ",gridArray[i][j][0]);
                        }
                    }
                    printf("\n");
                }
                i--;
                printf("\n(1) To Redo\n(2) Enter New Line\n\n ");
                a28 :
                scanf("%d",&load);
                fflush(stdin);
                switch (load) {
                    case 1 :
                        for(int i=0 ; i<n ; i++) {
                            for(int j=0 ; j<n ; j++) {
                                if (r1 == i && c1 == j) {
                                    if (i%2 == 0 && j%2 == 1) {
                                        gridArray[r1][c1][0] = '-';
                                        gridArray[r1][c1][1] = player_id-1;
                                    }
                                    else if (i%2 == 1 && j%2 == 0) {
                                        gridArray[r1][c1][0] = '|';
                                        gridArray[r1][c1][1] = player_id-1;
                                    }
                                }
                            }
                        }
                        system("cls");

                        // printing the grid after doing redo

                        if (gamemode == 1) {
                            printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                            printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
                            printf("\t\t\t     0 1 2 3 4\n");
                        }
                        else if (gamemode == 2) {
                            printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                            printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
                            printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
                        }
                        for (int i=0 ; i<n ; i++) {
                           if (i != 10) {
                                printf("\t\t\t%d    ",i);
                            }
                            else if (i == 10) {
                                printf("\t\t       %d    ",i);
                            }
                            for (int j=0 ; j<n ; j++) {
                                if ( (i%2 == 1)&& (j%2==1)&&(gridArray[i][j][0]=='A') ) {                       //we here check whether the cell saving a character A
                                    printf("\033[1;34m");                                                       //using ANSI color of blue
                                    printf("%c ",gridArray[i][j][0]);
                                    printf("\033[0m");                                                          //using ANSI color of reset
                                }
                                else if ( (i%2 == 1)&& (j%2 == 1) && (gridArray[i][j][0] == 'B') ) {            //we here check whether the cell saving a character B
                                    printf("\033[1;31m");                                                       //using ANSI color of Red
                                    printf("%c ",gridArray[i][j][0]);
                                    printf("\033[0m");                                                          //using ANSI color of reset
                                }
                                else if ( (i%2 == 0) && (j%2 == 1 ) && (gridArray[i][j][0] == '-') ) {
                                    if (gridArray[i][j][1]==0) {
                                        printf("\033[1;34m");                                                   //using ANSI color of blue
                                        printf("%c ",gridArray[i][j][0]);
                                        printf("\033[0m");
                                    }
                                    else {
                                        printf("\033[1;31m");                                                   //using ANSI color of red
                                        printf("%c ",gridArray[i][j][0]);
                                        printf("\033[0m");
                                    }
                                }
                                else if ( (i%2 == 1) && (j%2 == 0 ) && (gridArray[i][j][0] == '|') ) {
                                    if (gridArray[i][j][1]==0) {
                                        printf("\033[1;34m");                                                  //using ANSI color of blue
                                        printf("%c ",gridArray[i][j][0]);
                                        printf("\033[0m");
                                    }
                                    else {
                                        printf("\033[1;31m");                                                  //using ANSI color of red
                                        printf("%c ",gridArray[i][j][0]);
                                        printf("\033[0m");
                                    }
                                }
                                else {
                                printf("%c ",gridArray[i][j][0]);
                                }
                            }
                            printf("\n");
                        }
                        i++;
                        turn++;
                        count--;
                        if (count % 2 == 1) {
                            p1moves++ ;
                        }
                        else {
                            p2moves++ ;
                        }
                        break;
                    case 2 :
                        goto a11;
                        break;
                    default :
                        printf("Invalid Input Please Enter Again\n\n");
                        goto a28;
                        break;
                }
                goto a11;
            }
        }

        // Saving in File 1

        if (r == 1 && c == 1) {
            game = fopen("Save1.txt", "w");
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    fprintf (game,"%c",gridArray[i][j][0]);
                }
            }
            for (int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    fprintf (game,"%c",gridArray[i][j][1]);
                }
            }
            fprintf(game,"%d\n",freelines);
            fprintf(game,"%d\n",n);
            fprintf(game,"%d\n",p[0].score);
            fprintf(game,"%d\n",p[1].score);
            fprintf(game,"%d\n",player_id);
            fprintf(game,"%d\n",p1moves);
            fprintf(game,"%d\n",p2moves);
            fprintf(game,"%d\n",count);
            fprintf(game,"%d\n",minutes_of_game);
            fprintf(game,"%lf",seconds_of_game);
            fclose(game);
            goto a11;
        }

        // Saving in File 2

        if (r == 2 && c == 2 ) {
            game = fopen("Save2.txt", "w");
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    fprintf (game,"%c",gridArray[i][j][0]);
                }
            }
            for (int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    fprintf (game,"%c",gridArray[i][j][1]);
                }
            }
            fprintf(game,"%d\n",freelines);
            fprintf(game,"%d\n",n);
            fprintf(game,"%d\n",p[0].score);
            fprintf(game,"%d\n",p[1].score);
            fprintf(game,"%d\n",player_id);
            fprintf(game,"%d\n",p1moves);
            fprintf(game,"%d\n",p2moves);
            fprintf(game,"%d\n",count);
            fprintf(game,"%d\n",minutes_of_game);
            fprintf(game,"%lf",seconds_of_game);
            fclose(game);
            goto a11;
        }

        // Saving in File 3

        if (r == 3 && c == 3 ) {
            game = fopen("Save3.txt", "w");
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    fprintf (game,"%c",gridArray[i][j][0]);
                }
            }
            for (int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    fprintf (game,"%c",gridArray[i][j][1]);
                }
            }
            fprintf(game,"%d\n",freelines);
            fprintf(game,"%d\n",n);
            fprintf(game,"%d\n",p[0].score);
            fprintf(game,"%d\n",p[1].score);
            fprintf(game,"%d\n",player_id);
            fprintf(game,"%d\n",p1moves);
            fprintf(game,"%d\n",p2moves);
            fprintf(game,"%d\n",count);
            fprintf(game,"%d\n",minutes_of_game);
            fprintf(game,"%lf",seconds_of_game);
            fclose(game);
            goto a11;
        }

        // Saving in Any File

        if (r == 4 && c == 4) {
            if (k == 1) {
                game = fopen("Save1.txt", "w");
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][0]);
                    }
                }
                for (int i=0; i<n; i++) {
                    for(int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][1]);
                    }
                }
                fprintf(game,"%d\n",freelines);
                fprintf(game,"%d\n",n);
                fprintf(game,"%d\n",p[0].score);
                fprintf(game,"%d\n",p[1].score);
                fprintf(game,"%d\n",player_id);
                fprintf(game,"%d\n",p1moves);
                fprintf(game,"%d\n",p2moves);
                fprintf(game,"%d\n",count);
                fprintf(game,"%d\n",minutes_of_game);
                fprintf(game,"%lf",seconds_of_game);
                fclose(game);
            }
            else if (k == 2) {
                game = fopen("Save2.txt", "w");
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][0]);
                    }
                }
                for (int i=0; i<n; i++) {
                    for(int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][1]);
                    }
                }
                fprintf(game,"%d\n",freelines);
                fprintf(game,"%d\n",n);
                fprintf(game,"%d\n",p[0].score);
                fprintf(game,"%d\n",p[1].score);
                fprintf(game,"%d\n",player_id);
                fprintf(game,"%d\n",p1moves);
                fprintf(game,"%d\n",p2moves);
                fprintf(game,"%d\n",count);
                fprintf(game,"%d\n",minutes_of_game);
                fprintf(game,"%lf",seconds_of_game);
                fclose(game);
            }
            else if (k == 3) {
                game = fopen("Save3.txt", "w");
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][0]);
                    }
                }
                for (int i=0; i<n; i++) {
                    for(int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][1]);
                    }
                }
                fprintf(game,"%d\n",freelines);
                fprintf(game,"%d\n",n);
                fprintf(game,"%d\n",p[0].score);
                fprintf(game,"%d\n",p[1].score);
                fprintf(game,"%d\n",player_id);
                fprintf(game,"%d\n",p1moves);
                fprintf(game,"%d\n",p2moves);
                fprintf(game,"%d\n",count);
                fprintf(game,"%d\n",minutes_of_game);
                fprintf(game,"%lf",seconds_of_game);
                fclose(game);
            }
            goto a11;
        }

        // Checking the entered point of the user

        while ( ((r%2==0) && (c%2==0)) || ((r%2==1) && (c%2==1)) || (r>=n) || (c>=n) || (r<0) || (c<0)|| (isalpha(r)) || (isalpha(c)) || (gridArray[r][c][0] == '|') || (gridArray[r][c][0] == '-') ) {
            printf("\n\'\033[1;31mInvalid Input\033[0m\' Enter again Row Then Column Of Required Line [Example: 0 3] --> ");
            goto a10;
        }

        // printing the taken time for every turn

        if ((player_id+1) == 1) {
            printf("\nTurn Time Elapsed for \033[1;34mPlayer (%d)\033[0m :\033[1;34m %0.0f Seconds\033[0m\n", player_id+1, cpu_time_used);
        }
        else if ((player_id+1) == 2) {
            printf("\nTurn Time Elapsed for \033[1;31mPlayer (%d)\033[0m :\033[1;31m %0.0f Seconds\033[0m\n", player_id+1, cpu_time_used);
        }
        Sleep(1000);
        printf("\n");
        turn++ ;
        freelines = m - turn ;

        // Logic of entering data to the grid by the user

        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<n ; j++) {
                if (r == i && c == j) {
                    if (i%2 == 0 && j%2 == 1) {
                        gridArray[r][c][0] = '-';
                        gridArray[r][c][1] = player_id;

                    }
                    else if (i%2 == 1 && j%2 == 0) {
                        gridArray[r][c][0] = '|';
                        gridArray[r][c][1] = player_id;

                    }
                }
            }
        }

        // Counting the moves for each player

        if (count % 2 == 0) {
            p1moves++ ;
        }
        else {
            p2moves++ ;
        }

        // Logic of closing boxes and increasing score accompanying it

        count++;                                                                               // when any player enter his input count inc by one to change turns
        if (gridArray[r][c][0]== '|') {                                                        //checks if the last vertical line drawn made a box or not
            if ( (gridArray[r][c+2][0] == '|')&&(gridArray[r+1][c+1][0] == '-')&&(gridArray[r-1][c+1][0] == '-')&&(gridArray[r][c-2][0] =='|')&&(gridArray[r-1][c-1][0] == '-')&&(gridArray[r+1][c-1][0] == '-') ){
                p[player_id].score += 2;
                count++;                                                                       //if any player draw a box he will continue playing until he did not draw a box so count will remain even or odd
                if (count % 2 == 0) {
                    printf("%c",gridArray[r][c+1][0]= 'A');                                    //player1 Symbol
                    printf("%c",gridArray[r][c-1][0]= 'A');                                    //player1 Symbol
                }
                else {
                    printf("%c",gridArray[r][c+1][0]= 'B');                                    //player2 Symbol
                    printf("%c",gridArray[r][c-1][0]= 'B');                                    //player2 Symbol
                }
            }
            else if ( (gridArray[r][c+2][0] == '|')&&(gridArray[r+1][c+1][0] == '-')&&(gridArray[r-1][c+1][0] == '-') ) {
                p[player_id].score += 1;
                count++;
                if (count % 2 == 0){
                    printf("%c",gridArray[r][c+1][0] = 'A');                                   //player1 Symbol
                }
                else {
                printf("%c",gridArray[r][c+1][0] = 'B');                                       //player2 Symbol
                }
            }
            else if ( (gridArray[r][c-2][0]=='|')&&(gridArray[r-1][c-1][0]=='-')&&(gridArray[r+1][c-1][0]=='-') ) {
                p[player_id].score += 1;
                count++;
                if (count % 2 == 0) {
                    printf("%c",gridArray[r][c-1][0] = 'A');                                   //player1 Symbol
                }
                else {
                    printf("%c",gridArray[r][c-1][0] = 'B');                                   //player2 Symbol
                }
            }
        }
        else if (gridArray[r][c][0]=='-') {                                                    //checks if the last horizontal line drawn made a box or not
            if ( (gridArray[r+2][c][0]=='-')&&(gridArray[r-2][c][0]=='-')&&(gridArray[r+1][c+1][0]=='|')&&(gridArray[r+1][c-1][0]=='|')&&(gridArray[r-1][c+1][0]=='|')&&(gridArray[r-1][c-1][0]=='|') ) {
                p[player_id].score += 2;
                count++;
                if (count % 2 == 0) {
                    printf("%c",gridArray[r+1][c][0] = 'A');                                   //player1 Symbol
                    printf("%c",gridArray[r-1][c][0] = 'A');                                   //player1 Symbol
                }
                else {
                    printf("%c",gridArray[r+1][c][0] = 'B');                                   //player2 Symbol
                    printf("%c",gridArray[r-1][c][0] = 'B');                                   //player2 Symbol
                }
            }
            else if ( (gridArray[r+2][c][0]=='-')&&(gridArray[r+1][c+1][0]=='|')&&(gridArray[r+1][c-1][0]=='|') ) {
                p[player_id].score += 1;
                count++;
                if (count % 2 == 0) {
                    printf("%c",gridArray[r+1][c][0] = 'A');                                   //player1 Symbol
                }
                else {
                    printf("%c",gridArray[r+1][c][0] = 'B');                                   //player2 Symbol
                }
            }
            else if ( (gridArray[r-2][c][0]=='-')&&(gridArray[r-1][c+1][0]=='|')&&(gridArray[r-1][c-1][0]=='|') ) {
                p[player_id].score+=1;
                count++;
                if (count % 2 == 0) {
                    printf("%c",gridArray[r-1][c][0] = 'A');                                   //player1 Symbol
                }
                else {
                    printf("%c",gridArray[r-1][c][0] = 'B');                                   //player2 Symbol
                }
            }
        }

        // Printing Grid Zone by coloring the played lines with the color of the player who plays it

        system("cls");
        printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
        if (gamemode == 1) {
            printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
            printf("\t\t\t     0 1 2 3 4\n");
        }
        else if (gamemode == 2) {
            printf("NOTE: \033[1;34m\'A\' is for Player (1)\033[0m & \033[1;31m\'B\' is for Player (2)\033[0m\n\n");
            printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
        }
        for (int i=0 ; i<n ; i++) {
           if (i != 10) {
                printf("\t\t\t%d    ",i);
            }
            else if (i == 10) {
                printf("\t\t       %d    ",i);
            }
            for (int j=0 ; j<n ; j++) {
                if ( (i%2 == 1)&& (j%2==1)&&(gridArray[i][j][0]=='A') ) {                       //we here check whether the cell saving a character A
                    printf("\033[1;34m");                                                       //using ANSI color of blue
                    printf("%c ",gridArray[i][j][0]);
                    printf("\033[0m");                                                          //using ANSI color of reset
                }
                else if ( (i%2 == 1)&& (j%2 == 1) && (gridArray[i][j][0] == 'B') ) {            //we here check whether the cell saving a character B
                    printf("\033[1;31m");                                                       //using ANSI color of Red
                    printf("%c ",gridArray[i][j][0]);
                    printf("\033[0m");                                                          //using ANSI color of reset
                }
                else if ( (i%2 == 0) && (j%2 == 1 ) && (gridArray[i][j][0] == '-') ) {
                    if (gridArray[i][j][1]==0) {
                        printf("\033[1;34m");                                                   //using ANSI color of blue
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                    else {
                        printf("\033[1;31m");                                                   //using ANSI color of red
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                }
                else if ( (i%2 == 1) && (j%2 == 0 ) && (gridArray[i][j][0] == '|') ) {
                    if (gridArray[i][j][1]==0) {
                        printf("\033[1;34m");                                                  //using ANSI color of blue
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                    else {
                        printf("\033[1;31m");                                                  //using ANSI color of red
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                }
                else {
                printf("%c ",gridArray[i][j][0]);
                }
            }
            printf("\n");
        }

        // Printing The Score and Players Moves

        printf("\n");
        printf("\033[1;34mPlayer (1)\033[0m Score: %d\t\tMoves: %d\n",p[0].score,p1moves);
        printf("\033[1;31mPlayer (2)\033[0m Score: %d\t\tMoves: %d\n",p[1].score,p2moves);

        // Calculating Game Time Elapsed

        end2 = clock();                                                                    // Time
        seconds_of_game= ((double) (end2 - start2)) / CLOCKS_PER_SEC;

        if (seconds_of_game >= 60) {
            minutes_of_game = seconds_of_game / 60;
            tmp = seconds_of_game;                                                         //to keep the value of time of the total game in seconds
            seconds_of_game = tmp - minutes_of_game * 60 ;
        }
        else {
            minutes_of_game = 0 ;
        }

    // Printing # of Remaining Lines and Game Time Elapsed

        printf("\033[0;32m");
        printf("\nRemaining Lines: %d\n",freelines);
        printf("\033[0m");
        printf("\033[1;36m");
        printf("\nGame Time Elapsed: %d Minutes %0.0f Seconds\n" ,minutes_of_game, seconds_of_game);
        printf("\033[0m");

    // Announcing The Winner

        printf("\n");
        if (i == m-1) {
            if (p[0].score > p[1].score) {
                printf("\033[1;34m");
                printf("Player 1 is The WINNER! \n");
                printf("\033[0m");
            }
            else if (p[0].score < p[1].score) {
                printf("\033[1;31m");
                printf("Player 2 is The WINNER!\n");
                printf("\033[0m");
            }
            else {
                printf("\033[1;32m");
                printf("The Game is DRAW! \n");
                printf("\033[0m");
            }
        }
    }

    // Taking Name of The Winner Zone

    if (p[0].score > p[1].score) {
        printf("\n\nPlayer 1 Name: ");
        scanf("%s",p[0].name);
    }
    else if (p[0].score < p[1].score) {
        printf("\n\nPlayer 2 Name: ");
        scanf("%s",p[1].name);
    }

    // Saving Scores and Names of the Winners to Rank File

    Sleep(2500);
    system("cls");
    rank = fopen("Rank.txt" , "a");
    if (p[0].score > p[1].score) {
        fprintf(rank,"%s %d ",p[0].name,p[0].score);
    }
    else if (p[0].score < p[1].score) {
        fprintf(rank,"%s %d ",p[1].name,p[1].score);
    }
    fclose(rank);

    // Loading Scores and Names of Winners from Rank File

    rank = fopen("Rank.txt", "r");
    for(int i=0; i<1000; i++) {
        fscanf(rank,"%s",topGamers[i].name);
        fscanf(rank,"%d",&topGamers[i].score);
    }
    fclose(rank);
    
    // Updating Score of the Same Player

    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            if (strcasecmp(topGamers[i].name, topGamers[j].name) == 0 && topGamers[i].score < topGamers[j].score) {
                topGamers[i].score = 0;
            }
        }
    }

    // Sorting The Top Players Descending

    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            if (topGamers[j].score < topGamers[j+1].score) {
                temp = topGamers[j];
                topGamers[j] = topGamers[j+1];
                topGamers[j+1] = temp;
            }
        }
    }

    // Printing Top 10

    printf("\t\t\tTop 10\n\n");
    printf("\t\t      Name    Score\n\n");
    for (int i=0; i<10; i++) {
        if (i != 9) {
        printf("\t\t(%d)  %s\t%d\n",i+1, topGamers[i].name, topGamers[i].score);
        }
        else {
        printf("\t\t(%d) %s\t%d\n",i+1, topGamers[i].name, topGamers[i].score);
        }
    }
    turn = 0;
    minutes_of_game = 0;
    seconds_of_game = 0;
    p[0].score = 0;
    p[1].score = 0;
    p1moves = 0;
    p2moves = 0;
    start2 = clock();
}
void computer() {
    system("cls");
    FILE *game;
    FILE *rank;

    //Way to make the game able to do Automatic Choosing of saving File

    // Saving certain value to let us do loop for choosing file of saving

    game = fopen("Save0.txt", "r");
    fscanf(game,"%d",&k);
    fflush(stdin);
    fclose(game);

    // loop for choosing the file automatically

    if (k == 1) {
        k = 2;
    }
    else if (k == 2){
        k = 3;
    }
    else if (k == 3) {
        k = 1;
    }

    // loading this value

    game = fopen("Save0.txt", "w");
    fprintf(game,"%d",k);
    fclose(game);

    // Choosing Game Mode

    a21 :
    system("cls");
    printf("(1) Beginner\n(2) Expert\n\n");
    a14 :
    scanf("%d",&gamemode) ;
    fflush(stdin);
    switch (gamemode) {
    case 1 :
        n = 5;                                                                                  // No. of Beginner Array Elements
        m = 12;                                                                                 // No. of Lines can be Connected
        break;
    case 2 :
        n = 11 ;                                                                                // No. of Expert Array Elements
        m = 60 ;                                                                                // No. of Lines can be Connected
        break;
    default :
        printf("Invalid Input Please Enter Again\n\n");
        goto a14;
        break;
    }

    // Checking New Game Or Load Saved Game

    a25 :
    system("cls");
    printf("(1) Start A New Game\n(2) Load Game\n(3) Return\n\n");
    char gridArray[n][n][2];
    a23 :
    scanf("%d",&load);
    fflush(stdin);
    switch (load) {
        case 1 :
            goto a24;
            break;
        case 2 :
            system("cls");
            printf("(1) To Load Game 1\n(2) To Load Game 2\n(3) To Load Game 3\n(4) Return\n\n");
            a22 :
            scanf("%d",&load);
            fflush(stdin);
            switch (load) {
                case 1 :
                    game = fopen("Save4.txt", "r");                                                       //Open Text File with the name "Save1" to load the last saved data of the grid
                    for(int i=0; i<n; i++) {                                                              //Loop for Scanning the saved data of the grid to the game
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][0]);
                        }
                    }
                    for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][1]);
                        }
                    }
                    fscanf(game, "%d", &m);
                    fscanf(game, "%d", &n);
                    fscanf(game, "%d", &p1.score);
                    fscanf(game, "%d", &comp.score);
                    fscanf(game, "%d", &player_id);
                    fscanf(game, "%d", &p1moves);
                    fscanf(game, "%d", &compumoves);
                    fscanf(game, "%d", &count);
                    fscanf(game, "%d", &minutes_of_game);
                    fscanf(game, "%lf", &seconds_of_game);
                    fclose(game);
                    break;
                case 2 :
                    game = fopen("Save5.txt", "r");                                                       //Open Text File with the name "Save2" to load the last saved data of the grid
                    for(int i=0; i<n; i++) {                                                              //Loop for Scanning the saved data of the grid to the game
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][0]);
                        }
                    }
                    for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][1]);
                        }
                    }
                    fscanf(game, "%d", &m);
                    fscanf(game, "%d", &n);
                    fscanf(game, "%d", &p1.score);
                    fscanf(game, "%d", &comp.score);
                    fscanf(game, "%d", &player_id);
                    fscanf(game, "%d", &p1moves);
                    fscanf(game, "%d", &compumoves);
                    fscanf(game, "%d", &count);
                    fscanf(game, "%d", &minutes_of_game);
                    fscanf(game, "%lf", &seconds_of_game);
                    fclose(game);
                    break;
                case 3 :
                    game = fopen("Save6.txt", "r");                                                       //Open Text File with the name "Save3" to load the last saved data of the grid
                    for(int i=0; i<n; i++) {                                                              //Loop for Scanning the saved data of the grid to the game
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][0]);
                        }
                    }
                    for(int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fscanf(game, "%c", &gridArray[i][j][1]);
                        }
                    }
                    fscanf(game, "%d", &m);
                    fscanf(game, "%d", &n);
                    fscanf(game, "%d", &p1.score);
                    fscanf(game, "%d", &comp.score);
                    fscanf(game, "%d", &player_id);
                    fscanf(game, "%d", &p1moves);
                    fscanf(game, "%d", &compumoves);
                    fscanf(game, "%d", &count);
                    fscanf(game, "%d", &minutes_of_game);
                    fscanf(game, "%lf", &seconds_of_game);
                    fclose(game);
                    break;
                case 4 :
                    goto a25;
                    break;
                default :
                    printf("Invalid Input Please Enter Again\n");
                    goto a22;
                    break;
                }

            // Check The Chosen Mode is compatible with Loaded Grid

            if (gamemode == 1 && n == 11) {
                    printf("\nThe Loaded Grid is Greater than Beginner Mode Grid ");
                    Sleep(1500);
                    goto a21;
            }
            else if (gamemode == 2 && n == 5) {
                printf("\nThe Loaded Grid is Smaller than Beginner Mode Grid ");
                Sleep(1500);
                goto a21;
            }
            goto a26;
            break;
        case 3 :
            goto a21;
            break;
        default :
            printf("Invalid Input Please Enter Again\n\n");
            goto a23;
            break;
    }

    // Designing the grid

    a24 :
    for (int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if (i%2 == 0 && j%2 == 0) {
                gridArray[i][j][0] = 254;
            }
            else if (i%2 == 0 && j%2 == 1) {
                gridArray[i][j][0] = ' ' ;
            }
            else if (i%2 == 1 && j%2 == 0) {
                gridArray[i][j][0] = ' ';
            }
            else if (i%2 == 1 && i%2 == 1){
                gridArray[i][j][0] = ' ';
            }
        }
    }

    // Printing the Grid Before The Match

    a26 :
    system("cls");
    if (gamemode == 1) {
        printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
        printf("\t\t\t     0 1 2 3 4\n\n");
    }
    else if (gamemode == 2) {
        printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
        printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
    }
    for (int i=0 ; i<n ; i++) {
        if (i != 10) {
            printf("\t\t\t%d    ",i);
        }
        else if (i == 10) {
            printf("\t\t       %d    ",i);
        }
        for (int j=0 ; j<n ; j++) {
            printf("%c ",gridArray[i][j][0]);
        }
        printf("\n");
    }
    printf("\n");

    // Loop of The Game

    for( int i=0 ; i<m ; i++) {
        a16:
        cpu_time_used = 0;
        if (gamemode == 1) {
            if ((count % 2) == 0) {
                printf("\n\t\t\t\033[1;34mPlayer\033[0m Turn\n\n");
            }
            else {
                printf("\n\t\t\t\033[1;31mComputer\033[0m Turn\n\n");
            }
        }
        else if (gamemode == 2) {
            if ((count % 2) == 0) {
                printf("\n         \t\t\t\033[1;34mPlayer\033[0m Turn\n\n");
            }
            else {
                printf("\n         \t\t\t\033[1;31mComputer\033[0m Turn\n\n");
            }
        }

        // Asking Player to enter coordinates of the required connected lines

        if (count % 2 == 0) {                                                                                   //Player 1 enters is row and and column
            printf("Enter Row Then Column of Required Line [example: 0 3] --> ");
            a17 :
            start = clock();                                                                                    //the beginning of counting
            scanf("%d %d",&r,&c);                                                                               //r = row , c = column
            fflush(stdin);
            end = clock();                                                                                      //the end of counting
            cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

            // Undo Your Move and computer Move

            if (r == 0 && c == 0) {
            }
            else {
                r1 = r;
                c1 = c;
            }
            if (i>0) {
                if ( r == 0 && c == 0 ) {
                    gridArray[r1][c1][0] = ' ';
                    gridArray[r2][c2][0] = ' ';

                    // printing the grid after doing undo

                    system("cls");
                    if (gamemode == 1) {
                        printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                        printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
                        printf("\t\t\t     0 1 2 3 4\n");
                    }
                    else if (gamemode == 2) {
                        printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                        printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
                        printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
                    }
                    for (int i=0 ; i<n ; i++) {
                       if (i != 10) {
                            printf("\t\t\t%d    ",i);
                        }
                        else if (i == 10) {
                            printf("\t\t       %d    ",i);
                        }
                        for (int j=0 ; j<n ; j++) {
                            if ( (i%2 == 1)&& (j%2==1)&&(gridArray[i][j][0]=='A') ) {                       //we here check whether the cell saving a character A
                                printf("\033[1;34m");                                                       //using ANSI color of blue
                                printf("%c ",gridArray[i][j][0]);
                                printf("\033[0m");                                                          //using ANSI color of reset
                            }
                            else if ( (i%2 == 1)&& (j%2 == 1) && (gridArray[i][j][0] == 'B') ) {            //we here check whether the cell saving a character B
                                printf("\033[1;31m");                                                       //using ANSI color of Red
                                printf("%c ",gridArray[i][j][0]);
                                printf("\033[0m");                                                          //using ANSI color of reset
                            }
                            else if ( (i%2 == 0) && (j%2 == 1 ) && (gridArray[i][j][0] == '-') ) {
                                if (gridArray[i][j][1]==0) {
                                    printf("\033[1;34m");                                                   //using ANSI color of blue
                                    printf("%c ",gridArray[i][j][0]);
                                    printf("\033[0m");
                                }
                                else {
                                    printf("\033[1;31m");                                                   //using ANSI color of red
                                    printf("%c ",gridArray[i][j][0]);
                                    printf("\033[0m");
                                }
                            }
                            else if ( (i%2 == 1) && (j%2 == 0 ) && (gridArray[i][j][0] == '|') ) {
                                if (gridArray[i][j][1]==0) {
                                    printf("\033[1;34m");                                                  //using ANSI color of blue
                                    printf("%c ",gridArray[i][j][0]);
                                    printf("\033[0m");
                                }
                                else {
                                    printf("\033[1;31m");                                                  //using ANSI color of red
                                    printf("%c ",gridArray[i][j][0]);
                                    printf("\033[0m");
                                }
                            }
                            else {
                            printf("%c ",gridArray[i][j][0]);
                            }
                        }
                        printf("\n");
                    }
                    turn=turn-2;
                    if (count % 2 == 0) {
                        p1moves-- ;
                    }
                    else {
                        compumoves-- ;
                    }
                    compumoves--;
                    i=i-2;
                    printf("\n(1) To Redo\n(2) Enter New Line\n\n ");
                    a28 :
                    scanf("%d",&load);
                    fflush(stdin);
                    switch (load) {
                        case 1 :
                            for(int i=0 ; i<n ; i++) {
                                for(int j=0 ; j<n ; j++) {
                                    if (r1 == i && c1 == j) {
                                        if (i%2 == 0 && j%2 == 1) {
                                            gridArray[r1][c1][0] = '-';
                                            gridArray[r1][c1][1] = 0;
                                        }
                                        else if (i%2 == 1 && j%2 == 0) {
                                            gridArray[r1][c1][0] = '|';
                                            gridArray[r1][c1][1] = 0;
                                        }
                                    }
                                }
                            }
                            system("cls");

                            // printing the grid after doing redo

                            if (gamemode == 1) {
                                printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                                printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
                                printf("\t\t\t     0 1 2 3 4\n");
                            }
                            else if (gamemode == 2) {
                                printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
                                printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
                                printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
                            }
                            for (int i=0 ; i<n ; i++) {
                               if (i != 10) {
                                    printf("\t\t\t%d    ",i);
                                }
                                else if (i == 10) {
                                    printf("\t\t       %d    ",i);
                                }
                                for (int j=0 ; j<n ; j++) {
                                    if ( (i%2 == 1)&& (j%2==1)&&(gridArray[i][j][0]=='A') ) {                       //we here check whether the cell saving a character A
                                        printf("\033[1;34m");                                                       //using ANSI color of blue
                                        printf("%c ",gridArray[i][j][0]);
                                        printf("\033[0m");                                                          //using ANSI color of reset
                                    }
                                    else if ( (i%2 == 1)&& (j%2 == 1) && (gridArray[i][j][0] == 'B') ) {            //we here check whether the cell saving a character B
                                        printf("\033[1;31m");                                                       //using ANSI color of Red
                                        printf("%c ",gridArray[i][j][0]);
                                        printf("\033[0m");                                                          //using ANSI color of reset
                                    }
                                    else if ( (i%2 == 0) && (j%2 == 1 ) && (gridArray[i][j][0] == '-') ) {
                                        if (gridArray[i][j][1]==0) {
                                            printf("\033[1;34m");                                                   //using ANSI color of blue
                                            printf("%c ",gridArray[i][j][0]);
                                            printf("\033[0m");
                                        }
                                        else {
                                            printf("\033[1;31m");                                                   //using ANSI color of red
                                            printf("%c ",gridArray[i][j][0]);
                                            printf("\033[0m");
                                        }
                                    }
                                    else if ( (i%2 == 1) && (j%2 == 0 ) && (gridArray[i][j][0] == '|') ) {
                                        if (gridArray[i][j][1]==0) {
                                            printf("\033[1;34m");                                                  //using ANSI color of blue
                                            printf("%c ",gridArray[i][j][0]);
                                            printf("\033[0m");
                                        }
                                        else {
                                            printf("\033[1;31m");                                                  //using ANSI color of red
                                            printf("%c ",gridArray[i][j][0]);
                                            printf("\033[0m");
                                        }
                                    }
                                    else {
                                    printf("%c ",gridArray[i][j][0]);
                                    }
                                }
                                printf("\n");
                            }
                            i=i+1;
                            count++;
                            if (count % 2 == 1) {
                                p1moves++ ;
                            }
                            else {
                                compumoves++ ;
                            }
                            turn = turn+1;
                            break;
                        case 2 :
                            goto a16;
                            break;
                        default :
                            printf("Invalid Input Please Enter Again\n\n");
                            goto a28;
                            break;
                    }
                    goto a16;
                }
            }

            // Saving in File 4

            if (r == 1 && c == 1) {
                game = fopen("Save4.txt", "w");
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][0]);
                    }
                }
                for (int i=0; i<n; i++) {
                    for(int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][1]);
                    }
                }
                fprintf(game,"%d\n",freelines);
                fprintf(game,"%d\n",n);
                fprintf(game,"%d\n",p1.score);
                fprintf(game,"%d\n",comp.score);
                fprintf(game,"%d\n",player_id);
                fprintf(game,"%d\n",p1moves);
                fprintf(game,"%d\n",compumoves);
                fprintf(game,"%d\n",count);
                fprintf(game,"%d\n",minutes_of_game);
                fprintf(game,"%lf\n",seconds_of_game);
                fclose(game);
                goto a16;
            }

            // Saving in File 5

            if (r == 2 && c == 2 ) {
                game = fopen("Save5.txt", "w");
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][0]);
                    }
                }
                for (int i=0; i<n; i++) {
                    for(int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][1]);
                    }
                }
                fprintf(game,"%d\n",freelines);
                fprintf(game,"%d\n",n);
                fprintf(game,"%d\n",p1.score);
                fprintf(game,"%d\n",comp.score);
                fprintf(game,"%d\n",player_id);
                fprintf(game,"%d\n",p1moves);
                fprintf(game,"%d\n",compumoves);
                fprintf(game,"%d\n",count);
                fprintf(game,"%d\n",minutes_of_game);
                fprintf(game,"%lf\n",seconds_of_game);
                fclose(game);
                goto a16;
            }

            // Saving in File 6

            if (r == 3 && c == 3 ) {
                game = fopen("Save6.txt", "w");
                for (int i=0; i<n; i++) {
                    for (int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][0]);
                    }
                }
                for (int i=0; i<n; i++) {
                    for(int j=0; j<n; j++) {
                        fprintf (game,"%c",gridArray[i][j][1]);
                    }
                }
                fprintf(game,"%d\n",freelines);
                fprintf(game,"%d\n",n);
                fprintf(game,"%d\n",p1.score);
                fprintf(game,"%d\n",comp.score);
                fprintf(game,"%d\n",player_id);
                fprintf(game,"%d\n",p1moves);
                fprintf(game,"%d\n",compumoves);
                fprintf(game,"%d\n",count);
                fprintf(game,"%d\n",minutes_of_game);
                fprintf(game,"%lf\n",seconds_of_game);
                fclose(game);
                goto a16;
            }

            // Saving in Any File

            if (r == 4 && c == 4) {
                if (k == 1) {
                    game = fopen("Save4.txt", "w");
                    for (int i=0; i<n; i++) {
                        for (int j=0; j<n; j++) {
                            fprintf (game,"%c",gridArray[i][j][0]);
                        }
                    }
                    for (int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fprintf (game,"%c",gridArray[i][j][1]);
                        }
                    }
                    fprintf(game,"%d\n",freelines);
                    fprintf(game,"%d\n",n);
                    fprintf(game,"%d\n",p1.score);
                    fprintf(game,"%d\n",comp.score);
                    fprintf(game,"%d\n",player_id);
                    fprintf(game,"%d\n",p1moves);
                    fprintf(game,"%d\n",compumoves);
                    fprintf(game,"%d\n",count);
                    fprintf(game,"%d\n",minutes_of_game);
                    fprintf(game,"%lf\n",seconds_of_game);
                    fclose(game);
                }
                else if (k == 2) {
                    game = fopen("Save5.txt", "w");
                    for (int i=0; i<n; i++) {
                        for (int j=0; j<n; j++) {
                            fprintf (game,"%c",gridArray[i][j][0]);
                        }
                    }
                    for (int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fprintf (game,"%c",gridArray[i][j][1]);
                        }
                    }
                    fprintf(game,"%d\n",freelines);
                    fprintf(game,"%d\n",n);
                    fprintf(game,"%d\n",p1.score);
                    fprintf(game,"%d\n",comp.score);
                    fprintf(game,"%d\n",player_id);
                    fprintf(game,"%d\n",p1moves);
                    fprintf(game,"%d\n",compumoves);
                    fprintf(game,"%d\n",count);
                    fprintf(game,"%d\n",minutes_of_game);
                    fprintf(game,"%lf\n",seconds_of_game);
                    fclose(game);
                }
                else if (k == 3) {
                    game = fopen("Save6.txt", "w");
                    for (int i=0; i<n; i++) {
                        for (int j=0; j<n; j++) {
                            fprintf (game,"%c",gridArray[i][j][0]);
                        }
                    }
                    for (int i=0; i<n; i++) {
                        for(int j=0; j<n; j++) {
                            fprintf (game,"%c",gridArray[i][j][1]);
                        }
                    }
                    fprintf(game,"%d\n",freelines);
                    fprintf(game,"%d\n",n);
                    fprintf(game,"%d\n",p1.score);
                    fprintf(game,"%d\n",comp.score);
                    fprintf(game,"%d\n",player_id);
                    fprintf(game,"%d\n",p1moves);
                    fprintf(game,"%d\n",compumoves);
                    fprintf(game,"%d\n",count);
                    fprintf(game,"%d\n",minutes_of_game);
                    fprintf(game,"%lf\n",seconds_of_game);
                    fclose(game);
                }
                goto a16;
            }

            // Checking the entered point of the user

            while ( ((r%2==0) && (c%2==0)) || ((r%2==1) && (c%2==1)) || (r>=n) || (c>=n) || (r<0) || (c<0)|| (isalpha(r)) || (isalpha(c)) || (gridArray[r][c][0] == '|') || (gridArray[r][c][0] == '-') ) {
                printf("\n\'\033[1;31mInvalid Input\033[0m\' Enter again Row Then Column Of Required Line [Example: 0 3] --> ");
                goto a17;
            }

            // printing the taken time for every turn

            if ((count % 2) == 0) {
                printf("\nTurn Time Elapsed for \033[1;34mPlayer\033[0m :\033[1;34m %0.0f Seconds\033[0m\n", cpu_time_used);
            }
            Sleep(1000);
            printf("\n");
            cpu_time_used = 0;

            // Logic of entering data to the grid by the user

            for(int i=0 ; i<n ; i++ ) {
                for(int j=0 ; j<n ; j++) {
                    if (r == i && c == j) {
                        if (i%2 == 0 && j%2 == 1) {
                            gridArray[r][c][0] = '-';
                            gridArray[r][c][1] = 0 ;
                        }
                        else if (i%2 == 1 && j%2 == 0) {
                            gridArray[r][c][0] = '|';
                            gridArray[r][c][1] = 0 ;
                        }
                    }
                }
            }
        }

        // Scanning computer play

        else if (count % 2 == 1) {                                                             //computer plays random line
            do {                                                                               //loop until the computer draw a correct line
                Sleep(500) ;
                r = rand() % n ;                                                               //chooses ranodom r(row) and random c(column)
                c = rand() % n ;
            }
            while ( (gridArray[r][c][0] == '-') || (gridArray[r][c][0] == '|') || ((r%2 == 0) && (c%2 == 0)) || ((r%2 == 1) && (c%2 == 1)) ); //checks if it's a true place to draw line
            r2 = r ;
            c2 = c ;
            for(int i=0 ; i<n ; i++ ) {
                for(int j=0 ; j<n ; j++) {
                    if (r == i && c == j) {
                        if (i%2 == 0 && j%2 == 1) {                                           //assign the true line in the memory
                            gridArray[r][c][0] = '-';
                            gridArray[r][c][1] = 1 ;
                        }
                        else if (i%2 == 1 && j%2 == 0) {
                            gridArray[r][c][0] = '|';
                            gridArray[r][c][1] = 1 ;
                        }
                    }
                }
            }
        }

        // counting moves for each player

        if (count % 2 == 0) {
            p1moves++ ;
        }
        else {
            compumoves++ ;
        }
        count ++ ;
        turn++ ;

        // Logic of closing boxes and increasing score accompanying it

        if (gridArray[r][c][0] == '|') {                                                       //checks if the last vertical line drawn made a box or not
            if((gridArray[r][c+2][0]=='|')&&(gridArray[r+1][c+1][0]=='-')&&(gridArray[r-1][c+1][0]=='-')&&(gridArray[r][c-2][0]=='|')&&(gridArray[r-1][c-1][0] == '-')&&(gridArray[r+1][c-1][0] =='-')){
                count++;                                                                      // if any player drew a box he will continue playing until he did not drew a box so count will remain even or odd
                if (count % 2 == 0) {
                    p1.score += 2;
                    printf("%c",gridArray[r][c+1][0] = 'A');
                    printf("%c",gridArray[r][c-1][0] = 'A');
                }
                else {
                    comp.score += 2 ;
                    printf("%c",gridArray[r][c+1][0] = 'C');
                    printf("%c",gridArray[r][c-1][0] = 'C');
                }
            }
            else if ((gridArray[r][c+2][0]=='|')&&(gridArray[r+1][c+1][0]=='-')&&(gridArray[r-1][c+1][0]=='-')) {
                count++;
                if (count % 2 == 0) {
                    p1.score++;
                    printf("%c",gridArray[r][c+1][0] = 'A');
                }
                else {
                    comp.score++ ;
                    printf("%c",gridArray[r][c+1][0] = 'C');
                }
            }
            else if ((gridArray[r][c-2][0] =='|')&&(gridArray[r-1][c-1][0] =='-')&&(gridArray[r+1][c-1][0] =='-')) {
                count++;
                if (count % 2 == 0) {
                    p1.score++;
                    printf("%c",gridArray[r][c-1][0] = 'A');
                }
                else {
                    comp.score++;
                    printf("%c",gridArray[r][c-1][0] = 'C');
                }
            }
        }
        else if (gridArray[r][c][0]=='-') {                                                      //checks if the last horzintal line drawn made a box or not
            if ((gridArray[r+2][c][0] =='-')&&(gridArray[r-2][c][0]=='-')&&(gridArray[r+1][c+1][0]=='|')&&(gridArray[r+1][c-1][0]=='|')&&(gridArray[r-1][c+1][0]=='|')&&(gridArray[r-1][c-1][0]=='|')){
                count++;
                if (count % 2 == 0) {
                    p1.score+=2;
                    printf("%c",gridArray[r+1][c][0] = 'A');
                    printf("%c",gridArray[r-1][c][0] = 'A');
                }
                else {
                    comp.score+=2;
                    printf("%c",gridArray[r+1][c][0] = 'C');
                    printf("%c",gridArray[r-1][c][0] = 'C');
                }
            }
            else if ((gridArray[r+2][c][0]=='-')&&(gridArray[r+1][c+1][0] =='|')&&(gridArray[r+1][c-1][0] =='|')) {
                count++;
                if (count % 2 == 0) {
                    p1.score+=1;
                    printf("%c",gridArray[r+1][c][0] = 'A');
                }
                else {
                    comp.score++ ;
                    printf("%c",gridArray[r+1][c][0] = 'C');
                }
            }
            else if ((gridArray[r-2][c][0] =='-')&&(gridArray[r-1][c+1][0] =='|')&&(gridArray[r-1][c-1][0] =='|')) {
                count++;
                if (count % 2 == 0) {
                    p1.score++;
                    printf("%c",gridArray[r-1][c][0] = 'A');
                }
                else {
                    comp.score++ ;
                    printf("%c",gridArray[r-1][c][0] = 'C');
                }
            }
        }

        // Printing Grid Zone by coloring the played lines with the color of the player who plays it

        system("cls");
        printf("\nInstructions:\n\033[1;34mUndo\033[0m [0 0]\t\033[1;31mSave in file1\033[0m [1 1]\t\033[1;34mSave in file2\033[0m [2 2]\t\033[1;31mSave in file3\033[0m [3 3]\t\033[1;34mSave in any file\033[0m [4 4]\n\n ");
        if (gamemode == 1) {
            printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
            printf("\t\t\t     0 1 2 3 4\n");
        }
        else if (gamemode == 2) {
            printf("NOTE: \033[1;34m\'A\' is for Player \033[0m & \033[1;31m\'C\' is for Computer\033[0m\n\n");
            printf("\t\t\t     0 1 2 3 4 5 6 7 8 9 10\n");
        }
        for (int i=0 ; i<n ; i++) {
            if (i != 10) {
                printf("\t\t\t%d    ",i);
            }
            else if (i == 10) {
                printf("\t\t       %d    ",i);
            }
            for (int j=0 ; j<n ; j++) {
                if ( (i%2 == 1)&& (j%2==1)&&(gridArray[i][j][0]=='A') ) {                   //we here check whether the cell saving a character A
                    printf("\033[1;34m");                                                   //using ANSI color of blue
                    printf("%c ",gridArray[i][j][0]);
                    printf("\033[0m");                                                      //using ANSI color of reset
                }
                else if ( (i%2 == 1)&& (j%2 == 1) && (gridArray[i][j][0] == 'C') ) {        //we here check whether the cell saving a character B
                    printf("\033[1;31m");                                                   //using ANSI color of Red
                    printf("%c ",gridArray[i][j][0]);
                    printf("\033[0m");                                                      //using ANSI color of reset
                }
                else if ( (i%2 == 0) && (j%2 == 1 ) && (gridArray[i][j][0] == '-') ) {
                    if (gridArray[i][j][1]==0) {
                        printf("\033[1;34m");                                               //using ANSI color of blue
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                    else {
                        printf("\033[1;31m");                                               //using ANSI color of red
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                }
                else if ( (i%2 == 1) && (j%2 == 0 ) && (gridArray[i][j][0] == '|') ) {
                    if (gridArray[i][j][1]==0) {
                        printf("\033[1;34m");                                               //using ANSI color of blue
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                    else {
                        printf("\033[1;31m");                                               //using ANSI color of red
                        printf("%c ",gridArray[i][j][0]);
                        printf("\033[0m");
                    }
                }
                else {
                printf("%c ",gridArray[i][j][0]);                                           //we here check whether the cell saving a character '-' or '|'
                }
            }
            printf("\n");
        }

        freelines = m - turn ;

        // Printing The Score and Players Moves

        printf("\n");
        printf("\033[1;34mPlayer\033[0m   Score: %d\t\tMoves: %d\n",p1.score,p1moves);
        printf("\033[1;31mComputer\033[0m Score: %d\t\tMoves: %d\n",comp.score,compumoves);

        // Calculating Game Time Elapsed

        end2 = clock();                                                                    // Time
        seconds_of_game= ((double) (end2 - start2)) / CLOCKS_PER_SEC;

        if (seconds_of_game >= 60) {
            minutes_of_game = seconds_of_game / 60;
            tmp = seconds_of_game;                                                         //to keep the value of time of the total game in seconds
            seconds_of_game = tmp - minutes_of_game * 60 ;
        }
        else {
            minutes_of_game = 0 ;
        }

    // Printing # of Remaining Lines and Game Time Elapsed

        printf("\033[0;32m");
        printf("\nRemaining Lines: %d\n",freelines);
        printf("\033[0m");
        printf("\033[1;36m");
        printf("\nGame Time Elapsed: %d Minutes %0.0f Seconds\n" ,minutes_of_game, seconds_of_game);
        printf("\033[0m");


    // Announcing The Winner

        printf("\n");
        if (i == m-1) {
            if (p1.score > comp.score) {
                printf("\033[1;34m");
                printf("You are The WINNER!\n");
                printf("\033[0m");
            }
            else if (p1.score < comp.score) {
                printf("\033[1;31m");
                printf("Computer is The WINNER!\n");
                printf("\033[0m");
            }
            else {
                printf("\033[1;32m");
                printf("The Game is DRAW!\n");
                printf("\033[0m");
            }
        }
    }

    // Taking Name of The Winner Zone

    if (p1.score > comp.score) {
        printf("\n\nYour Name: ");
        scanf("%s",p1.name);
    }

    // Saving Scores and Names of the Winners to Rank File

    Sleep(2500);
    system("cls");
    rank = fopen("Rank.txt" , "a");
    if (p1.score > comp.score) {
        fprintf(rank,"%s %d ",p1.name,p1.score);
    }
    fclose(rank);

    // Loading Scores and Names of Winners from Rank File

    rank = fopen("Rank.txt" , "r");
    for(int i=0; i<1000; i++) {
        fscanf(rank,"%s",topGamers[i].name);
        fscanf(rank,"%d",&topGamers[i].score);
    }
    fclose(rank);

    // Updating Score of the Same Player

    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            if (strcasecmp(topGamers[i].name, topGamers[j].name) == 0 && topGamers[i].score < topGamers[j].score) {
                topGamers[i].score = 0;
            }
        }
    }

    // Sorting The Top Players Descending

    for(int i=0; i<1000; i++) {
        for(int j=0; j<1000; j++) {
            if (topGamers[j].score < topGamers[j+1].score) {
                temp = topGamers[j];
                topGamers[j] = topGamers[j+1];
                topGamers[j+1] = temp;
            }
        }
    }

    // Printing Top 10

    printf("\t\t\tTop 10\n\n");
    printf("\t\t      Name    Score\n\n");
    for (int i=0; i<10; i++) {
        if (i != 9) {
        printf("\t\t(%d)  %s\t%d\n",i+1, topGamers[i].name, topGamers[i].score);
        }
        else {
        printf("\t\t(%d) %s\t%d\n",i+1, topGamers[i].name, topGamers[i].score);
        }
    }
    turn = 0;
    minutes_of_game = 0;
    seconds_of_game = 0;
    p1.score = 0;
    comp.score = 0;
    p1moves = 0;
    compumoves = 0;
    start2 = clock();
}

int main()
{
    system("cls");
    FILE *tank;
    printf("\n");
    HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE); // to make the color of the logo be blue
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
    printf("                                                                                                              \n\n");
    printf(" __________        ________   __________   _________          __________   _____      __    ___________               \n");
    printf("|  _______ \\      |  ____  | |___    ___| |   ______\\        |    ___   | |     \\    |  |  |  ________ \\              \n");
    printf("| |       \\ \\     | |    | |     |  |     |  |               |   |   |  | |   _  \\   |  |  | |        \\ \\             \n");
    printf("| |        \\ \\    | |    | |     |  |      |  |              |   |   |  | |  | \\  \\  |  |  | |         \\ \\            \n");
    printf("| |         \\ \\   | |    | |     |  |       |  |             |   |___|  | |  |  \\  \\ |  |  | |          \\ \\           \n");
    printf("| |          \\ \\  | |    | |     |  |        |  |            |   ____   | |  |   \\  \\|  |  | |           \\ \\          \n");
    printf("| |          / /  | |    | |     |  |     _   |  |           |  |    |  | |  |    \\  \\  |  | |           / /           \n");
    printf("| |         / /   | |    | |     |  |    | |   |  |          |  |    |  | |  |     \\    |  | |          / /            \n");
    printf("| |________/ /    | |____| |     |  |    | |____|  |         |  |    |  | |  |      \\   |  | |_________/ /             \n");
    printf("|___________/     |________|     |__|    |_________|         |__|    |__| |__|       \\__|  |____________/             \n\n");

    printf(" ___________      ________   ___        ___   _______    ___________      \n");
    printf("|  _______  \\    |  ____  |  \\  \\      /  /  |       |  |    _______\\           \n");
    printf("| |       \\  \\   | |    | |   \\  \\    /  /   |  _____|   |  |                     \n");
    printf("| |        \\  \\  | |    | |    \\  \\  /  /    | |          |  |             \n");
    printf("| |_________\\  \\ | |    | |     \\  \\/  /     | |____       |  |           \n");
    printf("|  ________    | | |    | |     |      |     |  ____|        |  |\n");
    printf("| |        /  /  | |    | |     /  /\\  \\     | |         _    |  |\n");
    printf("| |       /  /   | |    | |    /  /  \\  \\    | |____    | |    |  |\n");
    printf("| |______/  /    | |____| |   /  /    \\  \\   |      |   | |_____|  | \n");
    printf("|__________/     |________|  /__/      \\__\\  |______|   |__________|  \n\n\n");
    SetConsoleTextAttribute(hConSole,saved_attributes); //to return the color of the console to its original color
    printf("                  Loading....\n"); //to give the user the exciting of the loading of the game
    Sleep(3500);  //to give the user the exciting of the loading of the game
    system("cls");
    a1 :
    printf("\033[1;34m");
    printf("Dots");
    printf("\033[0m");
    printf(" & ");
    printf("\033[1;31m");
    printf("Boxes\n\n");
    printf("\033[0m");
    printf("(1) Start Game\n");
    printf("(2) How To Play\n");
    printf("(3) Top 10\n");
    printf("(4) Quit\n\n");
    a5 :
    scanf("%d",&menu);
    fflush(stdin);
    switch(menu){
        case 1 :
            system("cls");
            printf("(1) Player 1 vs Player 2\n");
            printf("(2) Player vs Computer \n");
            printf("(3) Return To Main Menu\n\n");
            a2:
            scanf("%d",&startGame);
            fflush(stdin);
            switch (startGame) {
                case 1 :
                    human() ;
                    printf("\n\n(1) Return To Main Menu\n");
                    printf("(2) Quit\n\n");
                    a8 :
                    scanf("%d",&menu);
                    fflush(stdin);
                    switch(menu) {
                        case 1 :
                            system("cls");
                            goto a1;
                            break;
                        case 2 :
                            return 0;
                            break;
                        default :
                            printf("Invalid Input Please Enter Again\n");
                            goto a8;
                            break;
                    }
                    break;
                case 2 :
                    computer() ;
                    printf("\n\n(1) Return To Main Menu\n");
                    printf("(2) Quit\n\n");
                    a18 :
                    scanf("%d",&menu);
                    fflush(stdin);
                    switch(menu) {
                        case 1 :
                            system("cls");
                            goto a1;
                            break;
                        case 2 :
                            return 0;
                            break;
                        default :
                            printf("Invalid Input Please Enter Again\n");
                            goto a18;
                            break;
                    }
                    break;
                case 3 :
                    system("cls");
                    goto a1;
                    break;
                default :
                    printf("Invalid Input Please Enter Again\n");
                    goto a2;
                    break;
            }
            break;
        case 2 :
            system("cls");
            printf("\t\t\t How To Play\n\n");
            printf("\033[0;32m");
            printf("(1) To gain point : you should close a square of size 1x1\n(2) When you get a point you will have an extra move\n\nHow to input:\n\n- You enter the number of the row of the line on the grid then space then\n  you enter the number of the column of the same line on the grid then press Enter.\n\nSome notes for playing:\n\n1 - To undo a play , you should enter '0 0' in the input.\n2 - To save the game in file number 1  , you should enter  '1 1' in the input.\n3 - To save the game in file number 2  , you should enter  '2 2' in the input.\n4 - To save the game in file number 3  , you should enter  '3 3' in the input.\n5 - To save the game in a  file chosen randomly , you should enter  '4 4' in the input.\n6 - To load saved game , choose 'Start Game' from the menu and then whether the saved game was\n    played between 2 players or between a player and the computer and then choose game mode then\n    choose the game number (game number1 or game number2 or game number3 ).\n");
            printf("\033[0;33m");
            printf("\n\n(1) Return To Main Menu\n\n");
            printf("\033[0m");

            a7 :
            scanf("%d",&menu);
            fflush(stdin);
            switch(menu) {
                case 1 :
                    system("cls");
                    goto a1;
                    break;
                default :
                    printf("Invalid Input Please Enter Again\n");
                    goto a7;
                    break;
            }
            break;
        case 3 :
            system("cls");
            tank = fopen("Rank.txt" , "r");
            for(int i=0; i<1000; i++) {
            fscanf(tank,"%s",topGamers[i].name);
            fscanf(tank,"%d",&topGamers[i].score);
            }
            fclose(tank);
            for(int i=0; i<1000; i++) {
                for(int j=0; j<1000; j++) {
                    if (strcasecmp(topGamers[i].name, topGamers[j].name) == 0 && topGamers[i].score < topGamers[j].score) {
                        topGamers[i].score = 0;
                    }
                }
            }
            for(int i=0; i<1000; i++) {
                for(int j=0; j<1000; j++) {
                    if (topGamers[j].score < topGamers[j+1].score) {
                        temp = topGamers[j];
                        topGamers[j] = topGamers[j+1];
                        topGamers[j+1] = temp;
                    }
                }
            }
            printf("\t\t\t Top 10\n\n");
            printf("\t\t      Name    Score\n\n");
            for (int i=0; i<10; i++) {
                if (i != 9) {
                    printf("\t\t(%d)  %s\t%d\n",i+1,topGamers[i].name,topGamers[i].score);
                }
                else {
                    printf("\t\t(%d) %s\t%d\n",i+1,topGamers[i].name,topGamers[i].score);
                }
            }
            printf("\n\n(1) Return To Main Menu\n\n");
            a6 :
            scanf("%d",&menu);
            fflush(stdin);
            switch(menu) {
                case 1 :
                    system("cls");
                    goto a1;
                    break;
                default :
                    printf("Invalid Input Please Enter Again\n");
                    goto a6;
                    break;
            }
            break;
        case 4 :
            return 0;
            break;
        default :
            printf("Invalid Input Please Enter Again\n");
            goto a5;
            break;
    }
    return 0;
}
