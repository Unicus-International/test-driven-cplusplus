# Task the Second – Dietary energy converter

Dietary energy is generally measured in one of two units: kJ (kilojoules) or kcal (kilocalories). These two units are related by a factor of 4.184, with 1 kcal equal to 4.184 kJ.

The task for the second movement is to implement a member function in `energy` named `convert()`. `convert()` should return an object of type `energy`, with its value properly converted and its scale set appropriately.

## What do the errors I'm getting mean?

When dealing with computers, floating point numbers are treacherous. Comparing numbers directly doesn't work like you expect it to, so instead of comparing two floating point values, the difference between them is taken and compared to `ε` (epsilon), a tolerance value. This is necessary, as with floating point numbers not all numbers are exactly representable. This also makes floating point numbers unsuitable for certain applications, such as financial data.
