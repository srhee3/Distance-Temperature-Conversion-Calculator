#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// function declarations:
char getUserConversion();
void isTemperatureValid(char typeInitial, char typeNewline);
double temperatureConversion(double firstTemp, char typeInitial, char typeNew);
void isDistanceValid(char typeInitial, char typeNewLine);
double distanceConversion(double firstDist, char typeInitial, char typeNew);

char getUserConversion() {
    /*
        Gets the type of conversion the user wants. If not t or d, the program
        will exit.
    */
    char userConversion, shouldBewNewline;
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    scanf(" %c%c", &userConversion, &shouldBewNewline);

    if (isalpha(userConversion) && shouldBewNewline == '\n') {
        if (toupper(userConversion) == 'T' || toupper(userConversion) == 'D') {
            return userConversion;
        }
        else {
            printf("Unknown conversion type %c chosen. Ending program.\n", userConversion);
            exit(0);
        }
    } else{
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

void isTemperatureValid(char typeInitial, char typeNewline) {
    // ensures that the temperature the user inputs is valid
    if (isalpha(typeInitial) && typeNewline == '\n') {
        if (toupper(typeInitial) != 'F' && toupper(typeInitial) != 'C' && toupper(typeInitial) != 'K') {
            printf("%c is not a valid temperature type. Ending program.\n", typeInitial);
            exit(0);
        }
    } else {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

double temperatureConversion(double firstTemp, char typeInitial, char typeNew) {
    // converts the temperature that the user wants and returns it
    typeInitial = toupper(typeInitial);
    typeNew = toupper(typeNew);

    if (typeInitial == typeNew) {
        return firstTemp;
    } else if (typeInitial == 'F' && typeNew == 'C') {
        return (firstTemp - 32.0) * (5.0/9.0);
    } else if (typeInitial == 'F' && typeNew == 'K') {
        return (firstTemp - 32.0) * (5.0/9.0) + 273.15;
    } else if (typeInitial == 'C' && typeNew == 'F') {
        return (firstTemp * (9.0/5.0)) + 32;
    } else if (typeInitial == 'C' && typeNew == 'K') {
        return firstTemp + 273.15;
    } else if (typeInitial == 'K' && typeNew == 'F') {
        return (firstTemp - 273.15) * (9.0/5.0) + 32.0;
    } else if (typeInitial == 'K' && typeNew == 'C') {
        return firstTemp - 273.15;
    } else {
        return 10000000;
    }
}

void isDistanceValid(char typeInitial, char typeNewline) {
    // ensures that the distance the user inputs is valid
    if (isalpha(typeInitial) && typeNewline == '\n') {
        if (toupper(typeInitial) != 'I' && toupper(typeInitial) != 'F' && toupper(typeInitial) != 'Y'
            && toupper(typeInitial) != 'M') {
            printf("%c is not a valid distance type. Ending program.\n", typeInitial);
            exit(0);
        }
    } else {
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

double distanceConversion(double firstDist, char typeInitial, char typeNew) {
    // converts the temperature that the user wants and returns it
    typeInitial = toupper(typeInitial);
    typeNew = toupper(typeNew);

    // converts every type to yards
    if (typeInitial == 'I') {
        firstDist = firstDist / 36.0;
    } else if (typeInitial == 'F') {
        firstDist = firstDist / 3.0;
    } else if (typeInitial == 'M') {
        firstDist = firstDist * 1760.0;
    }

    // converts to new type and returns it
    if (typeNew == 'I') {
        return firstDist * 36.0;
    } else if (typeNew == 'F') {
        return firstDist * 3.0;
    } else if (typeNew == 'M') {
        return firstDist / 1760.0;
    } else {
        return firstDist;
    }
}

int main() {
    char conversionType = getUserConversion();
    
    if (toupper(conversionType) == 'T') {   // temperature conversion
        // gets user's initial temperature
        double tempInitial;
        char tempTypeInitial, shouldBeNewline;
        printf("Enter the temperature followed by its suffix (F, C, or K): ");
        scanf(" %lf %c%c", &tempInitial, &tempTypeInitial, &shouldBeNewline);
        isTemperatureValid(tempTypeInitial, shouldBeNewline);

        // gets user's new temperature type
        char newTempType;
        printf("Enter the new unit type (F, C, or K): ");
        scanf(" %c%c", &newTempType, &shouldBeNewline);
        isTemperatureValid(newTempType, shouldBeNewline);

        double convertedTemp = temperatureConversion(tempInitial, tempTypeInitial, newTempType);
        printf("%.2lf%c is %.2lf%c\n", tempInitial, toupper(tempTypeInitial),
               convertedTemp, toupper(newTempType));
    } else {   // distance conversion
        // gets user's initial distance
        double distInitial;
        char distTypeInitial, shouldBeNewLine;
        printf("Enter the distance followed by its suffix (I,F,Y,M): ");
        scanf(" %lf %c%c", &distInitial, &distTypeInitial, &shouldBeNewLine);
        isDistanceValid(distTypeInitial, shouldBeNewLine);

        // get user's new distance type
        char newDistType;
        printf("Enter the new unit type (I,F,Y,M): ");
        scanf(" %c%c", &newDistType, &shouldBeNewLine);
        isDistanceValid(newDistType, shouldBeNewLine);

        double convertedDist = distanceConversion(distInitial, distTypeInitial, newDistType);
        printf("%.2lf%c is %.2lf%c\n", distInitial, toupper(distTypeInitial), 
               convertedDist, toupper(newDistType));
    }
    return 0;
}