import java.util.*;



class Input {
    private static int max2(int a, int b)
    {
        if (a >= b)
        {
            return a;
        }
        else    return b;
    }
    private static int max3(int a, int b, int c)
    {
        if (a >= max2(b, c))  return a;
        else    return max2(b, c);
    }
    static String[] initializeNames()
    {
        /*
        Gets the names of the players from the user(s).
         */

        Scanner sc = new Scanner(System.in);
        String[] names = new String[2];
        System.out.print("Enter player 1 - ");
        names[0] = sc.nextLine();
        System.out.print("Enter player 2 - ");
        names[1] = sc.nextLine();
        return names;
    }

    static int[] initializeStacks()
    {
        int[] stacks = {0, 0, 0};

        /*
            Getting input for the first peg. The program will continue asking the user for the number of counters
            on the first peg until the integer provided is > 0. If the user does not input an integer at all, the
            program will not throw an error but instead ask again. sc.nextLine() is used to reset the input, otherwise
            the program will enter an infinite loop.

         */
        Scanner sc = new Scanner(System.in);
        do {
            System.out.print("Enter a positive integer for pile [A]: ");
            try{
                stacks[0] = sc.nextInt();
            }
            catch (RuntimeException InputMismatchException) {
                stacks[0] = -1;
                sc.nextLine();
            }

        }
        while (stacks[0] <= 0);

        /*
            Getting input for the second peg. The program will continue asking the user for the number of counters
            on the second peg until the integer provided is > 0. If the user does not input an integer at all, the
            program will not throw an error but instead ask again. sc.nextLine() is used to reset the input, otherwise
            the program will enter an infinite loop.

         */

        do {
            System.out.print("Enter a positive integer for pile [B]: ");
            try{
                stacks[1] = sc.nextInt();
            }
            catch (RuntimeException InputMismatchException) {
                stacks[1] = -1;
                sc.nextLine();
            }

        }
        while (stacks[1] <= 0);

        /*
            Getting input for the third peg. The program will continue asking the user for the number of counters
            on the third peg until the integer provided is > 0. If the user does not input an integer at all, the
            program will not throw an error but instead ask again. sc.nextLine() is used to reset the input, otherwise
            the program will enter an infinite loop.

         */

        do {
            System.out.print("Enter a positive integer for pile [C]: ");
            try{
                stacks[2] = sc.nextInt();
            }
            catch (RuntimeException InputMismatchException) {
                stacks[2] = -1;
                sc.nextLine();
            }

        }
        while (stacks[2] <= 0);
        return stacks;
    }

    static int getCounters(int n, String peg)
    {
        // Gets input from the user about how many counters they want to take off the peg.
        // Does not check for the case x < 0; this is checked by the class game.
        // n = number of counters on the peg
        // peg = name of the peg
        Scanner sc = new Scanner(System.in);
        peg = peg.toUpperCase();
        int x = -1; boolean check=false;
        do
        {
            System.out.format("How many do you want to remove from the peg %s: (or enter any negative number to exit)", peg);
            try{
                x = sc.nextInt();
                check = true;
            }
            catch (RuntimeException InputMismatchException) {
                sc.nextLine();
            }
            if (x > n || x == 0) { System.out.println("Wrong number of counters. The number should be a positive integer <= number of counters on the chosen pile."); check=false;}
        }
        while (!check);
        return x;
    }
    static String getPeg(String player)
    {
        /*
        Gets the name of the peg the user wishes to take counters off of.
        player = current player
         */
        Scanner sc = new Scanner(System.in);
        String peg = ""; boolean check;
        do {
            System.out.format("%s, choose a pile: (or enter 'q' to exit!) ", player);
            try{
                peg = sc.nextLine();
            }
            catch (RuntimeException InputMismatchException) {
                sc.nextLine();
            }
            peg = peg.toLowerCase();
            if (peg.equals("a") || peg.equals("b") || peg.equals("c") || peg.equals("q"))   check=true;
            else
            {
                check=false;
                System.out.println("Please, check your choice and try again! Remeber, the chosen pile must not be empty.");
            }
        }
        while (!check);
        return peg;
    }

    static void printPegs(int a, int b, int c)
    {
        /*
        Prints out each stack's counters in a 3-counter pyramid. Makes a (3 x h) array filled with spaces and then
        fills them respectively with either 3 stars (***), 2 stars (** ) or 1 star (*  ). Then iterates through it to
        print it on the screen. Takes in as input 3 numbers.
        a = num of counters on first peg
        b = num of counters on second peg
        c = = num of counters on third peg
         */

        int i; int j;
        int h = (max3(a, b, c) + 2) / 3;            // initializations, max is used so that all stacks can be fit on the screen nicely
        int[] l = {a, b, c};
        String[][] rect = new String[3][h];
        for (i=0; i < h; i++)                           // setting up the rect array
        {
            for (j=0; j < 3; j++)                       // fill with spaces
            {
                rect[j][i] = "   ";
            }
        }
        for (i=0; i < 3; i++)                               // for each peg
        {
            for (j=0; j < l[i]/3; j++)                      // first fill the first k lines with 3 stars for each l[i] = 3*k + r
            {
                rect[i][j] = "***";
            }
            switch (l[i]% 3)                                // then put in either 2 or 1 star, depending on r | l[i] = 3*k + r
            {
                case 1:
                    rect[i][l[i]/3] = "*  ";
                    break;
                case 2:
                    rect[i][l[i]/3] = "** ";
                    break;
            }
        }
        // Actual printing of the output
        for (i = h-1; i >= 0; i--)
        {
                System.out.format("\t%4s\t\t%4s\t\t%4s\n", rect[0][i], rect[1][i], rect[2][i]);
        }
        System.out.format("\t[A] : %d \t [B] : %d \t [C] : %d\n", a, b, c);
    }
}
