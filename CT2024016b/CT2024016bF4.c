//Output

#include <stdio.h>

extern int guestID;
extern char roomType, category;
extern float roomCharges, mealCharges, spaCharges, serviceCharge;
extern float luxuryTax, totalBeforeDiscount, discount, finalTotal;

void printCategory() {
    if (category == 'S') printf("Short Stay");
    else if (category == 'R') printf("Regular Stay");
    else printf("Extended Stay");
}

void printBill() {
    printf("\n--- Bill Summary for Guest ID: %d ---\n", guestID);
    printf("Room type: %c\n", roomType);
    printf("Category: ");
    printCategory();
    printf("\nRoom Charges: %.2f\n", roomCharges);
    printf("Meal Charges: %.2f\n", mealCharges);
    printf("Spa Charges: %.2f\n", spaCharges);
    printf("Service Charge: %.2f\n", serviceCharge);
    printf("Luxury Tax: %.2f\n", luxuryTax);
    printf("Total Before Discount: %.2f\n", totalBeforeDiscount);
    printf("Discount: %.2f\n", discount);
    printf("Final Total: %.2f\n", finalTotal);
}

