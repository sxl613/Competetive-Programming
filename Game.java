public class Game {
    public static void main(String[] args)
    {
        String currName = ""; int c = 0; String peg; int sw; int countersOff; boolean quitSentinel = false; int k;
        /* Initializations for the  variables.
        currName = name of the current player
        c = count of ALL rounds
        peg = the peg chosen by the player
        sw = a integer value obtained from peg - it can be either 0, 1, 2 or 16, representing A, B, C and q, respectively.
        countersOff = number of counters taken off a peg
        quitSentinel =  a boolean used to check whether one of the players quit the game

        All input from the user is handled by the Input class.
         */
        String[] names = Input.initializeNames();       // initialize the names for the players
        int[] stacks = Input.initializeStacks();           // initialize the values for the number of counters on the respective pegs
        int counters = stacks[0] + stacks[1] + stacks[2];   // counters is the count of all counters on all pegs. Since a player removes i >= 1 counters, it is also the maximum length of a game.
        int[][] pegs = new int[2][counters];        // int arrays for the history of the game for player A and player B
        String[][] rounds = new String[2][counters];        // string arrays for the history of the game for player A and player B

        for (int i=0; i < counters; i++)
        {
            pegs[0][i] = 0;                     // initialization of a double array - fill with zeros
            pegs[1][i] = 0;
        }
        for (int i=0; i < counters; i++)
        {
            rounds[0][i] = "";                  // initialization of a double array - fill with zeros
            rounds[1][i] = "";
        }
        while (counters > 0)                                    // means the game is still going
        {
            Input.printPegs(stacks[0], stacks[1], stacks[2]);
            currName = names[c%2]; // the current player
            do
            {
                peg = Input.getPeg(currName);                           // choose the peg with a non-zero number of counters
                sw = peg.charAt(0) - 'a';                        // sw --> (0, 1, 2 or 16)
                if (sw == 16)   break;
            }
            while (stacks[sw] < 1);
            if (sw == 16) { quitSentinel = true; break; } // if peg chosen == 'q' we break from the loop; quitSentinel = true as well
            countersOff = Input.getCounters(stacks[sw], peg);
            if (countersOff < 0){quitSentinel = true; break;}
            k = c % 2;
            rounds[k][c/2] = peg.toUpperCase();
            pegs[k][c/2] = countersOff;
            counters -= countersOff;
            stacks[sw] -= countersOff;
            c++;
        }
        // if quitSentinel == true it means one of the players quit from the game
        if (!quitSentinel)
        {
            /*
            This is the output part of the game - the winner is displayed and the loops iterate through the
            recorded rounds, displaying both pegs chosen and how many counters were taken off.
             */

            System.out.print("\n\n");
            System.out.format("%s has won the game - congratulations,  You picked up the last counter!\n", currName);
            System.out.println("##########################");
            System.out.format("Recorded history of player A - %s\n", names[0]);
            for (int i=0; i <= c/2; i++)
            {
                if (pegs[0][i] == 0) break;
                System.out.format("\t\ttakes off %d counter(s) off peg %s\n", pegs[0][i], rounds[0][i]);
            }

            System.out.format("Recorded history of player B - %s\n", names[1]);
            for (int i=0; i <= c/2; i++)
            {
                if (pegs[1][i] == 0) break;
                System.out.format("\t\ttakes off %d counter(s) off peg %s\n", pegs[1][i], rounds[1][i]);
            }
            System.out.println("Thank you for playing.");       // THE END
        }
    }

}
