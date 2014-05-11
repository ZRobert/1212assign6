/*/////////////////////////////////////////////
//Program: arraysums.cpp
//Author: Robert Payne
//Date: 05-01-2012
//Purpose: Array Sums allows the
//         user to input numbers unique numbers
//        from 1 to 25 into a 5x5 matrix
//        and the program checks to see if the sum
//        of the diagonals, rows, and columns are
//        all equal. Outputs if the user entered
//        data that passes the sum checks or not.
/////////////////////////////////////////////*/
#include <iostream>

using namespace std;

int main()
{
    int arraySums[5][5];    //the 5x5 array that holds the user's input
    //and is checked to see if all the columns,
    //rows, and diagonals have the same sum
    int userInput;          //the user's input to go into the array
    bool valueUsed[25]= {0}; //used to validate if the user input is unique
    int row;                //row iterator; used for valueUsed also
    int column;             //column iterator
    int sumPrime;           //first sum check is stored here
    int sum;                //all other sum checks pass through here
    bool sumsMatch;         //tracks that all checks pass
    char repeat;            //user input to repeat the program

    do
    {
        //initializes the 5x5 array to 0s
        for(row = 0; row < 5; row++)
            for(column = 0; column < 5; column++)
                arraySums[row][column] = 0;

        //initializes the 1-25 array of bools to false
        for(row = 0; row < 25; row++)
            valueUsed[row]=false;

        //initializes sumsMatch, sum, and sumPrime
        sumsMatch = false;
        sum = 0;
        sumPrime = 0;

        //nested for loops that include a do while for data validation as
        //the user fills the array with unique integers from 1-25
        for(row = 0; row < 5; row++)
        {
            for(column = 0; column < 5; column++)
            {
                do
                {

                    cout<<"Enter a unique number (1-25) for row "<<row+1 <<" and column "<<column+1<<":";
                    cin>>userInput;

                }
                while(valueUsed[userInput-1] || userInput > 25 || userInput < 1);

                arraySums[row][column] = userInput;
                valueUsed[userInput-1]=true;
            }
        }

        //Output the array
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
        for(row = 0; row<5; row++)
        {
            cout<<"_________________________________________\n|";
            for(column = 0; column<5; column++)
                cout<<arraySums[row][column]<<"\t|";
            cout<<endl;
        }
        cout<<"_________________________________________\n";

        //prompts the user to press enter... gives user interaction feel
        cout<<"\nNow checking to see if the sums are the same... press enter to continue...";
        cin.get();
        cin.get();

        //start with column 0; sets up sumPrime to be used
        //for all of the following checks
        for(row = 0; row < 5; row++)
            sumPrime += arraySums[row][0];
        //check sum column 1
        for(row = 0; row < 5; row++)
            sum += arraySums[row][1];

        //if the first two checks on column 1 and 0 match,
        //program performs the remaining checks
        if(sum == sumPrime)
        {
            //sumsMatch tracks if all the checks pass
            //if it misses any checks it will change
            //to false
            sumsMatch = true;
            sum = 0;
            //check sum column 2
            for(row = 0; row < 5; row++)
                sum+= arraySums[row][2];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check sum column 3
            for(row = 0; row < 5; row++)
                sum+= arraySums[row][3];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check sum column 4
            for(row = 0; row < 5; row++)
                sum+= arraySums[row][4];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check row 0
            for(column = 0; column < 5; column++)
                sum+= arraySums[0][column];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check row 1
            for(column = 0; column < 5; column++)
                sum+= arraySums[1][column];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check row 2
            for(column = 0; column < 5; column++)
                sum+= arraySums[2][column];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check row 3
            for(column = 0; column < 5; column++)
                sum+= arraySums[3][column];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check row 4
            for(column = 0; column < 5; column++)
                sum+= arraySums[4][column];

            if(sum != sumPrime)
                sumsMatch = false;

            sum= 0;
            //check diagonal 1
            for(row = 0; row < 5; row++)
                sum += arraySums[row][row];

            if(sum != sumPrime)
                sumsMatch = false;

            sum = 0;
            //check diagonal 2
            for(row = 0; row < 5; row++)
                sum += arraySums[4-row][row];
        }

        //tells the user if their values pass the
        //sum checks
        if(sumsMatch == true)
            cout<<"\nSums match up :)";
        else
            cout<<"\nSums do not match up :(";

        //asks the user if they want to try again
        cout<<"\nTry Again?(y/n): ";
        cin>>repeat;

    }
    while(repeat == 'y'||repeat == 'Y');

    return 0;
}
