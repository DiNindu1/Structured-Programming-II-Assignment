#include <stdio.h>

//calculate room charges
float calculateRoomcharges(char roomType, int nights)
{
    if (roomType == 'S' || roomType == 's'){
        return nights * 8000;
    }else if (roomType == 'D' || roomType == 'd'){
        return nights * 12000;
    }else if (roomType == 'U' || roomType == 'u'){
        return nights * 20000;
    }
    return 0;
}

//calculate meal charges
float calculateMealCharges(int meals)
{
    return meals * 1200;
}

//calculate spa charges
float calculateSpaCharges(int spaSessions)
{
    return spaSessions * 3500;
}

//determine category based on number of nights
void getCategory(int nights, char *category)
{
    if (nights <= 3){
        *category = 'S'; //S = Short Stay
    }else if (nights <= 7){
        *category = 'R'; //R = Regular Stay
    }else{
        *category = 'E'; //E = Extended Stay

    }
}

//calculate service charge
float calculateServiceCharge(char category)
{
    if (category == 'S'){
        return 2000;
    }else if (category == 'R'){
        return 3500;
    }else {
        return 5000;
    }

}

//calculate discount
float calculateDiscount(char category, float total, char paymentFlag)
{
    if (paymentFlag == 'Y' || paymentFlag == 'y'){
        if (category == 'S'){
            return total * 0.05; //5% discount
        }else if (category == 'R'){
            return total * 0.10; //10% discount
        }else {
            return total * 0.15; //15% discount
        }
    }
    return 0;
}

//calculate luxury tax
float calculateLuxuryTax(float total)
{
    if (total > 100000)
        return total * 0.08;
    return 0;
}

//print category
void printCategory(char category)
{
    switch(category){
        case 'S': printf("Short Stay\n");
        break;
        case 'R': printf("Regular Stay\n");
        break;
        case 'E': printf("Extended Stay\n");
        break;
        default: printf("Unknown Category\n");
    }
}

//bill process for a customer
void processBill()
{
    int guestID, nights, meals, spa;
    char roomType, category, paymentFlag;

    printf("Enter Guest ID: "); //Range 1000-9999
    scanf("%d", &guestID);
    while (guestID < 1000 || guestID > 9999) {
        printf("Invalid Guest ID. Please enter a valid Guest ID (1000-9999): ");
        scanf("%d", &guestID);
    }
    printf("Enter Room Type (S/D/U): ");
    scanf(" %c", &roomType);
    printf("Enter Number of Nights: ");
    scanf("%d", &nights);
    while (nights <= 0) {
        printf("Invalid number of nights. Please enter a positive number: ");
        scanf("%d", &nights);
    }
    printf("Enter Number of Meals: ");
    scanf("%d", &meals);
    while (meals < 0) {
        printf("Invalid number of meals. Please enter a non-negative number: ");
        scanf("%d", &meals);
    }
    printf("Enter Number of Spa Sessions: ");
    scanf("%d", &spa);
    while (spa < 0) {
        printf("Invalid number of spa sessions. Please enter a non-negative number: ");
        scanf("%d", &spa);
    }
    printf("Payment Made in Advance? (Y/N): ");
    scanf(" %c", &paymentFlag);

    float roomCharges = calculateRoomcharges(roomType, nights);
    float mealCharges = calculateMealCharges(meals);
    float spaCharges = calculateSpaCharges(spa);
    getCategory(nights, &category);
    float serviceCharge = calculateServiceCharge(category);
    float totalBeforeDiscount = roomCharges + mealCharges + spaCharges + serviceCharge;
    float luxuryTax = calculateLuxuryTax(totalBeforeDiscount);
    totalBeforeDiscount += luxuryTax;
    float discount = calculateDiscount(category, totalBeforeDiscount, paymentFlag);
    float finalTotal = totalBeforeDiscount - discount;

    printf("\n--- Bill Summary for Guest ID: %d ---\n", guestID);
    printf("Room type: %c\n", roomType);
    printf("Category: ");
    printCategory(category);
    printf("Room Charges: %.2f\n", roomCharges);
    printf("Meal Charges: %.2f\n", mealCharges);
    printf("Spa Charges: %.2f\n", spaCharges);
    printf("Service Charge: %.2f\n", serviceCharge);
    printf("Luxury Tax: %.2f\n", luxuryTax);
    printf("Total Before Discount: %.2f\n", totalBeforeDiscount);
    printf("Discount: %.2f\n", discount);
    printf("Final Total: %.2f\n", finalTotal);
}

void main()
{
    char continueFlag;
    do {
        processBill();
        printf("\nDo you want to process another bill? (Y/N): ");
        scanf(" %c", &continueFlag);
    } while (continueFlag == 'Y' || continueFlag == 'y');
}
