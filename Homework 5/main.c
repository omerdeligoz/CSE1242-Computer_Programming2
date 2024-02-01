#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song {
    char songName[25];
    int duration;
    struct song *chrono_next;
    struct song *alpha_next;
    struct song *duration_next;
    struct song *random_next;
};
typedef struct song song;
song *chrono_head, *alpha_head, *duration_head, *random_head;

void insertNode(char songName[], int duration);

void deleteNode(char songName[]);

void printList();

void readInput();

void printListToFile(char outputName[]);

void shuffleList(int count);

void printListToFile(char outputName[]) {
    printf("outputName ->%s\n", outputName);

    FILE *outputFile = fopen(outputName, "w");
    song *printerPTr;
    printerPTr = chrono_head;
    int count = 1;
    int minute, second;
    fprintf(outputFile, "The list in chronological order:\n");
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        fprintf(outputFile, "%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->chrono_next;
        count++;
    }

    fprintf(outputFile, "\nThe list in alphabetical order:\n");

    printerPTr = alpha_head;
    count = 1;
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        fprintf(outputFile, "%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->alpha_next;
        count++;
    }

    fprintf(outputFile, "\nThe list in duration-time order:\n");

    printerPTr = duration_head;
    count = 1;
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        fprintf(outputFile, "%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->duration_next;
        count++;
    }
    fprintf(outputFile, "\nThe list in random order:\n");
    printerPTr = random_head;
    count = 1;
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        fprintf(outputFile, "%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->random_next;
        count++;
    }
}

void readInput() {
    FILE *inputFile;

    if ((inputFile = fopen("songs.txt", "r")) == NULL) {
        puts("File could not be opened");
    } else {
        char songName[25];
        int totalSecond;
        char minute[3];
        char second[3];
        do {  //Read the input file line by line and place each song in the appropriate positions in the linked lists
            fscanf(inputFile, "%[^\t]\t%[^:]:%[^\n]", songName, minute, second);
            totalSecond = (60 * atoi(minute)) + atoi(second);
            insertNode(songName, totalSecond);
        } while (getc(inputFile) != EOF);
    }
}

void deleteNode(char songName[]) {
    int isDeleted = 0;
    song *temp, *previous;

    if (chrono_head == NULL) {
        printf("The list is already empty!\n");
        return;
    }

    //////////////////////////////////////////////////////////////////
    // Delete node from alphabetical list
    temp = previous = alpha_head;

    if (strcmp(alpha_head->songName, songName) == 0) {
        alpha_head = alpha_head->alpha_next;
        isDeleted = 1;
    } else {
        while (temp != NULL) {
            if (strcmp(temp->songName, songName) == 0) {
                previous->alpha_next = temp->alpha_next;
                isDeleted = 1;
                break;
            }
            previous = temp;
            temp = temp->alpha_next;
        }
    }
    //////////////////////////////////////////////////////////////////
    // Delete node from chronological list
    temp = previous = chrono_head;

    if (strcmp(chrono_head->songName, songName) == 0) {
        chrono_head = chrono_head->chrono_next;
        isDeleted = 1;
    } else {
        while (temp != NULL) {
            if (strcmp(temp->songName, songName) == 0) {
                previous->chrono_next = temp->chrono_next;
                isDeleted = 1;
                break;
            }
            previous = temp;
            temp = temp->chrono_next;
        }
    }

    //////////////////////////////////////////////////////////////////
    // Delete node from duration list
    temp = previous = duration_head;

    if (strcmp(duration_head->songName, songName) == 0) {
        duration_head = duration_head->duration_next;
        isDeleted = 1;
    } else {
        while (temp != NULL) {
            if (strcmp(temp->songName, songName) == 0) {
                previous->duration_next = temp->duration_next;
                isDeleted = 1;
                break;
            }
            previous = temp;
            temp = temp->duration_next;
        }
    }
    //////////////////////////////////////////////////////////////////
    // Delete node from random list
    temp = previous = random_head;

    if (strcmp(random_head->songName, songName) == 0) {
        random_head = random_head->random_next;
        isDeleted = 1;
    } else {
        while (temp != NULL) {
            if (strcmp(temp->songName, songName) == 0) {
                previous->random_next = temp->random_next;
                isDeleted = 1;
                break;
            }
            previous = temp;
            temp = temp->random_next;
        }
    }
    //////////////////////////////////////////////////////////////////

    isDeleted == 1 ? printf("The song \"%s\" is deleted from the list!\n", songName) : printf(
            "There is no song named \"%s\" in the list\n", songName);
}

void printList() {
    song *printerPTr;
    printerPTr = chrono_head;
    int count = 1;
    int minute, second;

    //print the chronological list
    printf("The list in chronological order:\n");
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        printf("\t%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->chrono_next;
        count++;
    }

    //print the alphabetical list
    printf("\nThe list in alphabetical order:\n");
    printerPTr = alpha_head;
    count = 1;
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        printf("\t%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->alpha_next;
        count++;
    }

    //print the duration-time list
    printf("\nThe list in duration-time order:\n");
    printerPTr = duration_head;
    count = 1;
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        printf("\t%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->duration_next;
        count++;
    }

    //print the random list
    printf("\nThe list in random order:\n");
    shuffleList(count - 1);  //shuffle list before printing
    printerPTr = random_head;
    count = 1;
    while (printerPTr != NULL) {
        minute = printerPTr->duration / 60;
        second = printerPTr->duration % 60;
        printf("\t%d.%s\t%d:%d\n", count, printerPTr->songName, minute, second);
        printerPTr = printerPTr->random_next;
        count++;
    }
}

void insertNode(char songName[], int duration) {
    song *newNode = (song *) malloc(sizeof(song));
    newNode->duration = duration;
    strcpy(newNode->songName, songName);
    newNode->random_next = NULL;
    newNode->alpha_next = NULL;
    newNode->chrono_next = NULL;
    newNode->duration_next = NULL;


    ////////////////////////////////////////////////////////////
    // Create chronological list and random list
    song *temp, *tempRandom;
    temp = chrono_head;
    tempRandom = random_head;
    if (chrono_head == NULL) {
        chrono_head = newNode;
        random_head = newNode;
    } else {
        while (temp->chrono_next != NULL) {
            temp = temp->chrono_next;
            tempRandom = tempRandom->random_next;
        }
        temp->chrono_next = newNode;
        tempRandom->random_next = newNode;
    }

    ////////////////////////////////////////////////////////////
    // Create alphabetical list
    temp = alpha_head;
    song *previous = alpha_head;
    if (alpha_head == NULL) {
        alpha_head = newNode;
    } else if (strcmp(newNode->songName, alpha_head->songName) < 0) {
        alpha_head = newNode;
        newNode->alpha_next = temp;
    } else {
        while (strcmp(newNode->songName, temp->songName) > 0) {
            if (temp->alpha_next == NULL) {
                temp->alpha_next = newNode;
                break;
            } else {
                previous = temp;
                temp = temp->alpha_next;
            }
        }
        if (strcmp(newNode->songName, temp->songName) < 0) {
            previous->alpha_next = newNode;
            newNode->alpha_next = temp;
        }
    }
    ////////////////////////////////////////////////////////////
    // Create duration-time list
    temp = duration_head;
    previous = duration_head;

    if (duration_head == NULL) {
        duration_head = newNode;
    } else if (newNode->duration < duration_head->duration) {
        duration_head = newNode;
        newNode->duration_next = temp;
    } else {
        while (newNode->duration > temp->duration) {
            if (temp->duration_next == NULL) {
                temp->duration_next = newNode;
                break;
            } else {
                previous = temp;
                temp = temp->duration_next;
            }
        }
        if (newNode->duration < temp->duration) {
            previous->duration_next = newNode;
            newNode->duration_next = temp;
        }
    }
    return;
}

void shuffleList(int count) {
    if (random_head->random_next == NULL || random_head == NULL) { //return if the list is empty or has one element
        return;
    }

    int random1, random2;
    song *node1;
    song *node2;
    song *prevNode1 = NULL;
    song *prevNode2 = NULL;
    song *temp = NULL;

    for (int n = 0; n < 20; ++n) { //swap two nodes 20 times, it can be changed as desired
        random1 = rand() % count;
        random2 = rand() % count;
        node1 = random_head;
        node2 = random_head;
        prevNode1 = NULL;
        prevNode2 = NULL;

        if (random1 == random2) //skip this iteration if two nodes are the same
            continue;

        //find node1 and node2 based on random numbers
        for (int i = 0; i < random1; i++) {
            prevNode1 = node1;
            node1 = node1->random_next;
        }

        for (int i = 0; i < random2; i++) {
            prevNode2 = node2;
            node2 = node2->random_next;
        }

        if (node1 != NULL && node2 != NULL) {

            //If previous node to node1 is not null then, it will point to node2
            if (prevNode1 != NULL)
                prevNode1->random_next = node2;
            else
                random_head = node2;

            //If previous node to node2 is not null then, it will point to node1
            if (prevNode2 != NULL)
                prevNode2->random_next = node1;
            else
                random_head = node1;

            //Swaps the next nodes of node1 and node2
            temp = node1->random_next;
            node1->random_next = node2->random_next;
            node2->random_next = temp;
        }
    }
}

int main() {
    int totalSecond, choice;
    char minute[3];
    char second[3];
    char songName[25];
    char outputName[25];

    readInput();
    printList();

    do {
        printf("\nEnter your choice:\n\t"
               "1 to insert a song into the list.\n\t"
               "2 to delete a song from the list.\n\t"
               "3 to print the songs in the list.\n\t"
               "4 to print the songs to an output file.\n\t"
               "5 to end.\n? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter a song name with duration:\n");
                scanf("\n%[^\t]\t%[^:]:%[^\n]", songName, minute, second);
                totalSecond = 60 * atoi(minute) + atoi(second);
                insertNode(songName, totalSecond);
                break;
            case 2:
                printf("Enter a song name:\n");
                scanf("\n%[^\n]", songName);
                deleteNode(songName);
                break;
            case 3:
                printList();
                break;
            case 4:
                printf("Enter a file name:\n");
                scanf("%s", outputName);
                printListToFile(outputName);
                break;
            case 5:
                return 1;
        }
    } while (1);
}