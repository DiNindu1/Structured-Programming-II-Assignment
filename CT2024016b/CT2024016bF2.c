//Input Data

#include <stdio.h>

extern int guestID, nights, meals, spa;
extern char roomType, category, paymentFlag;

void inputData() {
    printf("Enter Guest ID (1000-9999): ");
    scanf("%d", &guestID);
    while (guestID < 1000 || guestID > 9999) {
        printf("Invalid Guest ID. Please enter a valid Guest ID (1000-9999): ");
        scanf("%d", &guestID);
    }
    printf("Enter Room Type (S/D/U): ");
    scanf(" %c", &roomType);
    printf("Enter Number of Nights: ");
    scanf("%d", &nights);
    while (nights < 1) {
        printf("Invalid Number of Nights. Please enter a valid number of nights (greater than 0): ");
        scanf("%d", &nights);
    }
    printf("Enter Number of Meals: ");
    scanf("%d", &meals);
    while (meals < 0) {
        printf("Invalid Number of Meals. Please enter a valid number of meals (0 or greater): ");
        scanf("%d", &meals);
    }
    printf("Enter Number of Spa Sessions: ");
    scanf("%d", &spa);
    while (spa < 0) {
        printf("Invalid Number of Spa Sessions. Please enter a valid number of spa sessions (0 or greater): ");
        scanf("%d", &spa);
    }
    printf("Payment Made in Advance? (Y/N): ");
    scanf(" %c", &paymentFlag);
}

