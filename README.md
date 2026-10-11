# Airport Baggage & Customs Duty System

A C program designed to automate airport check-in calculations, including tiered baggage weight fees, frequent flyer status discounts, customs duty taxes, and time-based late check-in surcharges.

## Features
- **Baggage Fee Calculation:** Tiered weight pricing for Economy, Business, and First Class with cumulative overages and max weight limits.
- **Frequent Flyer Discounts:** Tiered status discounts (Gold: 20%, Silver: 10%, None: 0%).
- **Customs Duty Tax:** Variable tax tiers on imported goods values ($0-$800 free, 4% up to $2k, 7% up to $5k, 12% over $5k + luxury fees).
- **Check-in Time Surcharges:** Military time difference conversion to apply express check-in fees or deny boarding (< 30 mins).
- **Itemized Receipt Generator:** Clean, formatted output displaying all calculated sub-costs and grand total.

## How to Compile & Run
```bash
gcc main.c -o airport_system
./airport_system
