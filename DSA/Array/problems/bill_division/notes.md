# Bill Division Problem

## Problem Description
Two friends Anna and Brian, are deciding how to split the bill at a dinner. Each will only pay for the items they consume. Brian gets the check and calculates Anna's portion. You must determine if his calculation is correct.
 
## Solution Approach
This problem calculates the correct share for Anna by summing up all items except the one she didn't eat (at index k), then dividing by 2. It compares this with what Brian calculated (b) and either confirms "Bon Appetit" or outputs the difference.

## Implementation Details
- Sums all items except the one at index k
- Calculates Anna's correct share by dividing the sum by 2
- Compares with Brian's calculation and outputs the appropriate response

## Known Issues
None - solution appears correct.