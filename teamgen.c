#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <windows.h>

// Defining paddings
#define LP 5
#define TP 3
#define RP 100
#define MAX 100

// Function prototypes and their short descriptions as a comment
void navBar(char *title, char *institution, char *section);
void contentBorders(void);
int mainMenu(void);
void runPrograms(int key);
void addWord();
void editWord();
void deleteWord();
void viewBank(int key);
void addBank();
void deleteBank();
void viewAllBanks(int key);
void teamGenerate();
void wordPick();

FILE *banks, *tp, *fp;

struct wordbank
{
    char word[100];
} st[55];


void gotoxy(int x,int y){
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    int choice = 11;

    while (choice == 11)
    {
        choice = mainMenu();
    }

    runPrograms(choice);

    if (choice == 10)
        return 0;
        // Thank you page

    // This just moves the return message way down
    gotoxy(13, 50);
    return 0;
}

void navBar(char *title, char *institution, char *section)
{
    system("COLOR 01");
    // Left and Right Borders
    for(int i = TP; i < 7; i++)
    {
        gotoxy(LP, i);
        printf("%c", 186);
    }
    for(int i = TP; i < 7; i++)
    {
        gotoxy(RP, i);
        printf("%c", 186);
    }
    // Top and Bottom Borders
    for(int i = LP; i < 100; i++)
    {
        gotoxy(i, 2);
        printf("%c", 205);
    }
    for(int i = LP; i < 100; i++)
    {
        gotoxy(i, 7);
        printf("%c", 196);
    }

    // Corners
    gotoxy(5, 2);
    printf("%c", 201);
    gotoxy(100, 2);
    printf("%c", 187);
    gotoxy(5, 7);
    printf("%c", 211);
    gotoxy(100, 7);
    printf("%c", 189);


    // Texts
    gotoxy((((LP + RP) / 2) - (strlen(institution) / 2)), TP + 1);
    printf("%s", institution);
    gotoxy((((LP + RP) / 2) - (strlen(section) / 2)), TP + 2);
    printf("%s", section);
    gotoxy((((LP + RP) / 2) - (strlen(title) / 2)), 7);
    for(int i = 0; i < strlen(title); i++){
        for(int j = 0; j < 10000000; j++);
        printf("%c", title[i]);//219
    }
}

int mainMenu(void)
{
    system("cls");
    navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");

    char *options = malloc(sizeof(char) * 50);
    char choice[1];

    contentBorders();

    char *subtitle = malloc(sizeof(char) * 50);
    subtitle = "Main Menu";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    options = "1 ) Add to the bank (/)";
    gotoxy(LP + 18, TP + 9);
    printf("%s", options);

    options = "2 ) Edit a member (/)";
    gotoxy(LP + 18, TP + 11);
    printf("%s", options);

    options = "3 ) Delete a member (/)";
    gotoxy(LP + 18, TP + 13);
    printf("%s", options);

    options = "4 ) View bank (/)";
    gotoxy(LP + 18, TP + 15);
    printf("%s", options);

    options = "5 ) Add more bank (/)";
    gotoxy(LP + 18, TP + 17);
    printf("%s", options);

    options = "(/) Delete a bank ( 6";
    gotoxy(RP - (20 + strlen(options)), TP + 9);
    printf("%s", options);

    options = "(/) View all banks ( 7";
    gotoxy(RP - (20 + strlen(options)), TP + 11);
    printf("%s", options);

    options = "(/) Random team generator ( 8";
    gotoxy(RP - (20 + strlen(options)), TP + 13);
    printf("%s", options);

    options = "(/) Random pick ( 9";
    gotoxy(RP - (20 + strlen(options)), TP + 15);
    printf("%s", options);

    options = "Exit ( 10";
    gotoxy(RP - (20 + strlen(options)), TP + 17);
    printf("%s", options);

    // User Prompt
    gotoxy(LP + 4, TP + 25);
    printf("Enter your choice: ");
    scanf("%s", &choice);
    getchar();

    int int_choice = atoi(choice);
    if (int_choice != 0)
    {
        if (int_choice < 0 || int_choice > 10)
        {
            gotoxy(LP + 4, TP + 25);
            printf("Enter a number between the given choices.");
            getchar();
            return 9;
        }
        return int_choice;
    }
    else if (int_choice == 0)
    {
        gotoxy(LP + 4, TP + 25);
        printf("Are you entering a character or a '0'? owo Please don't!");
        getchar();
        return 9;
    }

    free(options);
}

void runPrograms(int choice)
{
    if (choice == 1)
        addWord();
    else if (choice == 2)
        editWord();
    else if (choice == 3)
        deleteWord();
    else if (choice == 4)
        viewBank(1);
    else if (choice == 5)
        addBank();
    else if (choice == 6)
        deleteBank();
    else if (choice == 7)
        viewAllBanks(1);
    else if (choice == 8)
        teamGenerate();
    else if (choice == 9)
        wordPick();
    else
        exit(0);
}

void addWord()
{
    viewAllBanks(0);

    char *subtitle = malloc(sizeof(char) * 50), *bank_choice = malloc(sizeof(char) * 50);
    subtitle = "Add a Word";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    char choice[1], c;

    gotoxy(LP + 4, TP + 25);
    printf("Select the bank you want to add a word in: ");
    scanf("%s", &choice);
    getchar();

    int int_choice = atoi(choice);
    int counter = 0;
    banks = fopen("wordbanks.txt", "r");

    while (!feof(banks))
    {
        fgets(bank_choice, 20, banks);
        if (!feof(banks))
        {
            if (int_choice - 1 == counter)
            {
                break;
            }
        }
    }

    // Tinatanggal lang neto yung extra newline pag nag fgets.
    bank_choice[strlen(bank_choice) - 1] = '\0';

    sprintf(bank_choice, "%s .csv", bank_choice);
    char another;
    char word[100];

    tp = fopen(bank_choice, "ab+");
    if(tp == NULL)
    {
        gotoxy(LP + 4, TP + 25);
        printf("ERROR!! Cannot open file.");
        getchar();
    }
    fflush(tp);
    another = 'y';

    gotoxy(LP + 4, TP + 25);
    for (int i = 0; i < 50; i++)
    {
        printf("%c", 040);
    }
    gotoxy(LP + 4, TP + 25);
    printf("Enter Word: ");
    scanf("%[^\n]", word);
    sprintf(word,"%s\n", word);
    fprintf(tp, "%s", word); // Writing data into file.
    fflush(tp);
    gotoxy(LP + 4, TP + 25);
    printf("Add another word? (y/n): ");
    another = getche();
    another = tolower(another);
    getchar();

    if (another == 'y')
    {
        getchar();
        addWord();
    }

    else
    {
        fclose(banks);
        fclose(tp);
        getchar();
    }
    main();
}
void editWord()
{
    viewAllBanks(0);

    char *subtitle = malloc(sizeof(char) * 50), *bank_choice = malloc(sizeof(char) * 50);
    subtitle = "Edit a Word";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    char option[1], c;
    char another, word[100], edit[100];
    int i, a, n1;
    char ans;
    struct wordbank;

    gotoxy(LP + 4, TP + 25);
    printf("Select the bank you want to edit a word in: ");
    scanf("%s", &option);
    getchar();

    int int_choice = atoi(option);
    int counter = 0;
    banks = fopen("wordbanks.txt", "r");

    while (!feof(banks))
    {
        fgets(bank_choice, 20, banks);
        if (!feof(banks))
        {
            if (int_choice - 1 == counter)
            {
                break;
            }
        }
    }
    system("cls");
    navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
    contentBorders();
    subtitle = "Edit a Word";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    bank_choice[strlen(bank_choice) - 1] = '\0';
    sprintf(bank_choice, "%s .csv", bank_choice);
    fp = fopen(bank_choice, "r");

    int x = 9, y = 9;
    gotoxy(LP + y, TP + x);
    while ((c = fgetc(fp)) != EOF)
    {
        printf("%c", c);
        if (c == '\n')
        {
            if (x > 20)
            {
                x = 7;
                y += 25;
            }
            x += 2;
            gotoxy(LP + y, TP + x);
        }
    }
    gotoxy(LP + 4, TP + 25);
    for (int i = 4; i < RP - 7; i++)
    {
        gotoxy(LP + i, TP + 25);
        printf("%c", 040);
    }
    gotoxy(LP + 4, TP + 25);
    printf("Enter the word you want to edit: ");
	scanf("%[^\n]", edit);
    rewind(fp);
	while(fscanf(fp, "%s", st[i].word)!=EOF)
    {
        if(strcmp(edit,st[i].word)==0)
        {
            system("cls");
            navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
            contentBorders();
            subtitle = "Edit a Word";
            gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
            printf("%s", subtitle);
            gotoxy(LP + 9, TP + 9);
            printf("RECORD FOUND!");
            gotoxy(LP + 9, TP + 12);
            printf("WORD: %s", st[i].word);

            gotoxy(LP + 4, TP + 25);
            for (int i = 4; i < RP - 7; i++)
            {
                gotoxy(LP + i, TP + 25);
                printf("%c", 040);
            }
            gotoxy(LP + 4, TP + 25);
            printf("Enter the New Word: (One word is advisable)");
            scanf(" %[^\n]", st[i].word);
            x = 0;
        }
        i++;
    }
    if (x == 0)
    {
        fp=fopen(bank_choice,"w+");
        for(a=0; a<i; a++)
        {
            fprintf(fp,"%s\n",st[a].word);
        }
        fflush(fp);
        fclose(fp);
    }
    st:
    getch();
    gotoxy(LP + 4, TP + 25);
    for (int i = 4; i < RP - 7; i++)
    {
        gotoxy(LP + i, TP + 25);
        printf("%c", 040);
    }
    gotoxy(LP + 4, TP + 25);
    printf("Do you want to edit another word[Y/N]? "); //if you want to use the function again
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
	{
    	editWord();
	}
    else if(toupper(ans)=='N')
	{
		printf("\n\t\tThank you");
    	getch();
    	main();
		}
	    else
    {
        printf("\n\t\tInvalid Input\n");
        goto st;
    }
}
void deleteWord()
{
    viewAllBanks(0);

    char *subtitle = malloc(sizeof(char) * 50), *bank_choice = malloc(sizeof(char) * 50);
    subtitle = "Delete a Word";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    char option[1], c;

    gotoxy(LP + 4, TP + 25);
    printf("Select the bank you want to remove a word in: ");
    scanf("%s", &option);
    getchar();

    int int_choice = atoi(option);
    int counter = 0;
    banks = fopen("wordbanks.txt", "r");

    while (!feof(banks))
    {
        fgets(bank_choice, 20, banks);
        if (!feof(banks))
        {
            if (int_choice - 1 == counter)
            {
                break;
            }
        }
    }

    bank_choice[strlen(bank_choice) - 1] = '\0';

    sprintf(bank_choice, "%s .csv", bank_choice);

    char words, del_Word[30], buffer[50], ans;
    int choice, count = 0;
    char *piece = malloc(sizeof(char) * 50);
    fp = fopen(bank_choice, "r");
    if (fp==NULL)
    {
        gotoxy(LP + 4, TP + 25);
        printf("File cannot be found");
        getchar();
    }
    fclose(fp);
    gotoxy(LP + 5, TP + 9);
    for (int i = 5; i < RP - 7; i++)
    {
        gotoxy(LP + i, TP + 9);
        printf("%c", 040);
    }
    gotoxy(LP + 5, TP + 9);
    printf("1 ) Delete all the words\t\t\t\tDelete specific word ( 2");
    gotoxy(LP + 4, TP + 25);
    for (int i = 4; i < RP - 7; i++)
    {
        gotoxy(LP + i, TP + 25);
        printf("%c", 040);
    }
    gotoxy(LP + 4, TP + 25);
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            fp = fopen(bank_choice,"w");
    		printf("All words successfully deleted");
    		while(1){
                fflush(stdin);
                printf("\nDo you want to continue deleting [y/n]: ");
                scanf(" %c", &ans);
                if(ans == 'y'||ans == 'Y')
                    deleteWord();
                else if(ans == 'n'||ans == 'N')
                    main();
                else{
                    printf("Invalid Input, Please try again");
                    break;
                }
            }
            break;
        case 2:
            fflush(stdin);
            fp = fopen(bank_choice,"r");
   			if (fp==NULL){
                printf("File cannot be found");
                exit(1);
            }
            for (int i = 4; i < RP - 7; i++)
            {
                gotoxy(LP + i, TP + 9);
                printf("%c", 040);
            }
            int x = 9, y = 9;
            gotoxy(LP + y, TP + x);
            while ((c = fgetc(fp)) != EOF)
            {
                printf("%c", c);
                if (c == '\n')
                {
                    if (x > 20)
                    {
                        x = 7;
                        y += 25;
                    }
                    x += 2;
                    gotoxy(LP + y, TP + x);
                }
            }
            for (int i = 4; i < RP - 7; i++)
            {
                gotoxy(LP + i, TP + 25);
                printf("%c", 040);
            }
            gotoxy(LP + 4, TP + 25);
            printf("Enter the word you want to delete in the record: ");
            scanf("%[^\n]", del_Word);
            rewind(fp);
   			tp = fopen("temp.txt","w");
            while(fgets (buffer, sizeof(buffer), fp)){
                piece = strtok(buffer, " ");
                piece[strlen(piece)-1] = '\0';
                while (piece != NULL){
                    if(strcmp(piece, del_Word) == 0)
                        count = 1;
                    else
                        fprintf(tp, "%s\n", piece);
                    piece = strtok(NULL, " ");
                }
    		}
    		fclose(fp);
    		fclose(tp);
    		if(count==1){
                fp = fopen(bank_choice,"w");
                tp = fopen("temp.txt","r");
                    while(fgets (buffer, sizeof (buffer), tp)){
                        fprintf(fp, "%s", buffer);
                    }
                printf("The word has been successfully deleted");
                fclose(fp);
                fclose(tp);
                remove("temp.txt");
                while(1){
                    fflush(stdin);
                    printf("\nDo you want to continue deleting [y/n]: ");
                    scanf(" %c", &ans);
                    if(ans == 'y'||ans == 'Y')
                        deleteWord();
                    else if(ans == 'n'||ans == 'N')
                        main();
                    else{
                        printf("Invalid Input, Please try again");
                        break;
                    }
                }
    		}
    		else {
                while(1){
                    fflush(stdin);
                    printf("\nWord not found\n");
                    printf("\nDo you want to continue deleting[y/n]: ");
                    scanf(" %c", &ans);
                    if(ans == 'y'||ans == 'Y')
                        deleteWord();
                    else if(ans == 'n'||ans == 'N')
                        main();
                    else{
                        printf("Invalid Input, Please try again");
                        break;
                    }
                }
    		}
    }
    free(bank_choice);
    free(piece);
}
void viewBank(int key)
{
    viewAllBanks(0);

    char *subtitle = malloc(sizeof(char) * 50), *bank_choice = malloc(sizeof(char) * 50);
    if (key != 0)
    {
        subtitle = "View a Bank";
        gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
        printf("%s", subtitle);
    }

    char choice[1], c;

    gotoxy(LP + 4, TP + 25);
    printf("Select the bank you want to see: ");
    scanf("%s", &choice);
    getchar();

    int int_choice = atoi(choice);
    int counter = 0;
    banks = fopen("wordbanks.txt", "r");

    while (!feof(banks))
    {
        fgets(bank_choice, 20, banks);
        if (!feof(banks))
        {
            if (int_choice - 1 == counter)
            {
                break;
            }
        }
    }

    // Tinatanggal lang neto yung extra newline pag nag fgets.
    bank_choice[strlen(bank_choice) - 1] = '\0';

    sprintf(bank_choice, "%s .csv", bank_choice);
    char another;
    char word[100];

    tp = fopen(bank_choice, "r");

    system("cls");
    navBar("Randomizer???", "Technological University of the Philippines", "BSCS-1AB (STEM)");
    contentBorders();
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    int x = 9, y = 9;

    gotoxy(LP + y, TP + x);

    while ((c = fgetc(tp)) != EOF)
    {
        printf("%c", c);
        if (c == '\n')
        {
            if (x > 20)
            {
                x = 7;
                y += 25;
            }
            x += 2;
            gotoxy(LP + y, TP + x);
        }
    }
    getchar();
    fclose(banks);
    fclose(tp);
    free(bank_choice);
    if (key != 0)
        main();
}
void addBank()
{
    system("cls");
    navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
    contentBorders();
    banks = fopen("wordbanks.txt", "a+");

    char *word_bank = malloc(sizeof(char) * 50);
    char *word_bank_mod = malloc(sizeof(char) * 50);

    char c;
    int linecount = 0;
    char *subtitle = malloc(sizeof(char) * 50);
    subtitle = "Add A Word Bank";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    // User Prompt
    gotoxy(LP + 4, TP + 25);
    printf("Add the name the word bank: ");
    fgets(word_bank, sizeof(char) * 50, stdin);

    fputs(word_bank, banks);

    // Removes the space para magamit ng matino yung sprintf()
    for (int i = 0, n = strlen(word_bank); i < n; i++)
    {
        if (word_bank[i] == '\n')
        {
            word_bank[i] = 040;
        }
    }

    sprintf(word_bank_mod, "%s.csv", word_bank);

    if(!fopen(word_bank_mod, "w"))
       {
            gotoxy(LP + 4, TP + 7);
            printf("Error. Can't make that file.");
            getch();
            main();
       }

    gotoxy(LP + 4, TP + 7);
    printf("Successfully Added!");
    getch();
    fflush(banks);

    free(word_bank);
    free(word_bank_mod);

    main();
}
void deleteBank()
{
    viewAllBanks(0);

    char *subtitle = malloc(sizeof(char) * 50), *nameremove = malloc(sizeof(char) * 20);
    subtitle = "Delete a Section";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    char choice[1], *str = malloc(sizeof(char) * 20);

    gotoxy(LP + 4, TP + 25);
    printf("Select the number you want to delete: ");
    scanf("%s", &choice);
    getchar();

    int int_choice = atoi(choice);
    int counter = 0;
    banks = fopen("wordbanks.txt", "r");
    tp = fopen("tempbanks.txt", "w");

    if (int_choice - 1 == 0)
        fgets(nameremove, 20, banks);
    while (!feof(banks))
    {
        strcpy(str, "\0");
        fgets(str, 20, banks);
        if (!feof(banks))
        {
            counter++;
            if (int_choice - 1 == counter)
            {
                fgets(nameremove, 20, banks);
            }
            fprintf(tp, "%s", str);
        }
    }
    printf("%s", nameremove);
    nameremove[strlen(nameremove) - 1] = '\0';
    sprintf(nameremove, "%s .csv", nameremove);

    // I found out that you can't remove the file you just added in menu (5).
    if (remove(nameremove) != 0)
    {
        gotoxy(LP + 4, TP + 25);
        printf("Error Message: %s. This will probably solved by restarting the program.", strerror(errno));
        getchar();
        exit(1);
    }

    fclose(banks);
    fclose(tp);

    free(nameremove);
    remove("wordbanks.txt");
    rename("tempbanks.txt", "wordbanks.txt");
    main();
}
void viewAllBanks(int b)
{
    system("cls");
    navBar("Randomizer???", "Technological University of the Philippines", "BSCS-1AB (STEM)");
    contentBorders();
    banks = fopen("wordbanks.txt", "r");

    if (banks == NULL)
    {
        gotoxy(LP + 4, TP + 25);
        printf("No File Found. Try creating at least one bank first.");
        getchar();
        main();
    }

    char c;
    int section_count = 0, x = 9, y = 9;

    gotoxy(LP + y, TP + x);

    while ((c = fgetc(banks)) != EOF)
    {
        printf("%c", c);
        if (c == '\n')
        {
            section_count++;
            gotoxy((LP + y) - 4, TP + x);
            printf("%d )", section_count);
            if (x > 20)
            {
                x = 7;
                y += 25;
            }
            x += 2;
            gotoxy(LP + y, TP + x);
        }
    }


    fclose(banks);
    if (b != 0)
    {
        getchar();
        main();
    }

}
void teamGenerate()
{
    /*
    * pseudocode: count the lines
    * divide by desired number
    * print the divided group.
    */

    system("cls");
    navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
    contentBorders();
    char *subtitle = malloc(sizeof(char) * 50), *bank_choice = malloc(sizeof(char) * 50);
    char option[1], a = 'a', words[MAX][MAX], *temp = malloc(sizeof(char) * 50);
    int group, counter = 0;
    subtitle = "Generate a Team";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    while(toupper(a) != 'Y' && toupper(a) != 'N')
    {
        for (int i = 4; i < RP - 7; i++)
        {
            gotoxy(LP + i, TP + 25);
            printf("%c", 040);
        }
        gotoxy(LP + 4, TP + 25);
        printf("Choose from a bank or nah?(y/n) ");
        scanf("%c", &a);
        fflush(stdin);
    }

    gotoxy(LP + 4, TP + 25);
    for (int i = 4; i < RP - 7; i++)
    {
        gotoxy(LP + i, TP + 25);
        printf("%c", 040);
    }

    if (toupper(a) == 'Y')
    {
        viewAllBanks(0);
        gotoxy(LP + 4, TP + 25);
        printf("Select the bank you want to make a team in: ");
        scanf("%s", &option);
        getchar();
        fflush(stdin);

        int int_choice = atoi(option);
        banks = fopen("wordbanks.txt", "r");

        while (!feof(banks))
        {
            fgets(bank_choice, 20, banks);
            if (!feof(banks))
            {
                if (int_choice - 1 == counter)
                {
                    break;
                }
            }
        }
        system("cls");
        navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
        contentBorders();
        gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
        printf("%s", subtitle);

        bank_choice[strlen(bank_choice) - 1] = '\0';
        sprintf(bank_choice, "%s .csv", bank_choice);
        fp = fopen(bank_choice, "r");

        counter = 0;
        while (fgets(words[counter], MAX, fp) != NULL)
        {
            counter++;
        }

        gotoxy(LP + 4, TP + 25);
        printf("How many groups do you want to form? ");
        scanf("%d", &group);
        fflush(stdin);

        if ((counter / (float) group) <= 0 || (counter / (float) group) >= 20)
        {
            gotoxy(LP + 4, TP + 25);
            printf("Please enter a valid group amount.");
            getchar();
            free(bank_choice);
            free(temp);
            teamGenerate();
        }

        srand(time(NULL));
        for (int i = 0; i < round((float) counter / 2); i++)
        {
            int n = rand() % (counter);
            strcpy(temp, words[i]);
            strcpy(words[i], words[n]);
            strcpy(words[n], temp);
        }

        system("cls");
        navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
        contentBorders();
        gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
        printf("%s", subtitle);

        int mod_count = counter % group;

        for (int i = 0, x = 4, y = 7, visor = 0, num = 0; i < counter; i++, visor++)
        {
            if (visor == 0)
            {
                y++;
                gotoxy(LP + x, TP + y);
                printf("Group %d\n", num + 1);
                y++;
            }

            for (int j = 0, len = strlen(words[i]); j < len; j++, x++)
            {
                gotoxy(LP + x, TP + y);
                printf("%c", words[i][j]);
            }

            float mod_visor = floor(counter / (float) group);

            if (mod_count <= 0)
                mod_visor = floor(counter / (float) group) - 1;

            if (visor >= (int) mod_visor)
            {
                visor = -1;
                num++;
                mod_count--;
                if (num > 5 && num < 12)
                {
                    if (num == 6)
                        y = 7;
                    x = 40;
                }
                else if (num >= 12)
                {
                    if (num == 12)
                        y = 7;
                    x = 76;
                }
                else
                    x = 4;
            }
        }


        fclose(fp);
    }

    else if (toupper(a) == 'N')
    {
        // Take inputs from user
        for (int i = 4; i < RP - 7; i++)
        {
            gotoxy(LP + i, TP + 25);
            printf("%c", 040);
        }
        gotoxy(LP + 4, TP + 25);
        printf("Enter the number of words: ");
        scanf("%d", &counter);
        getchar();
        fflush(stdin);

        gotoxy(LP + 4, TP + 25);
        printf("How many groups do you want to form? ");
        scanf("%d", &group);
        fflush(stdin);

        if ((counter / (float) group) == 0)
        {
            gotoxy(LP + 4, TP + 25);
            printf("Please enter a valid group amount.");
            getchar();
            free(bank_choice);
            free(temp);
            teamGenerate();
        }

        for (int i = 0; i < counter; i++)
        {
            gotoxy(LP + 4, TP + 9);
            printf("Enter word %d: ", i + 1);
            scanf("%[^\n]", words[i]);
            getchar();
            for (int j = 4; j < RP - 7; j++)
            {
                gotoxy(LP + j, TP + 9);
                printf("%c", 040);
            }
            fflush(stdin);
        }

        srand(time(NULL));
        for (int i = 0; i < round((float) counter / 2); i++)
        {
            int n = rand() % (counter);
            strcpy(temp, words[i]);
            strcpy(words[i], words[n]);
            strcpy(words[n], temp);
        }

        system("cls");
        navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
        contentBorders();
        gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
        printf("%s", subtitle);

        int mod_count = counter % group;

        for (int i = 0, x = 4, y = 7, visor = 0, num = 0; i < counter; i++, visor++)
        {
            if (visor == 0)
            {
                y++;
                gotoxy(LP + x, TP + y);
                printf("Group %d\n", num + 1);
                y++;
            }

            for (int j = 0, len = strlen(words[i]); j < len; j++, x++)
            {
                gotoxy(LP + x, TP + y);
                printf("%c", words[i][j]);
            }

            float mod_visor = floor(counter / (float) group);

            if (mod_count <= 0)
                mod_visor = floor(counter / (float) group) - 1;

            if (visor >= (int) mod_visor)
            {
                visor = -1;
                num++;
                mod_count--;
                if (num > 5 && num < 12)
                {
                    if (num == 6)
                        y = 7;
                    x = 40;
                }
                else if (num >= 12)
                {
                    if (num == 12)
                        y = 7;
                    x = 76;
                }
                else
                    x = 4;
            }
        }
    }
    getchar();
    free(bank_choice);
    free(temp);
    main();
}
void wordPick()
{
    /*
    * pseudocode: count the lines.
    * generate a number within the range of 0 - maximum number of lines.
    * print the selected person.
    */

    system("cls");
    navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
    contentBorders();
    char *subtitle = malloc(sizeof(char) * 50), *bank_choice = malloc(sizeof(char) * 50);
    char option[1], a = 'a', words[MAX][MAX], *temp = malloc(sizeof(char) * 50);
    int group, counter = 0;
    subtitle = "Random Pick";
    gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
    printf("%s", subtitle);

    while(toupper(a) != 'Y' && toupper(a) != 'N')
    {
        for (int i = 4; i < RP - 7; i++)
        {
            gotoxy(LP + i, TP + 25);
            printf("%c", 040);
        }
        gotoxy(LP + 4, TP + 25);
        printf("Choose from a bank or nah?(y/n) ");
        scanf("%c", &a);
        fflush(stdin);
    }

    gotoxy(LP + 4, TP + 25);
    for (int i = 4; i < RP - 7; i++)
    {
        gotoxy(LP + i, TP + 25);
        printf("%c", 040);
    }

    if (toupper(a) == 'Y')
    {
        viewAllBanks(0);
        gotoxy(LP + 4, TP + 25);
        printf("Select the bank you want to make a team in: ");
        scanf("%s", &option);
        getchar();
        fflush(stdin);

        int int_choice = atoi(option);
        banks = fopen("wordbanks.txt", "r");

        while (!feof(banks))
        {
            fgets(bank_choice, 20, banks);
            if (!feof(banks))
            {
                if (int_choice - 1 == counter)
                {
                    break;
                }
            }
        }
        system("cls");
        navBar("Randomizer??", "Technological University of the Philippines", "BSCS-1AB (STEM)");
        contentBorders();
        gotoxy((((LP + RP) / 2) - (strlen(subtitle) / 2)), 26);
        printf("%s", subtitle);

        bank_choice[strlen(bank_choice) - 1] = '\0';
        sprintf(bank_choice, "%s .csv", bank_choice);
        fp = fopen(bank_choice, "r");

        counter = 0;
        while (fgets(words[counter], MAX, fp) != NULL)
        {
            counter++;
        }

        srand(time(NULL));
        int pick = rand() % (counter + 1);
        gotoxy((((LP + RP) / 2) - (strlen("Congratulations!") / 2)), TP + 9);
        printf("Congratulations!");

        gotoxy((((LP + RP) / 2) - (strlen(words[pick]) / 2)), TP + 11);
        for (int i = 0, n = strlen(words[pick]); i < n; i++)
        {
            for(int j = 0; j < 10000000; j++);
            printf("%c", words[pick][i]);
        }
        getchar();
    }

    else if (toupper(a) == 'N')
    {
        // Take inputs from user
        for (int i = 4; i < RP - 7; i++)
        {
            gotoxy(LP + i, TP + 25);
            printf("%c", 040);
        }
        gotoxy(LP + 4, TP + 25);
        printf("Enter the number of words: ");
        scanf("%d", &counter);
        getchar();
        fflush(stdin);

        for (int i = 0; i < counter; i++)
        {
            gotoxy(LP + 4, TP + 9);
            printf("Enter word %d: ", i + 1);
            scanf("%[^\n]", words[i]);
            getchar();
            for (int j = 4; j < RP - 7; j++)
            {
                gotoxy(LP + j, TP + 9);
                printf("%c", 040);
            }
            fflush(stdin);
        }

        srand(time(NULL));
        int pick = rand() % (counter + 1);
        gotoxy((((LP + RP) / 2) - (strlen("Congratulations!") / 2)), TP + 9);
        printf("Congratulations!");

        int n = strlen(words[pick]);
        gotoxy((((LP + RP) / 2) - n / 2), TP + 11);
        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < 10000000; j++);
            printf("%c", words[pick][i]);
        }
        getchar();
    }

    main();
}

void contentBorders(void)
{
     // Left and Right Borders
    for(int i = TP + 5; i < 30; i++)
    {
        gotoxy(LP, i);
        printf("%c", 186);
    }
    for(int i = TP + 5; i < 30; i++)
    {
        gotoxy(RP, i);
        printf("%c", 186);
    }
    // Bottom Borders
    for(int i = LP; i < RP; i++)
    {
        gotoxy(i, 26);
        printf("%c", 196);
    }
    for(int i = LP; i < RP; i++)
    {
        gotoxy(i, 30);
        printf("%c", 205);
    }

    // Corners
    gotoxy(LP, TP + 4);
    printf("%c", 199);
    gotoxy(RP, TP + 4);
    printf("%c", 182);
    gotoxy(LP, TP + 27);
    printf("%c", 200);
    gotoxy(RP, TP + 27);
    printf("%c", 188);
    gotoxy(LP, 26);
    printf("%c", 199);
    gotoxy(RP, 26);
    printf("%c", 182);
}


