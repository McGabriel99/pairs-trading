#ifndef PROCESSING_H
#define PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <cmath>

using std::vector;

// process vector to file
void vector_to_file(const vector<double> &dt, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        printf("Unable to create the file");
        exit(1);
    }

    for (auto i : dt)
    {
        fprintf(fp, "%f\n", i);
    }

    fclose(fp);
}
// Read csv file and return the adjusted closing price
vector<double> adj_ret(const char *filename)
{
    vector<double> adj_ret;
    // From Geeks for Geeks
    FILE *fp = fopen(filename, "r");

    if (!fp)
    {
        printf("Unable to open file\n");
        exit(1);
    }
    else
    {
        char buffer[1024];

        int row = 0;
        int column = 0;

        while (fgets(buffer, 1024, fp))
        {
            column = 0;
            row++;

            // skips 1st row, which are column names
            if (row == 1)
                continue;

            // Splitting the data
            char *value = strtok(buffer, ", ");

            while (value)
            {
                // Adjusted closing price is on 5th column
                if (column == 5)
                {
                    float num = atof(value);
                    adj_ret.push_back(num);
                }
                value = strtok(NULL, ", ");
                column++;
            }
        }
        fclose(fp);
    }
    return adj_ret;
}

// process log return
vector<double> log_ret(const vector<double> &dt)
{
    vector<double> log_ret_container;
    for (int i = 1; i < dt.size(); i++)
    {
        double log_ret = log(dt[i] / dt[i - 1]);
        log_ret_container.push_back(log_ret);
    }
    return log_ret_container;
}

#endif