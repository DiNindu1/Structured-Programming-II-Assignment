//Main

#include <stdio.h>

// Global variables
int guestID, nights, meals, spa;
char roomType, category, paymentFlag;
float roomCharges, mealCharges, spaCharges, serviceCharge;
float luxuryTax, totalBeforeDiscount, discount, finalTotal;

void inputData();
void calculateAll();
void printBill();

void main() {
    char continueFlag;
    do {
        inputData();
        calculateAll();
        printBill();
        printf("\nDo you want to process another bill? (Y/N): ");
        scanf(" %c", &continueFlag);
    } while (continueFlag == 'Y' || continueFlag == 'y');
}

