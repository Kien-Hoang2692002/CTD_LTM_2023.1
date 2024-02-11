#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dinh nghia cau truc cac nut trong danh sach
struct Node {
    char username[50];
    char password[50];
    int status;
    struct Node* next;
};

// Ham doc danh sach tu file
struct Node* readAccountsFromFile() {
    FILE* file = fopen("account.txt", "r");
    if (file == NULL) {
        perror("Khong the mo file");
        exit(EXIT_FAILURE);
    }

    struct Node* head = NULL;
    struct Node* current = NULL;

    char username[50];
    char password[50];
    int status;

    while (fscanf(file, "%s %s %d", username, password, &status) != EOF) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            perror("Loi cap phat bo nho cho Node");
            exit(EXIT_FAILURE);
        }

        strcpy(newNode->username, username);
        strcpy(newNode->password, password);
        newNode->status = status;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    fclose(file);
    return head;
}

// Ham ghi danh sach tai khoan vao file
void writeAccountsToFile(struct Node* head) {
    FILE* file = fopen("account.txt", "w");
    if (file == NULL) {
        perror("Khong the mo file");
        exit(EXIT_FAILURE);
    }

    struct Node* current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %d\n", current->username, current->password, current->status);
        current = current->next;
    }

    fclose(file);
}

// Ham kiem tra xem tai khoan co ton tai khong
struct Node* findAccount(struct Node* head, const char* username) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->username, username) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct Node* accountList = readAccountsFromFile();
    int choice;

    printf("USER MANAGEMENT PROGRAM\n");
    printf("-----------------------------------\n");

    do {
        printf("1. Register\n");
        printf("2. Sign in\n");
        printf("3. Search\n");
        printf("4. Sign out\n");
        printf("Your choice (1-4, other to quit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char newUsername[50];
                char newPassword[50];

                printf("Enter new username: ");
                scanf("%s", newUsername);

                // Kiem tra ten tai khoan da ton tai hay chua
                if (findAccount(accountList, newUsername) != NULL) {
                    printf("Account existed \n");
                } else {
                    printf("Enter new password: ");
                    scanf("%s", newPassword);

                    // Them tai khoan moi vao danh sach
                    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                    strcpy(newNode->username, newUsername);
                    strcpy(newNode->password, newPassword);
                    newNode->status = 1;  // trang thai active
                    newNode->next = accountList;
                    accountList = newNode;

                    // Cap nhat danh sach vao file
                    writeAccountsToFile(accountList);
                    printf("Registration successful.\n");
                }
                break;
            }

            case 2: {
                char username[50];
                char password[50];

                printf("Enter your username: ");
                scanf("%s", username);

                struct Node* account = findAccount(accountList, username);

                if (account == NULL || account->status == 0) {
                    printf("Cannot find account .\n");
                } else {
                    printf("Enter your password: ");
                    scanf("%s", password);

                    if (strcmp(account->password, password) == 0) {
                        printf("Hello %s \n", account->username);
                    } else {
                        printf("Password is incorrect .\n");
                    }
                }
                break;
            }

            case 3: {
                char searchUsername[50];

                printf("Enter username to search: ");
                scanf("%s", searchUsername);

                struct Node* account = findAccount(accountList, searchUsername);

                if (account == NULL) {
                    printf("Cannot find account .\n");
                } else {
                    printf("Account is %s\n", (account->status == 1) ? "active" : "blocked");
                }
                break;
            }

            case 4: {
                char signOutUsername[50];

                printf("Enter your username: ");
                scanf("%s", signOutUsername);

                struct Node* account = findAccount(accountList, signOutUsername);

                if (account == NULL) {
                    printf("Cannot find account.\n");
                } else {
                    printf("Goodbye %s\n", signOutUsername);
                }
                break;
            }

            default:
                printf("Goodbye!\n");
        }
    } while (choice >= 1 && choice <= 4);

    // Giai phong bo nho cho tai khoan
    struct Node* current = accountList;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
