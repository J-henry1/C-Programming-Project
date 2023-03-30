/* Ammortization Table & Loan Calculator
* Jared Henry
*  N01484167
*  Project 3 
*  COP 2220
*  July 12, 2021
*/
#include <stdio.h>
#include <math.h>

//function prototypes- monthly payment
int monthlyTotal(int yearsBorrowed);
double APR(double userApr);
double P(int monthlyTotal, double APR);
float ansQ(double P);
float monthlyPayment(float ansQ, int principalAmt, double APR);
float calcPayoff(float monthlyPayment);

int main(void) {

float loanAmt;
float loanApr;
int lengthLoan;
float placeHolder;
float *totalDue = &placeHolder;

  printf("Please enter loan amount:\n");
  scanf("%f", &loanAmt);
 
  printf("Please enter your Annual Percentage Rate:\n");
  scanf("%f", &loanApr);
  
  printf("Please enter the length of your loan:\n\n");
  scanf("%d", &lengthLoan);

  printf("Monthly payment: %.2f\n\n", monthlyPayment(ansQ(P(monthlyTotal(lengthLoan), APR(loanApr))), loanAmt, APR(loanApr)));

  *totalDue = calcPayoff(monthlyPayment(ansQ(P(monthlyTotal(lengthLoan), APR(loanApr))), loanAmt, APR(loanApr)));

  printf("%.4f\n", P(monthlyTotal(lengthLoan), APR(loanApr)));

  printf("Month\tOld balance\tMonthly Payment\tInterest Paid\tPrincipal Paid\tNew Balance\n\n");

int i, j;
int countMonths = 1;
float monthPay;
float monthlyApr = (loanApr / 12) / 100;
monthPay = monthlyPayment(ansQ(P(monthlyTotal(lengthLoan), APR(loanApr))), loanAmt, APR(loanApr));
float interestPaid = 0;
float principalPaid = 0;
float newBalance = loanAmt;
int oldBalance = loanAmt;
loanApr = monthlyPayment(ansQ(P(monthlyTotal(lengthLoan), APR(loanApr))), loanAmt, APR(loanApr));
// for loop for amortization
for(i = 1; i <= lengthLoan * 12; i++){
oldBalance = loanAmt - principalPaid;
interestPaid = loanAmt * monthlyApr;
principalPaid = monthPay - interestPaid;
newBalance = loanAmt - principalPaid;
printf("%-2d %13.2f %12.2f %14.2f %17.2f %15.2f", countMonths, loanAmt, monthPay, interestPaid,principalPaid, newBalance); 
loanAmt = newBalance;
countMonths++;

printf("\n");
}

printf("Your total amount paid at maturity of loan: %.2f\n\n", *totalDue);

  return 0;
}
int monthlyTotal(int yearsBorrowed){
int months;
months = yearsBorrowed * 12;
return months;
}
double APR(double userApr){
return (userApr / 12) / 100;
}
//finding P
double P(int monthlyTotal, double APR){
return pow((1 + APR),monthlyTotal);
}
// finding Q
float ansQ(double P){
return P / (P - 1);
}
// monthly payment
float monthlyPayment(float ansQ, int principalAmt, double APR){
return ansQ * principalAmt * APR;
}
//used for balances in table
float calcPayoff(float monthlyPayment){
  return monthlyPayment * 12;
}