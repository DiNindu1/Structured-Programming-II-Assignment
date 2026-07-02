//Calculate

#include <stdio.h>

extern int guestID, nights, meals, spa;
extern char roomType, category, paymentFlag;
extern float roomCharges, mealCharges, spaCharges, serviceCharge;
extern float luxuryTax, totalBeforeDiscount, discount, finalTotal;

float calculateRoomcharges() {
    if (roomType == 'S' || roomType == 's') return nights * 8000;
    else if (roomType == 'D' || roomType == 'd') return nights * 12000;
    else if (roomType == 'U' || roomType == 'u') return nights * 20000;
    return 0;
}

float calculateMealCharges() { return meals * 1200; }
float calculateSpaCharges() { return spa * 3500; }

void getCategory() {
    if (nights <= 3) category = 'S';
    else if (nights <= 7) category = 'R';
    else category = 'E';
}

float calculateServiceCharge() {
    if (category == 'S') return 2000;
    else if (category == 'R') return 3500;
    else return 5000;
}

float calculateDiscount() {
    if (paymentFlag == 'Y' || paymentFlag == 'y') {
        if (category == 'S') return totalBeforeDiscount * 0.05;
        else if (category == 'R') return totalBeforeDiscount * 0.10;
        else return totalBeforeDiscount * 0.15;
    }
    return 0;
}

float calculateLuxuryTax() {
    if (totalBeforeDiscount > 100000) return totalBeforeDiscount * 0.08;
    return 0;
}

void calculateAll() {
    roomCharges = calculateRoomcharges();
    mealCharges = calculateMealCharges();
    spaCharges = calculateSpaCharges();
    getCategory();
    serviceCharge = calculateServiceCharge();
    totalBeforeDiscount = roomCharges + mealCharges + spaCharges + serviceCharge;
    luxuryTax = calculateLuxuryTax();
    totalBeforeDiscount += luxuryTax;
    discount = calculateDiscount();
    finalTotal = totalBeforeDiscount - discount;
}

