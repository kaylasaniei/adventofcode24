#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    int numLines = 0;
    string line;
    int left[1000];
    int right[1000];
    int total = 0;
    // get input from a file
    ifstream read;
    read.open("puzzleinput.txt");
    if (!read) {
        cout<<"file isnt opening";
    }
    else {
        // read how many lines in the file
        // + read into 2 arrays
        while(read >> left[numLines] >>right[numLines]) {
            numLines++;
        }

        // sort arrays
        int temp = 0;
        for (int i = 0; i<numLines; i++)
        {
            for (int j = 0; j<numLines; j++)
                if (left[i] < left[j])
                {
                    temp = left[i];
                    left[i] = left[j];
                    left[j] = temp;
                }
        }

        int temps = 0;
        for (int i = 0; i<numLines; i++)
        {
            for (int j = 0; j<numLines; j++)
                if (right[i] < right[j])
                {
                    temps = right[i];
                    right[i] = right[j];
                    right[j] = temps;
                }
        }
        // for loop w/ # of lines, subtract from right array to left array,
        // get abs value, and add to a total
        for (int i = 0; i<numLines; i++)
        {
            total += abs(left[i] - right[i]);
        }
    }
    
    read.close();
    // part two

    int score = 0;
    int totalScore = 0;

    for (int i = 0; i<1000; i++)
    {
        int appears = 0;
        for (int j = 0; j<1000; j++)
        {
            if (left[i] == right[j]) {
                appears++;
            }
        }
        score = appears * left[i];
        totalScore += score;
    }
    cout<<totalScore<<endl;
    return 0;
} 
