This assignment is to use your knowledge of Chap 1-5 to
generate the following amortization table in a file given
user’s input of loan amount, annual interest rate, term or
number of years, and additional principal the borrower is
willing to pay per month.
You’ll use the formula of the monthly Payment as follows:
monthlyPayment = (loanAmount * annualInterest/12)/(1-
1/pow(1+annualInterest/12,numberOfYears*12))
Then, you can use the following formula to compute
Principal, Interest and Balance for the ith month.
Balance(0) = Loan Amount;
Actual Payment = Monthly Payment + Additional Principal
Interest(i) = Balance(i-1) * Annual Interest Rate/12;
Principal(i) = Actual Payment – Interest(i)
Balance(i) = Balance(i-1) – Principal(i)
When additional principal is greater than 0, it means that
the loan will be paid off earlier than the loan term. So,
your amortization table should end when the balance becomes
zero or negative. So, when the balance is less than the
actual payment, the next month’s principal is the same as
the previous month’s balance, and it is the end of the
amortization table.
Your table (program output file) needs to follow the exact
format as follows. Your program needs to accommodate a
loan amount up to $9,999,999.00. Your program needs to be
general enough to handle various user input errors, for
example, zero or negative numbers or numbers are too big.
The output in a file is for the following case:
2
 MORTGAGE AMORTIZATION TABLE
Amount: $600000.00
Interest Rate: 2.375%
Term(Years): 25
Monthly Payment: $2654.09
Additional Principal: $300.00
Actual Payment: $2954.09
 Principal Interest Balance
1 $ 1766.59 $ 1187.50 $ 598233.41
2 1770.08 1184.00 596463.33
3 1773.59 1180.50 594689.75
4 1777.10 1176.99 592912.65
5 1780.61 1173.47 591132.04
6 1784.14 1169.95 589347.90
 ………………………………………………
256 2924.83 29.25 11855.45
257 2930.62 23.46 8924.82
258 2936.42 17.66 5988.40
259 2942.23 11.85 3046.17
260 2948.06 6.03 98.11
261 98.11 0.19 0.00
24 hours before your assignment is due, I’ll post the test
case with all the parameter values for you to use to
produce the output for your program. Your will use a Word
file to include your program listing together with the
screenshot of your program execution, and name this file,
Assign2_yourLastName_yourFirstName.doc.
You will use Assign2_yourLastName_yourFirstName_output.txt
to store your program output file containing the
Amortization table.
You need to submit both files to the Blackboard.
Your assignment will be graded into 4 categories: A (100%),
B (75%), C (50%), D (25%). Any missing work or late
submission will get F (0 %). 
