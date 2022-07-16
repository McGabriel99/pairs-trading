# ASSURE Summer Research Experience: Pairs Trading

Pairs Trading Strategy is a trading strategy that involves matching a long position with a short position in two stocks with a high correlation. This program will calculate if two stocks are correlated using the Pearson Correlation method.


Steps needed to take to compile and run the program:

1. Download historical data (csv file) of two stocks from Yahoo Finance. Make sure both stocks have the same: Time Period and Frequency.

2. Store both data in the same folder of the program.

3. Compile using:
```
g++ main.cpp -o main
```

4. Run the program using:
```
./main <stock_1>.csv <stock_2>.csv
```
