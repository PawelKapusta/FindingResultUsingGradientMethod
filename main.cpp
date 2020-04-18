#include <iostream>
#include <math.h>

using namespace std;


double normFunction(double tab)
{   double total=0;
    for(int i=0; i<128; i++)
    {
        total+= tab * tab;
    }
    double norm=sqrt(total);
    return norm;
}

int main()
{
    double mainTab[128][128]={0};

    for(int i=0; i<128; i++)
    {
        for(int j=0; j<128; j++)
        {
            if(i==j) mainTab[i][j]={4};
            else if(j==i+1 || j==i+5 || i==j+1 || i==j+5) mainTab[i][j]={1};
        }
    }

    double rightVector[128];
    for(int i=0; i<128; i++)
    {
        rightVector[i]=1;
    }

    int firstIteration=0; 
    int maxNumberOfIterations=25;
    int sizeTab=128; 


    double temp1[128]={0};
    double temp2[128]={0};
    double solutions[128]={0};


    for(int i=0; i < sizeTab; i++)
        temp2[i] = temp1[i] = rightVector[i];

    while (firstIteration < maxNumberOfIterations)
    {
        double rtr = 0.0;
        double ptAp = 0.0;

        for(int i=0; i < sizeTab; i++)
            rtr += temp1[i] * temp1[i];

        for(int i=0; i < sizeTab; i++)
        {
            for(int j=0; j < sizeTab; j++)
                ptAp += mainTab[i][j] * temp2[i] * temp2[j];
        }


        double alpha = rtr / ptAp ;

        double temp3[128]={0};
        for(int i=0; i < sizeTab; i++)
        {
            solutions[i] += alpha * temp2[i];
            temp3[i] = temp1[i];
            for(int j=0; j < sizeTab; j++)
                temp3[i] -= alpha * mainTab[i][j] * temp2[j];
        }
        double rntrn = 0.0;

        for(int i=0; i < sizeTab; i++)
            rntrn += temp3[i] * temp3[i];


        double beta = rntrn / rtr;

        for(int i=0; i < sizeTab; i++)
        {
            temp2[i] = beta * temp2[i] + temp3[i];
            temp1[i] = temp3[i];
        }
        firstIteration++;
    }
    cout<<endl;

    cout << "Result: " << endl;
    for(int i=0;i<128;i++){
        cout << "x" <<i+1 << "=" << solutions[i] << endl;
    }
    cout<<endl;

    cout << "Norm: " << endl;

    for(int i=1;i<128; i++)
    {
        cout << i << ")" << normFunction(solutions[i] - solutions[i - 1]) << "\t";
    }


    return 0;
}