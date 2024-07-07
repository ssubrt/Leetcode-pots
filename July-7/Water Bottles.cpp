---------------->>>>>>>>>>>>>>> Approach-1 <<<<<<<<<<<<<<<<<<<<<<<<<---------------------
// Time Complexity - O(log(numsExchange))
// space Complexity  - O(1)

int numWaterBottles(int numBottles, int numExchange) {
    int totalDrank = 0;
    int emptyBottles = 0;

    while (numBottles > 0) {
        // Drink all the full bottles
        totalDrank += numBottles;
        emptyBottles += numBottles;
        numBottles = 0;

        // Exchange empty bottles for full bottles
        numBottles = emptyBottles / numExchange;
        emptyBottles = emptyBottles % numExchange;
    }

    return totalDrank;
}


----------------------------->>>>>>>>>>>>>>>>>>>>> Approach -2 <<<<<<<<<<<<<<<<<<<<<<<-----------------------------
// Time Complexity - O(log(numsExchange))
// space Complexity  - O(1)



int numWaterBottles(int numBottles, int numExchange) {
    int totalDrank = numBottles;
    int emptyBottles = numBottles;

    while (emptyBottles >= numExchange) {
        int newBottles = emptyBottles / numExchange;
        totalDrank += newBottles;
        emptyBottles = emptyBottles % numExchange + newBottles;
    }

    return totalDrank;
}