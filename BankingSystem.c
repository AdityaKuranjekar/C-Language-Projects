#include <stdio.h>
#include <stdlib.h>

int pass = 1234, word, chn;
int menu();
void deposit();
void withdraw();
void transfer();
void checkDetails();
void displaySummary();

int totalAmount = 1000, amount, amo, tr, totalDeposit = 0, totalWithdraw = 0, totalTransfer = 0;
int acc, transferAcc;
char name[50];

void main() {
    system("cls");
    printf("Enter the Password For Access to Your Account (pass is 1234): ");
    scanf("%d", &word);

    if (word == pass) {
        system("cls");
        printf("Correct password. You have access.\n");
        printf("Enter your name: ");
        getchar();
        scanf("%[^\n]", name);
        printf("Enter your Account Number: ");
        scanf("%d", &acc);

        while (1) {
            switch (menu()) {
                case 1:
                    deposit();
                    totalDeposit += amount;
                    printf("Deposit successful! Your total balance is: %d\n", totalAmount);
                    break;
                case 2:
                    withdraw();
                    if (amo <= totalAmount) {
                        totalWithdraw += amo;
                        printf("Withdrawal successful! Your total balance is: %d\n", totalAmount);
                    }
                    break;
                case 3:
                    transfer();
                    if (tr <= totalAmount) {
                        totalTransfer += tr;
                        printf("Transfer successful! Your total balance is: %d\n", totalAmount);
                    }
                    break;
                case 4:
                    checkDetails();
                    break;
                case 5:
                    system("cls");
                    displaySummary();
                    exit(0);
                default:
                    printf("\nInvalid Choice! Try Again.\n");
            }
            system("cls");
        }
    } else {
        system("cls");
        printf("Incorrect password.\nIf you want to retry, press 1. Else press 0: ");
        scanf("%d", &chn);
        if (chn == 1) {
            main();
        } else {
            printf("\nExiting...\n");
        }
    }
}

int menu() {
    int choice;
    printf("\n--- Menu ---");
    printf("\n1. Deposit Amount");
    printf("\n2. Withdraw Amount");
    printf("\n3. Transfer Amount");
    printf("\n4. Check Account Details");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void deposit() {
    printf("\nEnter the amount to deposit: ");
    scanf("%d", &amount);
    if (amount > 0) {
        totalAmount += amount;
    } else {
        printf("\nInvalid amount. Try again.\n");
    }
    printf("Deposited Succesfully\nPress Any key to continue...");
    getch();
}

void withdraw() {
    printf("\nEnter the amount to withdraw: ");
    scanf("%d", &amo);
    if (amo > 0 && amo <= totalAmount) {
        totalAmount -= amo;
        printf("Withdrawl Succesfully\nPress Any key to continue...");
        getch();
    } else {
        printf("\nInsufficient funds or invalid amount.\nPress any key to continue...");
        getch();
    }
}

void transfer() {
    printf("\nEnter the amount to transfer: ");
    scanf("%d", &tr);
    if (tr > 0 && tr <= totalAmount) {
        printf("Enter the account number to transfer to: ");
        scanf("%d", &transferAcc);
        totalAmount -= tr;
        printf("Transfer Succesfully\nPress Any key to continue...");
        getch();
    } else {
        printf("\nInsufficient funds or invalid amount.\nPress any key to continue...");
        getch();
    }
}

void checkDetails() {
    system("cls");
    printf("\n--- Account Details ---");
    printf("\nName: %s", name);
    printf("\nAccount Number: %d", acc);
    printf("\nTotal Balance: %d", totalAmount);
    printf("\nTotal Deposited: %d", totalDeposit);
    printf("\nTotal Withdrawn: %d", totalWithdraw);
    printf("\nTotal Transferred: %d\n", totalTransfer);
    printf("\nPress any key to continue...");
    getch();
}

void displaySummary() {
    printf("\n--- Final Account Summary ---");
    printf("\nName: %s", name);
    printf("\nAccount Number: %d", acc);
    printf("\nTotal Balance: %d", totalAmount);
    printf("\nTotal Deposited: %d", totalDeposit);
    printf("\nTotal Withdrawn: %d", totalWithdraw);
    printf("\nTotal Transferred: %d", totalTransfer);
    printf("\n\nThank you for banking with us!\n");
}
//By Aditya Kailash Kuranjekar..............HAPPY CODING.......................||
