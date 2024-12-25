#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_PLAYERS 20
#define MAX_OVERS 20

typedef struct {
    char name[30];
    char batsmen[MAX_PLAYERS][30];
    char bowlers[MAX_PLAYERS][30];
    int runs[MAX_OVERS][6];
    int totalRuns;
    int wickets;
    int numBatsmen;
    int numBowlers;
} Team;

void welcome();
void menu();
void newScoreSheet(Team *team1, Team *team2, int *overs);
void enterScores(Team *battingTeam, Team *bowlingTeam, int overs);
void displayScoreboard(const Team *team, int overs);
void determineWinner(const Team *team1, const Team *team2);
void viewScoreSheet(const Team *team1, const Team *team2);

int main() {
    Team team1 = {"", {}, {}, {}, 0, 0, 0, 0};
    Team team2 = {"", {}, {}, {}, 0, 0, 0, 0};
    int overs;
    int choice;

    welcome();

    while (1) {
        system("cls");
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                newScoreSheet(&team1, &team2, &overs);
                enterScores(&team1, &team2, overs);
                enterScores(&team2, &team1, overs);
                determineWinner(&team1, &team2);
                break;
            case 2:
                viewScoreSheet(&team1, &team2);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}

void welcome() {
    printf("\n\n\n\t\t\tWelcome to Cricket Score Sheet Program\n");
    printf("\n\n\t\t\tPress Any Key to Continue...\n");
    getch();
}

void menu() {
    printf("\n\n\t\tMenu\n");
    printf("1. New Scoresheet\n");
    printf("2. View Scoresheet\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void newScoreSheet(Team *team1, Team *team2, int *overs) {
    system("cls");
    printf("Enter name of Team 1: ");
    scanf(" %[^\n]", team1->name);
    printf("Enter name of Team 2: ");
    scanf(" %[^\n]", team2->name);

    printf("Enter number of overs: ");
    scanf("%d", overs);

    printf("\nEnter number of batsmen for %s: ", team1->name);
    scanf("%d", &team1->numBatsmen);
    printf("Enter batsmen names:\n");
    for (int i = 0; i < team1->numBatsmen; i++) {
        printf("Batsman %d: ", i + 1);
        scanf(" %[^\n]", team1->batsmen[i]);
    }

    printf("\nEnter number of bowlers for %s: ", team1->name);
    scanf("%d", &team1->numBowlers);
    printf("Enter bowlers names:\n");
    for (int i = 0; i < team1->numBowlers; i++) {
        printf("Bowler %d: ", i + 1);
        scanf(" %[^\n]", team1->bowlers[i]);
    }

    printf("\nEnter number of batsmen for %s: ", team2->name);
    scanf("%d", &team2->numBatsmen);
    printf("Enter batsmen names:\n");
    for (int i = 0; i < team2->numBatsmen; i++) {
        printf("Batsman %d: ", i + 1);
        scanf(" %[^\n]", team2->batsmen[i]);
    }

    printf("\nEnter number of bowlers for %s: ", team2->name);
    scanf("%d", &team2->numBowlers);
    printf("Enter bowlers names:\n");
    for (int i = 0; i < team2->numBowlers; i++) {
        printf("Bowler %d: ", i + 1);
        scanf(" %[^\n]", team2->bowlers[i]);
    }
}

void enterScores(Team *battingTeam, Team *bowlingTeam, int overs) {
    system("cls");
    printf("%s is batting now.\n", battingTeam->name);
    battingTeam->totalRuns = 0;
    battingTeam->wickets = 0;
    int currentBatter = 0;
    int currentBowler = 0;

    for (int i = 0; i < overs; i++) {
        printf("Over %d:\n", i + 1);
        printf("Current Bowler: %s\n", bowlingTeam->bowlers[currentBowler]);
        int overRuns = 0;

        for (int j = 0; j < 6; j++) {
            if (currentBatter >= battingTeam->numBatsmen) {
                printf("All batsmen are out! Innings over.\n");
                return;
            }

            printf("Current Batter: %s\n", battingTeam->batsmen[currentBatter]);
            printf("Ball %d: Enter runs (-1 if out): ", j + 1);
            int run;
            scanf("%d", &run);

            if (run == -1) {
                battingTeam->wickets++;
                currentBatter++;
                if (currentBatter >= battingTeam->numBatsmen) {
                    printf("All batsmen are out! Innings over.\n");
                    return;
                }
            } else {
                overRuns += run;
            }
            battingTeam->runs[i][j] = run;
        }
        battingTeam->totalRuns += overRuns;
        currentBowler = (currentBowler + 1) % bowlingTeam->numBowlers;
        displayScoreboard(battingTeam, i + 1);
    }
}

void displayScoreboard(const Team *team, int overs) {
    printf("\nScoreboard for %s:\n", team->name);
    printf("Overs: %d, Total Runs: %d, Wickets: %d\n", overs, team->totalRuns, team->wickets);
    for (int i = 0; i < overs; i++) {
        printf("Over %d: ", i + 1);
        for (int j = 0; j < 6; j++) {
            if (team->runs[i][j] == -1)
                printf("W ");
            else
                printf("%d ", team->runs[i][j]);
        }
        printf("\n");
    }
}

void determineWinner(const Team *team1, const Team *team2) {
    printf("\nMatch Result:\n");
    if (team1->totalRuns > team2->totalRuns) {
        printf("%s wins by %d runs!\n", team1->name, team1->totalRuns - team2->totalRuns);
    } else if (team1->totalRuns < team2->totalRuns) {
        printf("%s wins by %d wickets!\n", team2->name, team2->numBatsmen - team2->wickets);
    } else {
        printf("The match is a tie!\n");
    }
    getch();
}

void viewScoreSheet(const Team *team1, const Team *team2) {
    system("cls");
    printf("Match Score Sheet:\n");
    printf("\nTeam 1: %s\n", team1->name);
    displayScoreboard(team1, MAX_OVERS);

    printf("\nTeam 2: %s\n", team2->name);
    displayScoreboard(team2, MAX_OVERS);

    determineWinner(team1, team2);
}
// Made by Aditya Kailash Kuranjekar ------------HAPPY CODING------------------------------||
