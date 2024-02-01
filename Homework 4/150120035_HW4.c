//OMER DELIGOZ 150120035
//This program suggests a route to get from a starting point to a target point on a metro line.

#include <stdio.h>
#include <string.h>
#include <math.h>

//a macro for finding distance between two points
#define distance(x1, y1, x2, y2) (sqrt(pow(x2-x1,2) + pow(y2-y1,2)) * 1.0)
#define SIZE 10
double minimum_distance = 100000;

struct MetroStation {
    char name[20];
    double x, y;
};
typedef struct MetroStation MetroStation;

MetroStation path[] = {'\0'};


struct MetroLine {
    char color[20];
    MetroStation MetroStations[SIZE];
};
typedef struct MetroLine MetroLine;

struct MetroSystem {
    char name[20];
    MetroLine MetroLines[SIZE];
};
typedef struct MetroSystem MetroSystem;

//function prototypes
int equals(MetroStation s1, MetroStation s2);

void addStation(MetroLine *linePtr, MetroStation station);

int hasStation(MetroLine line, MetroStation station);

int containsStation(MetroStation stations[], MetroStation station);

MetroStation getFirstStop(MetroLine line);

MetroStation getPreviousStop(MetroLine line, MetroStation station);

MetroStation getNextStop(MetroLine line, MetroStation station);

void addLine(MetroSystem *system, MetroLine line);

void printLine(MetroLine line);

void printPath(MetroStation stations[]);

double getDistanceTravelled(MetroStation path[]);

MetroStation findNearestStation(MetroSystem system, double x, double y);

void getNeighboringStations(MetroSystem system, MetroStation station, MetroStation neighboringStations[]);

void findPath(MetroStation start, MetroStation finish, MetroStation path[]);

void recursiveFindPath(MetroStation start, MetroStation finish, MetroStation partialPath[], MetroStation bestPath[], int pathLength);


//Declare a MetroSystem with the name of istanbul and an empty content.
MetroSystem istanbul = {"istanbul", '\0'};

//This method compares the names of two stations
int equals(MetroStation s1, MetroStation s2) {
    return ((strcmp(s1.name, s2.name)) ? 0 : 1);  //returns non-zero value if names are equal
}

//This method adds the given metro station to the end of the given array
void addStation(MetroLine *linePtr, MetroStation station) {
    int index = 0;
    while (linePtr->MetroStations[index].name[0] != '\0') {
        index++;
    }
    linePtr->MetroStations[index] = station;
}

//This method checks whether there is a given station on the given line
int hasStation(MetroLine line, MetroStation station) {
    int i;
    for (i = 0; strlen(line.MetroStations[i].name) != 0; i++) {
        if (strcmp(line.MetroStations[i].name, station.name) == 0)
            return 1;
    }
    return 0;
}

//This method returns the first station of the given line
MetroStation getFirstStop(MetroLine line) {
    MetroStation empty = {'\0'};
    return (line.MetroStations[0].name[0] != '\0') ? line.MetroStations[0] : empty;
}

//This method returns the previous station from the given station
MetroStation getPreviousStop(MetroLine line, MetroStation station) {
    MetroStation empty = {'\0'};

    for (int i = 0; i < SIZE; ++i) {
        if (strcmp(line.MetroStations[i].name, station.name) == 0) {
            return (i != 0) ? line.MetroStations[i - 1] : empty;
        }
    }
    return empty;
}

//This method returns the next station from the given station
MetroStation getNextStop(MetroLine line, MetroStation station) {
    MetroStation empty = {'\0'};

    for (int i = 0; i < SIZE; ++i) {
        if (strcmp(line.MetroStations[i].name, station.name) == 0) {
            return (line.MetroStations[i + 1].name[0] != '\0') ? line.MetroStations[i + 1] : empty;
        }
    }
    return empty;
}

//This method adds the given line to the given metro system
void addLine(MetroSystem *systemPtr, MetroLine line) {
    int index = 0;

    while (systemPtr->MetroLines[index].color[0] != '\0') {
        index++;
    }
    systemPtr->MetroLines[index] = line;
}

//This method prints the stations of the given line
void printLine(MetroLine line) {

    printf("Metroline %s: ", line.color);
    for (int i = 0; line.MetroStations[i].name[0] != '\0'; ++i) {  //
        if (line.MetroStations[i].name[0] != '\0' && (line.MetroStations[i + 1].name[0] != '\0'))
            printf("%s, ", line.MetroStations[i].name);
        else if (line.MetroStations[i + 1].name[0] == '\0')
            printf("%s", line.MetroStations[i].name);
        else
            continue;
    }
    puts(".");
}

//This method prints the stations in the given array
void printPath(MetroStation stations[]) {
    int i = 0;
    while (strlen(stations[i].name)) {
        printf("%d. %s\n", (i + 1), stations[i].name);
        i++;
    }
}

//This method calculates the travelled distance along the given path
double getDistanceTravelled(MetroStation path[]) {
    double sum = 0;
    int i, stationNumber = 0;
    while (path[stationNumber].name[0] != '\0') {
        stationNumber++;
    }
    if (stationNumber < 2)
        return 0;
    else {
        for (i = 0; i < stationNumber - 1; ++i) {
            sum += distance(path[i].x, path[i].y, path[i + 1].x, path[i + 1].y);
        }
        return sum;
    }
}

//This method finds the nearest station to given location
MetroStation findNearestStation(MetroSystem system, double x, double y) {
    double min = 100000;
    MetroStation nearestStation;
    double goalX, goalY, distance;
    for (int i = 0; system.MetroLines[i].color[0] != '\0'; i++) {
        for (int j = 0; system.MetroLines[i].MetroStations[j].name[0] != '\0'; j++) {
            goalX = system.MetroLines[i].MetroStations[j].x;
            goalY = system.MetroLines[i].MetroStations[j].y;
            distance = distance(goalX, goalY, x, y);

            if (distance < min) {
                min = distance;
                nearestStation = system.MetroLines[i].MetroStations[j];
            }
        }
    }
    return nearestStation;
}

//This method finds all neighboring stations to the given station
void getNeighboringStations(MetroSystem system, MetroStation station, MetroStation neighboringStations[]) {
    int index = 0;
    for (int i = 0; i < strlen(system.MetroLines[i].color); ++i) {
        for (int j = 0; j < strlen(system.MetroLines[i].MetroStations[j].name); ++j) {
            if (equals(system.MetroLines[i].MetroStations[j], station)) {
                if (j == 0) { //If this station is the first stop of a line just add the next station
                    neighboringStations[index] = system.MetroLines[i].MetroStations[j + 1];
                    index++;
                } else if (system.MetroLines[i].MetroStations[j + 1].name[0] ==
                           '\0') { //If this station is the last stop of a line just add the previous station
                    neighboringStations[index] = system.MetroLines[i].MetroStations[j - 1];
                    index++;
                } else {  //else add the previous and next stations
                    neighboringStations[index] = system.MetroLines[i].MetroStations[j - 1];
                    index++;
                    neighboringStations[index] = system.MetroLines[i].MetroStations[j + 1];
                    index++;
                }
            }
        }
    }
}

//This method checks whether the given array contains the given station or not
int containsStation(MetroStation stations[], MetroStation station) {
    int i = 0;
    while (stations[i].name[0] != '\0') {
        if (equals(stations[i], station))
            return 1;
        i++;
    }
    return 0;
}

void findPath(MetroStation start, MetroStation finish, MetroStation path[]) {
    MetroStation partialPath[SIZE] = {'\0'};
    recursiveFindPath(start, finish, path, partialPath,0);
}


void recursiveFindPath(MetroStation start, MetroStation finish, MetroStation partialPath[], MetroStation bestPath[], int pathLength) {
    if (equals(start, finish)) {  //base case
        double distance = getDistanceTravelled(partialPath);
        if (distance < minimum_distance) {
            minimum_distance = distance;
            memcpy(bestPath, partialPath, sizeof(MetroStation) * SIZE);
        }
        return;
    }

    MetroStation neighboringStations[SIZE];
    getNeighboringStations(istanbul, start, neighboringStations);

    for (int i = 0; i < SIZE; i++) {
        if (neighboringStations[i].name[0] != '\0' && !containsStation(partialPath, neighboringStations[i])) {
            partialPath[pathLength] = neighboringStations[i];
            pathLength++;  // increment path length
            recursiveFindPath(neighboringStations[i], finish, partialPath, bestPath, pathLength);
            pathLength--;  // decrement path length
            partialPath[pathLength] = (MetroStation){'\0'}; // Set the last element to empty string to remove it
        }
    }
}



/*
void recursiveFindPath(MetroStation start, MetroStation finish, MetroStation partialPath[], MetroStation bestPath[]) {
    if (containsStation(partialPath, start))
        return;
    if (equals(start, finish)) {
        //TODO travelled distance minimum olan pathi kullan şartı eklenebilir
        for (int i = 0; bestPath[i].name[0] != '\0'; ++i) {
            strcpy(partialPath[i].name, bestPath[i].name);
            partialPath[i].x = bestPath[i].x;
            partialPath[i].y = bestPath[i].y;
        }
        return;
    } else {
        MetroStation neighbours[6] = {'\0'};
        getNeighboringStations(istanbul, start, neighbours);

        for (int i = 0; neighbours[i].name[0] != '\0'; ++i) {
            MetroStation duplicatePath[6] = {'\0'};
            int j;
            for (j = 0; partialPath[j].name[0] != '\0'; ++j) {
                strcpy(duplicatePath[j].name, partialPath[j].name);
                duplicatePath[j].x = partialPath[j].x;
                duplicatePath[j].y = partialPath[j].y;
            }
            strcpy(duplicatePath[j].name, start.name);
            duplicatePath[j].x = start.x;
            duplicatePath[j].y = start.y;


            recursiveFindPath(neighbours[i], finish, duplicatePath,
                              partialPath); //TODO partial yerine bestpath olabilir

            if (bestPath[0].name[0] != '\0') {
                if (getDistanceTravelled(bestPath) < minimum_distance) {
                    minimum_distance = getDistanceTravelled(bestPath);
                    for (int j = 0; bestPath[j].name[0] != '\0'; ++j) {
                        strcpy(partialPath[j].name, bestPath[j].name);
                        partialPath[j].x = bestPath[j].x;
                        partialPath[j].y = bestPath[j].y;
                    }
                }
            }
        }
    }
}
*/
/*
void recursiveFindPath(MetroStation start, MetroStation finish, MetroStation partialPath[], MetroStation bestPath[]) {
    double distance = 100000;

    if (containsStation(partialPath, start)) {
        return;
    } else if (equals(start, finish)) {
        for (int i = 0; strlen(bestPath[i].name) != 0; i++) {
            strcpy(partialPath[i].name, bestPath[i].name);
            partialPath[i].x = bestPath[i].x;
            partialPath[i].y = bestPath[i].y;
        }
        return;
    } else {
        MetroStation neighbors[6] = {'\0'};
        getNeighboringStations(istanbul, start, neighbors);
        MetroStation duplicatePath[6] = {'\0'};
        int j;
        for (int i = 0; strlen(neighbors[i].name) != 0; ++i) {  //for each neighbor stations
//            MetroStation duplicatePath[6] = {'\0'};
            for (j = 0; strlen(partialPath[j].name) != 0; ++j) {  //for each neighbor stations
                strcpy(duplicatePath[j].name, partialPath[j].name);
                duplicatePath[j].x = partialPath[j].x;
                duplicatePath[j].y = partialPath[j].y;
            }
            strcpy(duplicatePath[j].name, start.name);
            duplicatePath[j].x = start.x;
            duplicatePath[j].y = start.y;

            if (!containsStation(duplicatePath, neighbors[i])) {
                if (!equals(neighbors[i], finish)) {
                    recursiveFindPath(neighbors[i], finish, duplicatePath, bestPath);
                }
            }
        }


        for (int i = 0; strlen(duplicatePath[i].name) != 0; i++, j++) {
            strcpy(partialPath[i].name, duplicatePath[i].name);
            partialPath[i].x = duplicatePath[i].x;
            partialPath[i].y = duplicatePath[i].y;

        }
        for (int k = 0; strlen(partialPath[k].name) != 0; ++k) {
        }

        //partialPath[k] = finish;  //this line adds finish station more than one, i could not fix it

        if (strlen(partialPath[0].name) != 0) {
            if (getDistanceTravelled(partialPath) < distance) {
                bestPath = partialPath;
            }
        }
    }
}
*/

int main() {
    int i;

//    double myX = 1, myY = 2;
//    double goalX = 62, goalY = 45;
    double myX = 9, myY = 4;
    double goalX = 48, goalY = 22;

    // define 3 metro lines, 9 metro stations, and an empty myPath
    MetroLine red = {'\0'}, blue = {'\0'}, green = {'\0'};
    MetroStation s1, s2, s3, s4, s5, s6, s7, s8, s9;
    MetroStation myPath[SIZE] = {'\0'};

    strcpy(red.color, "red");
    strcpy(blue.color, "blue");
    strcpy(green.color, "green");

    printf("isEqual -> %d\n\n", red);
    printf("Red.color -> %s\n\n", red.color);

    strcpy(s1.name, "Haydarpasa");
    s1.x = 0;
    s1.y = 0;
    strcpy(s2.name, "Sogutlucesme");
    s2.x = 10;
    s2.y = 5;
    strcpy(s3.name, "Goztepe");
    s3.x = 20;
    s3.y = 10;
    strcpy(s4.name, "Kozyatagi");
    s4.x = 30;
    s4.y = 35;
    strcpy(s5.name, "Bostanci");
    s5.x = 45;
    s5.y = 20;
    strcpy(s6.name, "Kartal");
    s6.x = 55;
    s6.y = 20;
    strcpy(s7.name, "Samandira");
    s7.x = 60;
    s7.y = 40;
    strcpy(s8.name, "Icmeler");
    s8.x = 70;
    s8.y = 15;

    //Add several metro stations to the given metro lines.
    addStation(&red, s1);
    addStation(&red, s2);
    addStation(&red, s3);
    addStation(&red, s4);
    addStation(&red, s5);
    addStation(&red, s8);

    addStation(&blue, s2);
    addStation(&blue, s3);
    addStation(&blue, s4);
    addStation(&blue, s6);
    addStation(&blue, s7);

    addStation(&green, s2);
    addStation(&green, s3);
    addStation(&green, s5);
    addStation(&green, s6);
    addStation(&green, s8);

    // Add red, blue, green metro lines to the Istanbul metro system.
    addLine(&istanbul, red);
    addLine(&istanbul, blue);
    addLine(&istanbul, green);

    // print the content of the red, blue, green metro lines
    printLine(red);
    printLine(blue);
    printLine(green);


    printf("\nnext stop -> %s\n", getNextStop(red, s6).name);
    printf("\nnearestStation -> %s\n", findNearestStation(istanbul, 48, 22).name);

    // find the nearest stations to the current and target locations
    MetroStation nearMe = findNearestStation(istanbul, myX, myY);
    MetroStation nearGoal = findNearestStation(istanbul, goalX, goalY);

    printf("\n");

    printf("The best path from %s to %s is:\n", nearMe.name, nearGoal.name);

    // if the nearest current and target stations are the same, then print a message and exit.
    if (equals(nearMe, nearGoal)) {
        printf("It is better to walk!\n");
        return 0;
    }
    MetroStation neighbors[10] = {'\0'};
    getNeighboringStations(istanbul, s5, neighbors);
//    printf("\nneighbor1 -> %s\n", neighbors[0].name);
//    printf("\nneighbor2 -> %s\n", neighbors[1].name);
//    printf("\nneighbor3 -> %s\n", neighbors[2].name);
//    printf("\nneighbor4 -> %s\n", neighbors[3].name);
//    printf("\nneighbor5 -> %s\n", neighbors[4].name);
//    printf("\nneighbor6 -> %s\n", neighbors[5].name);


    // Calculate and print the myPath with the minimum distance travelled from start to target stations.
    findPath(nearMe, nearGoal, myPath);

    if (strlen(myPath[0].name) == 0)
        printf("There is no path on the metro!\n");
    else {
        printPath(myPath);
    }

    return 0;

}
